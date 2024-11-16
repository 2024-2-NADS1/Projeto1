# Sensores Utilizados

Para o desenvolvimento do projeto, realizamos pesquisas e estudamos a melhor forma de desenvolver um sistema que atendesse às necessidades propostas. Decidimos utilizar alguns sensores, sendo eles:

# Célula de carga / Sensor de peso

   É um sensor usado para medir força ou peso. Quando uma força é aplicada à célula de carga, ela se deforma ligeiramente, e essa deformação resulta em uma mudança na resistência elétrica dos fios de metal. Com base na mudança na resistência medida, o circuito eletrônico converte essa informação em um valor de peso. O valor de peso calculado é então enviado para um sistema de controle. Ele será aplicado na caçamba, onde o lixo recolhido pela rede será despejado, e um aviso será enviado para a retirada do lixo, dependendo do peso aplicado. 

<p align="center">
<img src="https://github.com/user-attachments/assets/7e67f5ce-ac39-4881-afe5-2ab12b89faa3" width="300px" border="0" >
  <p align="center">
  <a> Fonte: usinainfo.com.br  <a>
</p>
<br><br>

   É necessário, também, a utilização do módulo conversor HX711 para fazer a adaptação do sinal emitido pela célula de carga, visto que o mesmo tem o propósito de converter o sinal analógico em digital, além de amplificar seu valor de saída para que seja reconhecido pelo microcontrolador. Ele foi criado com a intenção de atuar com sensores de peso ligados à ponte.

<p align="center">
<img src="https://github.com/user-attachments/assets/2baad6a7-3a0f-4a7e-bc66-c0229d2a1c27" width="300px" border="0" >
  <p align="center">
  <a> Fonte: curtocircuitoprodutoseletronicos <a>
</p>
<br><br>

# Módulo receptor de Laser

   É um sensor que tem como finalidade receber um feixe de luz produzido por um laser e alterar o estado de sua saída de acordo com a presença ou ausência do feixe apontado para o receptor. Quando o sensor detecta a interrupção do feixe, ele pode acionar um alerta. Esse alerta pode ser visual (como um LED) ou sonoro (como um buzzer) e serve para informar sobre a irregularidade ou evento detectado. Ele será aplicado na caçamba em determinada altura, no momento em que o lixo atingir determinada altura o sensor enviará um alerta para o celular do responsável pela retirada do lixo, assim não permitindo que o lixo da caçamba transborde.

<p align="center">
<img src="https://github.com/user-attachments/assets/f9d6fbf9-b2ed-40ac-a323-3f577ee55211" width="300px" border="0" >
  <p align="center">
  <a> Fonte: mercado livre <a>
</p>
<br><br>
