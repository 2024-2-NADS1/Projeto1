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
  }

  scale.set_scale(calibracao); // ajusta a escala. Converte em unidades de medidas reais
  scale.tare(); // zera a balança
}
