int sensorPin = A0;
int relayPin = 9;
int moistureValue;
int threshold = 700;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
  Serial.begin(9600);
  Serial.println("Smart Irrigation System Started");
}

void loop() {
  moistureValue = analogRead(sensorPin);
  Serial.print("Moisture Value: ");
  Serial.println(moistureValue);

  if (moistureValue > threshold) {
    digitalWrite(relayPin, LOW);
    Serial.println("Pump: ON - Soil dry");
  } else {
    digitalWrite(relayPin, HIGH);
    Serial.println("Pump: OFF - Soil sufficient");
  }
  delay(1000);
}
