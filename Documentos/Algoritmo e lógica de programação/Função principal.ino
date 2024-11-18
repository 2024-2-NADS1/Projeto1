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
#endif
  
}
