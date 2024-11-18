#define BLYNK_TEMPLATE_ID "TMPL2WnHJ55AR" // Template criado para o projeto
#define BLYNK_TEMPLATE_NAME "BEA" // Nome do template
#define BLYNK_AUTH_TOKEN "q3gIDy126exES2zY9lXYzxBFtmhvBdPI"
#define BLYNK_PRINT Serial // Impressão serial do Blynk

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <HX711.h>

char auth[] = BLYNK_AUTH_TOKEN; // Token de autenticação
char ssid[] = "Nome da rede"; // Nome da rede Wi-Fi
char pass[] = "Senha da rede"; // Senha da rede Wi-Fi

BLYNK_CONNECTED() {
  Blynk.syncVirtual(V1); // Conectando o pino virtual 1
}

// Sensores
float ultimaLeitura = 0;
float tensaoMinima = 0.3; // Define o valor mínimo aceitável para o sensor funcionar
int sensorInfra = A0; // Pino onde o sensor IR está conectado
int ultimoEstado = HIGH; // Último estado do sensor (inicializado como não detectando)
unsigned long tempoDeteccao = 0;

// Pinos utilizados para controlar a velocidade de rotação
const int PINO_ENA = 17; 
const int PINO_ENB = 27;

// Pinos utilizados para controlar o sentido do motor
const int PINO_IN1 = 2; 
const int PINO_IN2 = 4;
const int PINO_IN3 = 13;
const int PINO_IN4 = 12;

const int TEMPO_ESPERA = 100; // Intervalo de 100 ms entre os sentidos de rotação do motor
const int TEMPO_RAMPA = 120; // Intervalo de 120 ms para as rampas de aceleração e desaceleração

#define DEBUG_HX711
#define CALIBRACAO 10000.0

byte pinData = 15; // Pino sensor de peso DT
byte pinClk = 14; // Pino sensor de peso SCK

int leituraConsecutivas = 0;

const int led = 8;
const int threshold = 100;

HX711 scale;

void setup() {
  Serial.begin(115200); // Começa a comunicação da ESP com a plataforma do Blynk
  Blynk.begin(auth, ssid, pass); // Valida os dados passados da rede

  // Configuração dos pinos como saída
  pinMode(PINO_ENA, OUTPUT); 
  pinMode(PINO_ENB, OUTPUT);
  pinMode(PINO_IN1, OUTPUT);
  pinMode(PINO_IN2, OUTPUT);
  pinMode(PINO_IN3, OUTPUT);
  pinMode(PINO_IN4, OUTPUT);
  pinMode(led, OUTPUT);
  
  // Inicia o código com os motores parados
  pararMotores();

  #ifdef DEBUG_HX711
  Serial.begin(115200); // Inicia a comunicação serial para depuração
  #endif

  scale.begin(pinData, pinClk); 

  if(!scale.is_ready()) {
    while(1); // Espera até que o sensor esteja pronto
  } else {
    Serial.println("Sensor de peso inicializado com sucesso.");
    Blynk.notify("Sensor de peso inicializado com sucesso.");
  }

  scale.set_scale(CALIBRACAO); // Ajusta a escala
  scale.tare(); // Zera a balança
}

// Função para parar os motores
void pararMotores() {
  digitalWrite(PINO_IN1, LOW); 
  digitalWrite(PINO_IN 2, LOW);
  digitalWrite(PINO_IN3, LOW);
  digitalWrite(PINO_IN4, LOW);
  digitalWrite(PINO_ENA, LOW);
  digitalWrite(PINO_ENB, LOW);
}

// VERIFICAÇÃO DO SENSOR DE PESO
void verificarSensorPeso(float min, float max, int maxConstantes) {
  if(scale.is_ready()) {
    float peso = scale.get_units(); // Obtém a leitura do sensor

    if(peso < min || peso > max) {
      Serial.println("Alerta, fora do limite");
      Blynk.notify("Alerta, fora do limite");
    } else {
      Serial.println("Peso: " + String(peso)); // Correção na impressão do peso
      Blynk.notify("Peso: " + String(peso));
    }

    if (abs(peso - ultimaLeitura) < 0.01) {
      leituraConsecutivas++; // Incrementa +1 caso seja detectado uma repetição na leitura do peso 

      if (leituraConsecutivas >= maxConstantes) {
        Serial.println("Alerta: peso repetindo várias vezes");
        Blynk.notify("Alerta: peso repetindo várias vezes");
      }
    } else {
      leituraConsecutivas = 0; // Reseta se houver variação
    }

    ultimaLeitura = peso; // Atualiza a última leitura
  } else {
    Serial.println("Sensor não inicializado");
    Blynk.notify("Sensor não inicializado");
  }
}

// VERIFICAÇÃO DO SENSOR INFRAVERMELHO
void verificarSensorInfraV() {
  int estadoSensor = analogRead(sensorInfra); // Lê a entrada analógica do sensor
  float tensaoInfraV = (estadoSensor / 1023.0) * 5.0; // Converte para tensão

  unsigned long tempo = millis(); // Tempo atual em milissegundos

  if(tensaoInfraV < tensaoMinima) {
    Serial.println("Alerta: tensão baixa");
    Blynk.notify("Alerta: tensão baixa");
  } else {
    Serial.print("Tensão de alimentação: ");
    Serial.println(tensaoInfraV); // Exibe a tensão medida
    Blynk.notify("Tensão de alimentação: " + String(tensaoInfraV));
  }

  if (estadoSensor < threshold && ultimoEstado >= threshold) {  
    if (tempo - tempoDeteccao > 100) {
      Serial.println("Objeto detectado!");
      Blynk.notify("Objeto detectado!");
      tempoDeteccao = tempo;  // Atualiza o tempo da última detecção
    }
  } 

  if (tempo - tempoDeteccao > 180000) { // Ajusta o tempo de intervalo em 3 minutos 
    Serial.println("Alerta: Nenhum objeto detectado por muito tempo");
    Blynk.notify("Alerta: Nenhum objeto detectado por muito tempo");   
  }

  ultimoEstado = estadoSensor; // Atualiza o último estado para comparação futura
}

void loop() {
  Blynk.run();

  // Configura os motores para o sentido horário
  digitalWrite(PINO_IN1, LOW); 
  digitalWrite(PINO_IN2, HIGH);
  digitalWrite(PINO_IN3, LOW);
  digitalWrite(PINO_IN4, HIGH);

  // Rampa de aceleração
  for (int i = 0; i < 128; i += 10) { 
    ledcWrite(PINO_ENA, i);
    ledcWrite(PINO_ENB, i);
    delay(TEMPO_RAMPA);
  }

  // Rampa de desaceleração
  for (int i = 128; i >= 0; i -= 10) { 
    ledcWrite(PINO_ENA, i);
    ledcWrite(PINO_ENB, i);
    delay(TEMPO_RAMPA);
  }

  delay(TEMPO_ESPERA);

  // Configura os motores para o sentido anti-horário
  digitalWrite(PINO_IN1, HIGH); 
  digitalWrite(PINO_IN2, LOW);
  digitalWrite(PINO_IN3, HIGH);
  digitalWrite(PINO_IN4, LOW);

  // Rampa de aceleração
  for (int i = 0; i < 128; i += 10) { 
    ledcWrite(PINO_ENA, i);
    ledcWrite(PINO_ENB, i);
    delay(TEMPO_RAMPA);
  }

  // Rampa de desaceleração
  for (int i = 128; i >= 0; i -= 10) { 
    ledcWrite(PINO_ENA, i); 
    ledc Write(PINO_ENB, i);
    delay(TEMPO_RAMPA);
  }

  delay(TEMPO_ESPERA);

  int sensorI = analogRead(sensorInfra);

  if(sensorI < threshold) {
    digitalWrite(led, HIGH);
    Serial.println("Lixo Caindo");
  } else {
    digitalWrite(led, LOW);
  }

  // Chama a função de verificação do sensor de peso
  verificarSensorPeso(0.0, 5000, 10);
  delay(100);

  // Chama a verificação do sensor infravermelho
  verificarSensorInfraV();
  delay(100);

  #ifdef DEBUG_HX711
  Serial.print("[HX7] peso: ");
  Serial.print(scale.get_units(), 1);
  Serial.print(" KG");
  Serial.println();
  Blynk.virtualWrite(V1, scale.get_units());
  #endif
}