const int IN_A0 = A0;  // infrared input LEFT side
const int IN_A1 = A1;  // infrared input RIGHT side

const int trigPin = 12;
const int echoPin = 13;
const int IRThreshold = 20;
const int USThreshold = 20;

const int speed = 1000;

// Motor A (right) pins
const int enableA = 11;
const int IN1 = 9; // forward
const int IN2 = 8; // reverse

// Motor B (left) pins
const int enableB = 10;
const int IN3 = 7; // forward
const int IN4 = 6; // reverse

float reading;

void controlDir();

void setup() {
  // Initialize pin mode
  pinMode(IN_A0, INPUT);
  pinMode(IN_A1, INPUT);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(trigPin, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  analogWrite(enableA, speed);
  analogWrite(enableB, speed);
  // Turn off motors - Initial state
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

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
  int value_A0 = analogRead(IN_A0);
  int value_A1 = analogRead(IN_A1);

  int changeValA0 = map(value_A0, 0, 1023, 0, 100);
  int changeValA1 = map(value_A1, 0, 1023, 0, 100);
  Serial.print(changeValA0);
  Serial.print(" ");
  Serial.print(reading);
  Serial.print(" ");
  Serial.println(changeValA1);
  // analogWrite(enableA, speed); 
  // analogWrite(enableB, speed); 

  analogWrite(IN1, 90);
  analogWrite(IN2, 0);
  analogWrite(IN3, 90);
  analogWrite(IN4, 0);
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
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 180);
  analogWrite(IN4, 0);
}

void moveRight(){
  analogWrite(IN1, 180);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
}

void stopMotors(){
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
  
}
