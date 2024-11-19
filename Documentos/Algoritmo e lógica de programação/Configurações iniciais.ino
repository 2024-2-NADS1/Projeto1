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
