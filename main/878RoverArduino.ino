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

void loop() {
  changeVal = map(analogRead(analogIpt), 0, 1023, 0, 100);
  Serial.print("Detected value: "+ changeVal)
}

void controlDir(){

}