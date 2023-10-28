const int rotSensorPin = 2; // Change this to the appropriate pin
const int ledPin = 13;
int triggerCount = 0;
int lastState;
unsigned long lastUpdateTime = 0;
int triggerCountLastnSecs = 0;

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
    // Serial.print("Rots: ");
    Serial.println(triggerCount); // Print the trigger count to Serial Monitor
  } else {
    digitalWrite(ledPin, LOW); // Turn the LED off
  }

  lastState = rotSensorState;

  unsigned long currentTime = millis();
  if (currentTime - lastUpdateTime >= 5000) {
    // Calculate average triggers per minute for the last 10 seconds
    float averageTriggersPerMinute = (triggerCount - triggerCountLastnSecs) / 5.0 * 60.0;

    // Print the result to the Serial Monitor
    Serial.print("Average Triggers Per Minute (Last 5 Seconds): ");
    Serial.println(averageTriggersPerMinute);

    // Update the trigger count for the last 10 seconds
    triggerCountLastnSecs = triggerCount;

    lastUpdateTime = currentTime;
  }
}
