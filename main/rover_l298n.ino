#include <L298NX2.h>

const int IN_A0 = A0;  // infrared input LEFT side
const int IN_A1 = A1;  // infrared input RIGHT side

const int trigPin = 12;
const int echoPin = 13;
const int IRThreshold = 20;
const int USThreshold = 20;

const int speed = 1000;

// Motor A (right) pins
const int IN1_A = 9; // forward
const int IN2_A = 8; // reverse

// Motor B (left) pins
const int IN1_B = 7; // forward
const int IN2_B = 6; // reverse

float reading;

L298NX2 motors(IN1_A, IN2_A, IN1_B, IN2_B);

void controlDir();

void setup() {
  // Initialize pin mode
  pinMode(IN_A0, INPUT);
  pinMode(IN_A1, INPUT);
  pinMode(trigPin, INPUT);

  motors.setSpeed(255);

  Serial.begin(9600);
}

int changeVal;

void ultrasonicReading(){
  pinMode(echoPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  float duration = pulseIn(echoPin, HIGH);
  float distance = (duration / 58);
  reading = distance;
}

void loop() {
  int IR_A0 = analogRead(IN_A0);
  int IR_A1 = analogRead(IN_A1);

  int changeValA0 = map(value_A0, 0, 1023, 0, 100);
  int changeValA1 = map(value_A1, 0, 1023, 0, 100);
  Serial.print(changeValA0);
  Serial.print(" ");
  Serial.print(reading);
  Serial.print(" ");
  Serial.println(changeValA1);
  // analogWrite(enableA, speed); 
  // analogWrite(enableB, speed); 

  
  motors.forward();

  if (IR_A0 >= IRThreshold) {
    motors.stopB(); // Stops left motor
    motors.forwardA(); // Move right
  }

  if (IR_A1 >= IRThreshold) {
    motors.stopA(); // Stops right motor
    motors.forwardB(); // Move left
  }
}

void controlDir() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(2000);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(2000);
}

void moveLeft(){
  motors.stopA();

}

void moveRight(){
  motors.stopB();
}
