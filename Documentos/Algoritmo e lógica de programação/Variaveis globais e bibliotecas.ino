#define BLYNK_TEMPLATE_ID "TMPL2WnHJ55AR" // Template criado para o projeto
#define BLYNK_TEMPLATE_NAME "BEA" // Nome do template
#define BLYNK_AUTH_TOKEN "q3gIDy126exES2zY9lXYzxBFtmhvBdPI"
#define BLYNK_PRINT Serial // Impressão serial do Blynk

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <HX711.h>

char auth[] = BLYNK_AUTH_TOKEN; // Token de autenticação
char ssid[] = "Nome da rede"; // Nome da rede Wi-Fi
char pass[] = "Senha da rede"; // Senha da rede Wi-Fi

BLYNK_CONNECTED() {
  Blynk.syncVirtual(V1); // Conectando o pino virtual 1
}

// Sensores
float ultimaLeitura = 0;
float tensaoMinima = 0.3; // Define o valor mínimo aceitável para o sensor funcionar
int sensorInfra = A0; // Pino onde o sensor IR está conectado
int ultimoEstado = HIGH; // Último estado do sensor (inicializado como não detectando)
unsigned long tempoDeteccao = 0;

// Pinos utilizados para controlar a velocidade de rotação
const int PINO_ENA = 17; 
const int PINO_ENB = 27;

// Pinos utilizados para controlar o sentido do motor
const int PINO_IN1 = 2; 
const int PINO_IN2 = 4;
const int PINO_IN3 = 13;
const int PINO_IN4 = 12;

const int TEMPO_ESPERA = 100; // Intervalo de 100 ms entre os sentidos de rotação do motor
const int TEMPO_RAMPA = 120; // Intervalo de 120 ms para as rampas de aceleração e desaceleração

#define DEBUG_HX711
#define CALIBRACAO 10000.0

byte pinData = 15; // Pino sensor de peso DT
byte pinClk = 14; // Pino sensor de peso SCK

int leituraConsecutivas = 0;

const int led = 8;
const int threshold = 100;

HX711 scale;
