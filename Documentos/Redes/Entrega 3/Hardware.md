# Hardware

A plataforma que implementamos para o nosso hardware, é o Blynk, que é basicamente uma plataforma para a comunicação das placas esp ou arduino, para uma plataforma web, onde podemos personalizar o dashboard com o os dados que queremos utilizar, e configurar alertas mensais, como a seguinte foto:
![image](https://github.com/user-attachments/assets/6f93e457-7c96-48a1-9da6-d6eeb574e13e)

O nosso dashboard ficou mais simples por conta de que o unico dado que o cliente terá acesso, são os pesos das caçambas de lixo, o restante será notificado pela plataforma Web ou pelo aplicativo móvel do Blynk.

Os alertas serão enviados via E-mail ou Sms, devido a configuração do Blynk que utilizamos e por conta dos códigos implementados:
```cpp
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
```
Dessa forma ele alertará tanto no monitor serial quanto nas plataformas do Blynk IoT.
