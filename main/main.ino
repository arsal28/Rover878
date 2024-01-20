const int IN_A0 = A0; // analog input

void setup() {
  pinMode (IN_A0, INPUT);
  pinMode (IN_D0, INPUT);
  Serial.begin(9600);
}

int value_A0;

void loop() {
  value_A0 = analogRead(IN_A0); // reads the analog input from the IR distance sensor
  Serial.print(value_A0);
  Serial.print(" ");
  Serial.println(value_D0);
  delay(1000);
}
