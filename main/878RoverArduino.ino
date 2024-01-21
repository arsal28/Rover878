const int IN_A0 = A0;  // infrared input left side
const int IN_A1 = A1;  // infrared input RIGHT side
const int trigPin = 12;
const int echoPin = 13;
const int IRThreshold = 80;
const int USThreshold = 20;

const int speed = 255;

// Motor A pins
const int enableA = 11;
const int IN1 = 9; // forward
const int IN2 = 8; // reverse

// Motor B pins
const int enableB = 10;
const int IN3 = 7; // forward
const int IN4 = 6; // reverse

void controlDir();

void setup() {
  // Initialize pin mode
  pinMode(analogIpt1, INPUT);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(trigPin, INPUT);
  pinMode(echoPin, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Turn off motors - Initial state
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  Serial.begin(9600);
}

int changeVal;

void ultrasonicReading(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(3);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  int duration = pulseln(echoPin, HIGH);
  int distance = (duration * 0.0343) / 2;
  return distance
}

void loop() {
  value_A0 = analogRead(IN_A0);
  value_A1 = analogRead(IN_A1);

  changeVal = map(analogRead(IN_A0), 0, 1023, 0, 100);
  Serial.print("Detected value: " + changeVal);

  analogWrite(enableA, speed);
  analogWrite(enableB, speed);

  // **DONT TOUCH THIS CODE**
  // if (value_A0 >= threshold) {
  //   analogWrite(IN1, 0);
  //   analogWrite(IN2, 0);
  //   analogWrite(IN3, 0);
  //   analogWrite(IN4, 0);
  // }

  // if (value_A1 >= threshold) {
  //   analogWrite(IN1, 0);
  //   analogWrite(IN2, 0);
  //   analogWrite(IN3, 0);
  //   analogWrite(IN4, 0);
  // } 

  analogWrite(IN1, 180);
  analogWrite(IN2, 0);
  analogWrite(IN3, 180);
  analogWrite(IN4, 0);

  delay(3000);

  analogWrite(IN1, 0);
  analogWrite(IN2, 180);
  analogWrite(IN3, 0);
  analogWrite(IN4, 180);

  delay(3000);
}

void controlDir() {
  analogWrite(enableA, speed);
  analogWrite(enableB, speed);

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
