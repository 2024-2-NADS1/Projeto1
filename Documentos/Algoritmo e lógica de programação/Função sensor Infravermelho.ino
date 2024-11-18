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
    }else{
      Serial.print("Tensão de alimentação: ");
        Serial.println(tensaoInfraV); // Exibe a tensão medida
    }

  // Identificar o momento em que um objeto foi detectado pelo sensor
  if (estadoSensor < limiar && ultimoEstado >= limiar) {  
    // Verifica se houve uma detecção recente (para evitar falsas leituras)
    if (tempo - tempoDeteccao > 100) {
      Serial.println("Objeto detectado!");
      Blynk.virtualWrite(V2, "Objeto detectado"); //Envia os dados para o Blynk
      tempoDeteccao = tempo;  // Atualiza o tempo da última detecção
    }
  } 

  // Verifica se o sensor está a muito tempo sem detectar um objeto
  if (tempo - tempoDeteccao > 180000) { // Ajusta o tempo de intervalo em 3 minutos 
    Serial.println("Alerta: Nenhum objeto detectado por muito tempo");
    Blynk.virtualWrite(V3, "Nenhum objeto detectado");
  }

  // Atualiza o último estado para comparação futura
  ultimoEstado = estadoSensor;
}
