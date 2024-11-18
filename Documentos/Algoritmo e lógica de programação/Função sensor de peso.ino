// VERIFIÇÃO DO SENSOR DE PESO
void verificarSensorPeso(float min, float max, int maxConstantes){

// verifica se o sensor está inicializado
  if(scale.is_ready()){
    float peso = scale.get_units(); // obtem a leitura do sensor
  
    // verifica se o peso está dentro do ideal
    if(peso < min || peso > max){
      Serial.println("Alerta, fora do limite");
    }else{
      Serial.println("peso"+peso); //correção na impressão do peso
      Blynk.virtualWrite(V1, peso); //Envia os dados para o Blynk
    }

    // verifica se a leitura é constante
    if (abs(peso - ultimaLeitura) < 0.01) {
            leituraConsecutivas++; // incrementa +1 caso seja detectado uma repetição na leitura do peso 

            // verifica se o número de leitura consecutivas está passando do maximo permitido
            if (leituraConsecutivas >= maxConstantes) {
                Serial.println("Alerta: peso repetindo várias vezes");
            }
        } else {
            leituraConsecutivas = 0; // Reseta se houver variação
        }

    ultimaLeitura = peso; // atualiza a última leitura
  }else{
    Serial.println("Sensor não inicializado");
  }
}
