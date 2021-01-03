/* Interface L298N With NodeMCU
   By TheCircuit
*/

int ENA = 3; //4;
int IN1 = 2; //0;
int IN2 = 4; //2;

int ENB = 14; //14;
int IN3 = 12; //12;
int IN4 = 13; //13;

void setup() {
  Serial.begin(9600);

  // set all the motor control pins to outputs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

// this function will run the motors in both directions at a fixed speed

void testOne() {
  Serial.println("Test 1");

  // turn on motor
  digitalWrite(ENA, HIGH);  // set speed to 200 out of possible range 0~255
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(ENB, HIGH);  // set speed to 200 out of possible range 0~255
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(5000); // now change motor directions

//  digitalWrite(IN1, LOW);
//  digitalWrite(IN2, HIGH);
//
//  digitalWrite(IN3, HIGH);
//  digitalWrite(IN4, LOW);
//
//  delay(5000); // now turn off motors

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// this function will run the motors across the range of possible speeds
// note that maximum speed is determined by the motor itself and the operating voltage
// the PWM values sent by analogWrite() are fractions of the maximum speed possible by your hardware

void testTwo() {

  Serial.println("Test 2");

  // turn on motors
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  // accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++)
  {
    analogWrite(ENA, i);
    analogWrite(ENB, i);
    delay(50);
  }

  // decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i)
  {
    analogWrite(ENA, i);
    analogWrite(ENB, i);
    delay(50);
  }

  // now turn off motors
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {
  testOne();
  delay(1000);
//  testTwo();
//  delay(1000);
}
