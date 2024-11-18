# Tipos de protocolos
  
Nós escolhemos utilizar o padrão do Blynk, que utiliza um protocolo proprietário, que faz com que o dispositivo cliente se conecte ao servidor Blynk usando **TCP/IP**, onde as mensagens são enviadas em formato binário, o que torna a comunicação mais eficiente em comparação ao formato de texto. O usuário também pode enviar comandos ou solicitar dados por esse método. Porém pretendemos modificar o protocolo proprietário, e utilizar o protocolo LoRaWan pelo fato de que é possivel se comunicar em longas distâncias e diminuir o consumo de energia, sem contar que o LoRaWan acaba facilitando a comunicação com outros dispositivos e outras plataformas também.

# Justificativa

### Processos
Acabamos optando o protocolo proprietário pelo fato de que a forma de comunicação acaba sendo mais simplificada, ou seja, não possui muitas etapas para a conexão. 

### Comunicação
A comunicação por mensagens binárias também reduz a sobrecarga de dados, tornando a comunicação entre proprietário e cliente, mais rápida e mais leve, o que é essencial para o projeto, já que estamos usando uma esp32 que não possui um espaço de armazenamento tão amplo. 

### Flexibilidade
Outro motivo para escolhermos o protocolo padrão do Blynk, foi a flexibilidade do protocolo, que permite a implementação de novos comandos e funcionalidades conforme avançamos com o projeto.

