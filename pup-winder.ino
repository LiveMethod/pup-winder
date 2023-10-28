const int rotSensorPin = 2; // Change this to the appropriate pin
const int ledPin = 13;
int triggerCount = 0;
int lastState;

void setup() {
  pinMode(rotSensorPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Initialize the Serial Monitor
}

void loop() {
  const int triggerAtInit = triggerCount + 0 ; // +0 incase it's a ref that preserves when I don't want it to? IDK
  int rotSensorState = digitalRead(rotSensorPin);

  if (rotSensorState == LOW && lastState != LOW) { // rot sensor is activated
    digitalWrite(ledPin, HIGH); // Turn the LED on
    triggerCount++; // Increment the trigger count
    Serial.print("Trigger Count: ");
    Serial.println(triggerCount); // Print the trigger count to Serial Monitor
  } else {
    digitalWrite(ledPin, LOW); // Turn the LED off
  }
  lastState = rotSensorState;
}