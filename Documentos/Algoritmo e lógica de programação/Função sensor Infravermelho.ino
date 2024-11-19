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
