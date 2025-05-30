#include <Servo.h>

// Definir os pinos
const int trigPin = 9;
const int echoPin = 10;
const int ledVerde = 2;
const int ledAmarelo = 3;
const int ledVermelho = 4;
const int buzzerPin = 5;
const int servoPin = 6;

// Definir o servo motor
Servo bombaDrenagem;

// Variáveis de controle
long duracao;
int distancia;
int nivelCritico = 30;  // Distância em cm para nível crítico
int nivelBaixo = 80;  // Distância em cm para nível baixo

void setup() {
  // Inicializar os pinos
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Inicializar o servo
  bombaDrenagem.attach(servoPin);

  // Inicializar comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Enviar sinal para o HC-SR04
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Medir o tempo de retorno do eco
  duracao = pulseIn(echoPin, HIGH);
  
  // Calcular a distância
  distancia = duracao * 0.034 / 2;

  // Exibir a distância no monitor serial para debug
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Lógica para controle dos LEDs e ações automáticas
  if (distancia <= nivelCritico) {
    // Nível de água crítico
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
    tone(buzzerPin, 1000); // Emitir som
    bombaDrenagem.write(180); // Ativar bomba (simulando drenagem)
  }
  else if (distancia < nivelBaixo && distancia > nivelCritico) {
    // Nível de água alto
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);
    noTone(buzzerPin); // Parar som
    bombaDrenagem.write(90); // Manter a bomba em modo de espera
  }
  else if (distancia >= nivelBaixo) {
    // Nível de água baixo
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, HIGH);
    noTone(buzzerPin); // Parar som
    bombaDrenagem.write(0); // Bomba desligada
  }

  delay(500); // Espera meio segundo para nova leitura
}