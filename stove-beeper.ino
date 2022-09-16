
const int THRESHOLD = 150; // The light sensor threshold
const int BEEP_RATE = 700; // The rate at which the buzzer beeps
int muteBtnPin = 7; // The pin for the mute button
int sensorPin = A0; // The pin for the light sensor
int sensorValue = 0; // The intensity of light
int muteBtnState = 0; // The state of the button
int beepTicker = 0; // Used for polling for button presses fast, and beeping slow
bool muted = true; // The mute state

void setup() {
  pinMode(muteBtnPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the value from the light sensor
  sensorValue = analogRead(sensorPin);

  // Wait for the stove to be turned back on
  while(muted) {
    sensorValue = analogRead(sensorPin);
    if (sensorValue > THRESHOLD) {
      muted = false;
    }
  }

  // Make beeping noises until the mute button is pressed
  while(!muted && sensorValue < THRESHOLD) {
    muteBtnState = digitalRead(muteBtnPin);
    if(muteBtnState == HIGH) {
      Serial.println("Mute button pressed!");
      muted = true;
      break;
    }

    // Read the new sensor value
    sensorValue = analogRead(sensorPin);

    // Produce a noise and add a delay
    if(beepTicker >= BEEP_RATE) {
      tone(8, 680, 50);
      beepTicker = 0;
    } else {
      beepTicker += BEEP_RATE / 10;
    }
    delay(BEEP_RATE / 10);
  }
}