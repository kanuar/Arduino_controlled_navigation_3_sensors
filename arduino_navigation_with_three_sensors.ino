// C++ code
//
int distance_right = 0;

int distance_left = 0;

int tilt = 0;

int unnamed = 0;

int distance_front = 0;

int servo_control = 0;

int i = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(6, INPUT);
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  distance_front = 0.01723 * readUltrasonicDistance(2, 1);
  distance_right = 0.01723 * readUltrasonicDistance(10, 11);
  distance_left = 0.01723 * readUltrasonicDistance(12, 13);
  tilt = digitalRead(6);
  Serial.print(distance_left);
  Serial.println("cm");
  Serial.print(distance_right);
  Serial.println("cm");
  if (distance_front > 1 && distance_front < 40) {
    delay(1000); // Wait for 1000 millisecond(s)
  }
  if (distance_right > 1 && distance_right < 40) {
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);
  }
  if (distance_left > 1 && distance_left < 40) {
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
  }
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  Serial.println("");
}
