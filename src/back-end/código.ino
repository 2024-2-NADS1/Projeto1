#define BLYNK_TEMPLATE_ID "TMPL2WnHJ55AR" //template criado para o projeto
#define BLYNK_TEMPLATE_NAME "BEA" //nome do template
#define BLYNK_AUTH_TOKEN "q3gIDy126exES2zY9lXYzxBFtmhvBdPI"
#define BLYNK_PRINT Serial // Print serial do Blynk
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
int sensorPino1 = 23;
int sensorPino2 = 24;
int sensorPinoAnalogico = A0; // Nome alterado para maior clareza
float tensao = 4.0; // Define o valor mínimo aceitável para o sensor funcionar

int sensorInfra = T2; // Pino onde o sensor IR está conectado
int ultEstado = HIGH; // Último estado do sensor (inicializado como não detectando)
unsigned long tempoDeteccao = 0;

//declaracao dos pinos utilizados para controlar a velocidade de rotacao
const int PINO_ENA = 17; 
const int PINO_ENB = 27;

//declaracao dos pinos utilizados para controlar o sentido do motor
const int PINO_IN1 = 2; 
const int PINO_IN2 = 4;
const int PINO_IN3 = 13;
const int PINO_IN4 = 12;

int i = 0; //declaracao da variavel para as rampas

const int TEMPO_ESPERA = 100;//declaracao do intervalo de 1 segundo entre os sentidos de rotacao do motor

const int TEMPO_RAMPA = 120;//declaracao do intervalo de 30 ms para as rampas de aceleracao e desaceleraca

#define DEBUG_HX711
#define calibracao 10000.0

byte pinData = 15; // pino sensor de peso DT
byte pinClk = 14; // pino sensor de peso SCK

int sensorInfra = A0;  // Pino onde o sensor IR está conectado

float ultimaLeitura = 0; // variavel que guarda a última leitura do sensor de peso
float tensao = 0.3; // define o valor minimo aceitavel para o sensor funcionar corretamente
int ultimoEstado = HIGH;  // Último estado do sensor (inicializado como não detectando)
unsigned long tempoDeteccao = 0; 
int leituraConsecutivas = 0;

const int led = 8;
const int threshold = 100;
int sensorI;

HX711 scale;


void setup() {

  Serial.begin(115200); // Comeca a comunicacao da esp com a plataforma do blynk
  Blynk.begin(auth, ssid, pass); //valida os dados passados da rede

  //configuração dos pinos como saida
  pinMode(PINO_ENA, OUTPUT); 
  pinMode(PINO_ENB, OUTPUT);
  pinMode(PINO_IN1, OUTPUT);
  pinMode(PINO_IN2, OUTPUT);
  pinMode(PINO_IN3, OUTPUT);
  pinMode(PINO_IN4, OUTPUT);

  //inicia o codigo com os motores parados
  digitalWrite(PINO_IN1, LOW); 
  digitalWrite(PINO_IN2, LOW);
  digitalWrite(PINO_IN3, LOW);
  digitalWrite(PINO_IN4, LOW);
  digitalWrite(PINO_ENA, LOW);
  digitalWrite(PINO_ENB, LOW);

   #ifdef DEBUG_HX711

  Serial.begin(115200); // Inicia a comunicação serial para depuração
  #endif

  scale.begin(pinData, pinClk); 
  pinMode(sensorInfra, INPUT);
  pinMode(led, OUTPUT);

  if(!scale.is_ready()){
    while(1);
  }else {
    Serial.println("Sensor de peso inicializado com sucesso.");
    Blynk.notify("Sensor de peso inicializado com sucesso.");
  }

  scale.set_scale(calibracao); // ajusta a escala. Converte em unidades de medidas reais
  scale.tare(); // zera a balança
}

// VERIFIÇÃO DO SENSOR DE PESO
void verificarSensorPeso(float min, float max, int maxConstantes){

// verifica se o sensor está inicializado
  if(scale.is_ready()){
    float peso = scale.get_units(); // obtem a leitura do sensor
  
    // verifica se o peso está dentro do ideal
    if(peso < min || peso > max){
      Serial.println("Alerta, fora do limite");
      Blynk.notify("Alerta, fora do limite"); //envia um alerta para o Blynk
    }else{
      Serial.println("peso"+peso); //correção na impressão do peso
      Blynk.notify("peso"+peso);
    }

    // verifica se a leitura é constante
    if (abs(peso - ultimaLeitura) < 0.01) {
            leituraConsecutivas++; // incrementa +1 caso seja detectado uma repetição na leitura do peso 

            // verifica se o número de leitura consecutivas está passando do maximo permitido
            if (leituraConsecutivas >= maxConstantes) {
                Serial.println("Alerta: peso repetindo várias vezes");
                Blynk.notify("Alerta: peso repetindo várias vezes");
            }
        } else {
            leituraConsecutivas = 0; // Reseta se houver variação
        }

    ultimaLeitura = peso; // atualiza a última leitura
  }else{
    Serial.println("Sensor não inicializado");
    Blynk.notify("Sensor não inicializado");
  }
}

// VERIFICAÇÃO DO SENSOR INFRAVERMELHO
void verificarSensorInfraV() {
  int estadoSensor = analogRead(sensorInfra); // lê a entrada analógica do sensor. 
  // O valor pode variar de 0 a 1023.
  // 0 representa 0 volts e 1023 representa a tensão máxima 5 volts
   float tensaoInfraV = (estadoSensor / 1023.0) * 5.0; // Converte para tensão

  int limiar = 500; // Defina um valor de limiar apropriado
  unsigned long tempo = millis(); // tempo atual em milissegundos

// Verifica se a tensão do sensor é menor que o valor minimo aceitavel
   if(tensaoInfraV < tensao){
      Serial.println("Alerta : tensão baixa");
      Blynk.notify("Alerta : tensão baixa"); //envia um alerta para o Blynk
    }else{
      Serial.print("Tensão de alimentação: ");
      Blynk.notify("Tensão de alimentação: ");
        Serial.println(tensaoInfraV); // Exibe a tensão medida
        Blynk.notify(tensaoInfraV
    }

  // Identificar o momento em que um objeto foi detectado pelo sensor
  if (estadoSensor < limiar && ultimoEstado >= limiar) {  
    // Verifica se houve uma detecção recente (para evitar falsas leituras)
    if (tempo - tempoDeteccao > 100) {
      Serial.println("Objeto detectado!");
      Blynk.notify("Objeto detectado!"); //envia um alerta para o Blynk
      tempoDeteccao = tempo;  // Atualiza o tempo da última detecção
    }
  } 

  // Verifica se o sensor está a muito tempo sem detectar um objeto
  if (tempo - tempoDeteccao > 180000) { // Ajusta o tempo de intervalo em 3 minutos 
    Serial.println("Alerta: Nenhum objeto detectado por muito tempo");
    Blynk.notify("Alerta: Nenhum objeto detectado por muito tempo");   
  }

  // Atualiza o último estado para comparação futura
  ultimoEstado = estadoSensor;
}

void loop() {
  Blynk.run();

  //configura os motores para o sentido horario
  digitalWrite(PINO_IN1, LOW); 
  digitalWrite(PINO_IN2, HIGH);
  digitalWrite(PINO_IN3, LOW);
  digitalWrite(PINO_IN4, HIGH);

  //rampa de aceleracao
  for (i = 0; i < 128; i=i+10){ 
    analogWrite(PINO_ENA, i);
    analogWrite(PINO_ENB, i);
    delay(TEMPO_RAMPA); //intervalo para incrementar a variavel i
  }

  //rampa de desaceleracao
  for (i = 128; i >= 0; i=i-10){ 
    analogWrite(PINO_ENA, i);
    analogWrite(PINO_ENB, i);
    delay(TEMPO_RAMPA); //intervalo para incrementar a variavel i
  }

  delay(TEMPO_ESPERA); //intervalo de um segundo

  //configura os motores para o sentido anti-horario
  digitalWrite(PINO_IN1, HIGH); 
  digitalWrite(PINO_IN2, LOW);
  digitalWrite(PINO_IN3, HIGH);
  digitalWrite(PINO_IN4, LOW);

  //rampa de aceleracao
  for (i = 0; i < 128; i=i+10){ 
    analogWrite(PINO_ENA, i);
    analogWrite(PINO_ENB, i);
    delay(TEMPO_RAMPA); //intervalo para incrementar a variavel i
  }

//rampa de desaceleracao
  for (i = 128; i >= 0; i=i-10){ 
    analogWrite(PINO_ENA, i); 
    analogWrite(PINO_ENB, i);
    delay(TEMPO_RAMPA); //intervalo para incrementar a variavel i
  }

  delay(TEMPO_ESPERA); //intervalo de um segundo


  sensorI = analogRead(sensorInfra);

  if(sensorI < threshold){
    digitalWrite(led, HIGH);
    Serial.println("Lixo Caindo");
  }else{
    diigitalWrite(led, LOW);
  }

// chama a função de verificação do sensor de peso
verificarSensorPeso(0.0, 5000, 10);
  delay(100);

// chama a verificação do sensor infra vermelho
  verificarSensorInfraV();
  delay(100);

#ifdef DEBUG_HX711
Serial.print("[HX7] peso: ");
Serial.print(scale.get_units(), 1);
Serial.print("KG");
Serial.println();
Blynk.virtualWrite(V1, scale.get_units());
#endif
  
}

