#define BLYNK_TEMPLATE_ID "TMPL2WnHJ55AR" //template criado para o projeto
#define BLYNK_TEMPLATE_NAME "BEA" //nome do template
#define BLYNK_AUTH_TOKEN "q3gIDy126exES2zY9lXYzxBFtmhvBdPI"
#define BLYNK_PRINT Serial // Print serial do Blynk
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <HX711.h>

char auth[] = BLYNK_AUTH_TOKEN; // Token de autenticação
char ssid[] = "Nome da rede"; // Nome da rede Wi-Fi
char pass[] = "Senha da rede"; // Senha da rede Wi-Fi

BLYNK_CONNECTED() {
  Blynk.syncVirtual(V1); // Conectando os pinos virtuais 1, 2 e 3
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3);
}

// Sensores
float ultimaLeitura = 0;
int sensorPino1 = 23;
int sensorPino2 = 24;
int sensorPinoAnalogico = A0; // Nome alterado para maior clareza
float tensao = 4.0; // Define o valor mínimo aceitável para o sensor funcionar

int sensorInfra = T2; // Pino onde o sensor IR está conectado
int ultEstado = HIGH; // Último estado do sensor (inicializado como não detectando)
unsigned long tempoDeteccao = 0;

//declaracao dos pinos utilizados para controlar a velocidade de rotacao
const int PINO_ENA = 17; 
const int PINO_ENB = 27;

//declaracao dos pinos utilizados para controlar o sentido do motor
const int PINO_IN1 = 2; 
const int PINO_IN2 = 4;
const int PINO_IN3 = 13;
const int PINO_IN4 = 12;

int i = 0; //declaracao da variavel para as rampas

const int TEMPO_ESPERA = 100;//declaracao do intervalo de 1 segundo entre os sentidos de rotacao do motor

const int TEMPO_RAMPA = 120;//declaracao do intervalo de 30 ms para as rampas de aceleracao e desaceleraca

#define DEBUG_HX711
#define calibracao 10000.0

byte pinData = 15; // pino sensor de peso DT
byte pinClk = 14; // pino sensor de peso SCK

int sensorInfra = A0;  // Pino onde o sensor IR está conectado

float ultimaLeitura = 0; // variavel que guarda a última leitura do sensor de peso
float tensao = 0.3; // define o valor minimo aceitavel para o sensor funcionar corretamente
int ultimoEstado = HIGH;  // Último estado do sensor (inicializado como não detectando)
unsigned long tempoDeteccao = 0; 
int leituraConsecutivas = 0;

const int led = 8;
const int threshold = 100;
int sensorI;

HX711 scale;
