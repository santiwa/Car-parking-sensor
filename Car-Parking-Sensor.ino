/*Name: Tiwari Ramesh Sanjana
Date: 13-3-2024
Title: Implement a Car parking Sensor
Output Requirements: 1. When object is too close, dis <= 10cm, buzzer beeps continuously
2. If the object is moderately close, 10 < dis >= 30cm, beep every 0.5 sec
3. If the object is close, 30 < dis >= 50cm, beep every 1 sec
4. If the object is far away, dis >= 50cm, beep every 1.5 sec
*/

const int trigPin = 9; //Trigger pin of the ultrasonic sensor
const int echoPin = 10; //Echo pin of the ultrasonic sensor
const int buzzerPin = 8; //Buzzer pin

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  long duration, distance;
  
  //Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  //Send a 10us pulse to trigger
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  //Measure the duration of the echo pulse
  duration = pulseIn(echoPin, HIGH);
  
  //Calculate the distance
  distance = duration * 0.034 / 2;
  //distance = duration * 0.017;

  //Check if the object is within a certain range
  if (distance <= 10) {
    //If the object is too close, beep continuosly
    digitalWrite(buzzerPin, HIGH);
  } else if (distance > 10 && distance <= 30) {
    //If the object is moderately close, beep every 0.5 sec
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
    delay(500);
  } else if (distance > 30 && distance <= 50) {
    //If the object is close, beep every 1 sec
    digitalWrite(buzzerPin, HIGH);
    delay(1000);
    digitalWrite(buzzerPin, LOW);
    delay(1000);
  } else if (distance > 50) {
    //If the object is far away, beep every 1.5 sec
    digitalWrite(buzzerPin, HIGH);
    delay(1500);
    digitalWrite(buzzerPin, LOW);
    delay(1500);
  }

  //Add delay to stabilize readings
  delay(100);
}