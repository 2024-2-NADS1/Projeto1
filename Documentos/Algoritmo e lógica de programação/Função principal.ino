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
