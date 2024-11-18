 # SENSOR DE PESO

Resultados esperados (mensagens que deveriam ser enviadas): [1, 0, 1, 1, 0, 1, 0, 0]</br>
Resultados reais (mensagens realmente enviadas): [1, 0, 1, 0, 0, 1, 1, 0]</br>
Vamos contar os acertos (onde os valores coincidem):</br>
Movimentos: 1, 0, 1, 1, 1 = 5 movimentos</br>
Observações totais = 8</br>
Precisão = Número de resultados / Número total de observações = 5/8 = 0,625 (ou 62,5%)</br>
Portanto, a precisão do sensor é de 62,5%.</br>

# SENSOR DE PESO // SENSOR LASER


Resultados esperados (Mensagens que deveriam ser enviadas):</br>

Sensor A: [1, 0, 1, 1, 0, 1, 0, 0]</br>

Sensor B: [0, 1, 1, 0, 0, 1, 1, 0]</br>

Resultados reais (Mensagens realmente enviadas):</br>

Sensor A: [1, 0, 1, 0, 0, 1, 1, 0]</br>

Sensor B: [0, 1, 0, 0, 1, 1, 0, 1]</br>

Sensor A: [1, 0, 1, 1, 0, 1, 0, 0] == [1, 0, 1, 0, 0, 1, 1, 0] =; 5 acertos</br>
Sensor B: [0, 1, 1, 0, 0, 1, 1, 0] == [0, 1, 0, 0, 1, 1, 0, 1] =; 4 acertos</br>
Observações totais = 8</br>
Precisão Combinada = Número de Resultados / Número Total de Observações = (5+4) / (8+8) = 9/16 = 0,5625 (ou 56,25%)</br>
Portanto, a precisão combinada dos sensores é de 56,25%.</br>
