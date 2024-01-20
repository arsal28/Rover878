const int analogIpt = A0; // infrared input

// Motor A pins
const int enableA = 11;
const int IN1 = 9;
const int IN2 = 8;

// Motor B pins
const int enableB = 10;
const int IN3 = 7;
const int IN4 = 6;

void setup() {
  // Initialize pin mode
  pinMode(analogIpt, INPUT);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // 

  Serial.begin(9600);
}

int changeVal;

void controlDir(){
  analogWrite(enableA, 255);
  analogWrite(enableB, 255);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(5000);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  delay(5000);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(5000);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  delay(5000);
}

void loop() {
  changeVal = map(analogRead(analogIpt), 0, 1023, 0, 100);
  Serial.print("Detected value: "+ changeVal);
}

