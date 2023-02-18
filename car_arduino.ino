int trigPin = 3;
int echoPin = 2;
int m1 = 5;
int m2 = 4;
int m3 = 7;
int m4 = 6;
int s1 = 10;
int s2 = 11;
void setup() {
  Serial.begin(9600);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  analogWrite(s1, 170);
  analogWrite(s2, 170);
}
void loop() {
  long duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.print(distance);
  Serial.println("CM");
  delay(10);
  if ((distance < 15))
  {
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW); //
    digitalWrite(m4, LOW);
    delay(1000);
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, LOW); //
    digitalWrite(m4, HIGH);
    delay(500);
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW); //
    digitalWrite(m4, HIGH);
    delay(700);
  }
  else if (distance > 15)
  {
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH); //HIGH
    digitalWrite(m4, LOW);
  }
}
