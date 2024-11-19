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
