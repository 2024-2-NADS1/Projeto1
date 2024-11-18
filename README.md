# FECAP - Fundação de Comércio Álvares Penteado

<div align="center">
<a href= "https://www.fecap.br/"><img src="https://github.com/user-attachments/assets/1005b6fc-f774-427a-b0df-debb63502053" width="300px" />
</div>

# Projeto Relacionado às ODS's para limpeza de rios.
  
## 🌱 Barreira Ecológica Automática (B.E.A.) 
# Integrantes:
### - <a href="https://www.linkedin.com/in/ana-c-de-souza-2b640922a/">Ana Clara De Souza Da Silva
### - Fabricio Yukio Yamashiro
### - Larissa De Almeida Lira Oliveira
### - <a href="https://www.linkedin.com/in/marcos-nascimento-985775317/">Marcos Paulo Fernandes Do Nascimento
### - <a href="https://www.linkedin.com/in/vinicius-cardoso-de-lima-a9a918227/">Vinicius Cardoso De Lima
## Professores Orientadores:
### - <a href="https://www.linkedin.com/in/victorbarq/">Victor Bruno Alexander Rosetti de Quiroz

# Descrição:

Rios que transpassam pelas cidades, infelizmente tendem a ser vítimas do descarte incorreto de resíduos, que por consequência poluem suas águas. Diante deste problema surgem diversas complicações, como enchentes, prejuízo com a vida local, e atinge diretamente as mesmas pessoas que causaram esta situação.

Em 2019, após fortes chuvas, uma cidade do interior de São Paulo foi invadida por mais de 17 toneladas de lixo após o rio Tietê transbordar. Essa notícia evidenciou o problema do descarte inadequado do lixo no país.

De acordo com a ABRELPE  (Associação Brasileira de Empresas de Limpeza Pública e Resíduos Especiais), no panorama do ano de 2022, revelou que o país gerou cerca de 81,8 milhões de toneladas de resíduos sólidos urbanos, na qual somente 76,1 milhões de toneladas foram coletados e 5,7 milhões de toneladas não tiveram um destino específico. A partir desta pesquisa, foi revelado que a quantidade de lixo lançada nos rios e litorais, por ano, seria suficiente para encher 30 vezes o estádio do Maracanã até o topo, sendo aproximadamente dois milhões de toneladas de resíduos.

Portanto como forma de manutenção preventiva, para evitar esse tipo de desastre, nasce o projeto “Barreira Ecológica Automática”(BEA), na qual o intuito é a construção de redes ao longo dos rios que coletam o lixo que desce pela correnteza e o armazena em caçambas de lixo que são pesadas, para que ao atingir um determinado peso, aciona uma empresa para fazer a coleta deste lixo. Tornando este processo cíclico e mecânico, é possível realizar a limpeza dos rios, coletando a maior parte do lixo que flutua na superfície.

<p align="center">
<img src="https://github.com/user-attachments/assets/3af2d9d0-9894-4afb-aace-7c225ca56bab" width="700px" border="0" >
  <p align="center">
  <a> Modelagem por Larissa De Almeida Lira Oliveira <a>
</p>

## 🛠 Instalação
A instalação só funciona por Windows.

- Faça o download do aplicativo ARDUÍNO IDE através do <a href="https://www.arduino.cc/en/software/">site oficial</a>.

- Já com o Arduino IDE instalado, execute-o e clique em Arquivo, e logo em seguida em Preferências.

- Uma janela será aberta. Cole o código "https://dl.espressif.com/dl/package_esp32_index.json" na aba de URL's adicionais.

- Selecione a placa na qual o código será executado.

- Insira o código contido na pasta scr.

- Apete em carregar o código.

## 📖 Componentes
![image](https://github.com/user-attachments/assets/e1bba79b-63cc-4641-8e0c-7abe29879e59)


### <br> 🛠 Hardware</br>
 <br> 1. ESP32 </br>
 <br> 2. Motores DC (2 unidades) </br>
 <br> 3. Ponte H </br>
 <br>	4. Módulo de peso </br>
 <br>	5. Protoboard </br>
 <br>	6. Fonte 5v </br>
 <br>	7. Módulo laser </br>
 <br>	8. Fotorresistor </br>
 <br>	9. Módulo HX711 </br>

## Fearramentas utilizadas:
- ``C++``<br>
- ``Arduíno IDE``<br>

## 🛠 Estrutura de pastas

-Raiz<br>
|<br>
|-->Documentos<br>
  &emsp;|-->Banco de dados<br>
  &emsp;|Entrega 1 <br>
      &emsp;&emsp;|Justificativa <br>
  &emsp;|Entrega 2 <br>
      &emsp;&emsp;|Modelagem Conceitual <br>
  &emsp;|Entrega 3 <br>
      &emsp;&emsp;|Modelagem Física (de duas tabelas) <br>
  &emsp;|Entrega 4 <br>
      &emsp;&emsp;|Modelagem Física (de todas as tabelas) <br>
      <br>
  &emsp;|-->SE<br>
  &emsp;|Entrega 1 <br>
      &emsp;&emsp;|Sensores <br>
  &emsp;|Entrega 2 <br>
      &emsp;&emsp;|Funcionamento Sensor Laser <br>
  &emsp;|Entrega 3 <br>
      &emsp;&emsp;|Modelo Físico (de duas tabelas) <br>
      <br>
  &emsp;|-->Algoritmo e lógica de programação<br>
    &emsp;&emsp;|Configurações iniciais.ino <br>
    &emsp;&emsp;|Função principal.ino <br>
    &emsp;&emsp;|Função sensor infravermelho.ino <br>
    &emsp;&emsp;|Função sensor de peso.ino <br>
    &emsp;&emsp;|Variaveis globais e bibliotecas.ino <br>
      <br>
  &emsp;|-->Redes <br>
  &emsp;|Entrega 1 <br>
      &emsp;&emsp;|Justificativa <br>
  &emsp;|Entrega 2 <br>
      &emsp;&emsp;|Testes <br>
  &emsp;|Entrega 3 <br>
      &emsp;&emsp;|Hardware <br>
  <br>
|-->imagens<br>
|-->src<br>
  &emsp;|-->Backend<br>
  &emsp;&emsp;|código.ino <br>
  
|readme.md<br>

<b>README.MD</b>: Arquivo que serve como guia e explicação geral sobre seu projeto. O mesmo que você está lendo agora.

Há também 4 pastas que seguem da seguinte forma:

<b>documentos</b>: Toda a documentação estará nesta pasta.

<b>imagens</b>: Imagens do sistema

<b>src</b>: Pasta que contém o código fonte.

## 🗃 Histórico de Lançamentos

- **0.1.0** - 13/10/2024: Compra de materiais.
- **0.2.0** - 15/10/2024: Criação do protótipo 3D.
- **0.3.0** - 20/10/2024 a 13/11/2024 : Teste de sensores.
- **0.4.0** - 05/11/2024 a 17/11/2024: Organização do GitHub e pastas.
- **0.5.0** - 11/11/2024: Desenvolvimento do código e circuito.
- **0.6.0** - 13/11/2024: Integração ao Blynk.
- **0.7.0** - 17/11/2024: Conclusão do projeto.

## 📋 Licença/License
<p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/2024-2-NADS1/Projeto1">Barreira Ambiental Ecológica (B.E.A.) </a> is licensed under <a href="https://creativecommons.org/licenses/by/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC BY 4.0<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1" alt=""><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1" alt=""></a></p>

## 🎓 Referências:
- https://blog.brkambiental.com.br/descarte-de-lixo/
- https://g1.globo.com/jornal-nacional/noticia/2019/03/22/pesquisadores-medem-o-volume-de-lixo-descartado-nos-rios-e-no-mar.ghtml
