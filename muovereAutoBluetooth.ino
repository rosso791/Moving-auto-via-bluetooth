//Programma per muovere un auto 2wd utilizzando un ponte H L293DNE
#include <SoftwareSerial.h> //libreria di gestione del protocollo di trasmissione seriale
SoftwareSerial BT(10, 11);

const int motor1Sx = 3; //pin 3 INPUT motore sinistro
const int motor2Sx = 4; //pin 4 INPUT motore sinistro
const int motor2Dx = 12; //pin 12 INPUT motore destro
const int motor1Dx = 13; //pin 12 INPUT motore destro
const int pinEnableSx = 7; //pin ENABLE motore sinistro
const int pinEnableDx = 6; //pin ENABLE motore destro
int direzione; //variabile per ricevere la direzione dell'auto tramite tastiera

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  pinMode(motor1Sx, OUTPUT);
  pinMode(motor2Sx, OUTPUT);
  pinMode(motor1Dx, OUTPUT);
  pinMode(motor2Dx, OUTPUT);
  pinMode(pinEnableSx, OUTPUT);
  pinMode(pinEnableDx, OUTPUT);
  //teniamo i motori sempre accesi
  digitalWrite(pinEnableSx, HIGH); //accensione motore sinistro
  digitalWrite(pinEnableDx, HIGH); //accensione motore destro
}

void loop() {
  //lettura direzione tramite tastiera
  direzione = BT.read();

  if (direzione == 119) {
    digitalWrite(motor1Sx, HIGH); //accendo motori 1 sinistro e destro per andare avanti
    digitalWrite(motor2Sx, LOW);
    digitalWrite(motor1Dx, HIGH);
    digitalWrite(motor2Dx, LOW);
  }
  if (direzione == 115) {
    digitalWrite(motor1Sx, LOW);  //accendo motori 2 sinistro e destro per andare indietro
    digitalWrite(motor2Sx, HIGH);
    digitalWrite(motor1Dx, LOW);
    digitalWrite(motor2Dx, HIGH);
  }

  if (direzione == 97) {
    digitalWrite(motor1Sx, LOW); //accendo il motore di destra per girare a sinistra
    digitalWrite(motor2Sx, LOW);
    digitalWrite(motor1Dx, HIGH);
    digitalWrite(motor2Dx, LOW);
  }
  if (direzione == 100) {
    digitalWrite(motor1Sx, HIGH); //accendo il motore di sinistra per girare a destra
    digitalWrite(motor2Sx, LOW);
    digitalWrite(motor1Dx, LOW);
    digitalWrite(motor2Dx, LOW);
  }

  if (direzione == 32) {
    digitalWrite(motor1Sx, LOW); //stop fermo tutti i motori
    digitalWrite(motor2Sx, LOW);
    digitalWrite(motor1Dx, LOW);
    digitalWrite(motor2Dx, LOW);
  }

}
