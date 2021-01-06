#include <Arduino.h>

#define LED_GRE D1
#define LED_RED D2
#define LED_WHI D3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(LED_GRE, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_WHI, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("LED GRE");
  digitalWrite(LED_GRE, HIGH);
  delay(3000);
  digitalWrite(LED_GRE, LOW);
  delay(1000);
  Serial.println("LED RED");
  digitalWrite(LED_RED, HIGH);
  delay(3000);
  digitalWrite(LED_RED, LOW);
  delay(1000);
  Serial.println("LED WHI");
  digitalWrite(LED_WHI, HIGH);
  delay(3000);
  digitalWrite(LED_WHI, LOW);
  delay(1000);



}
