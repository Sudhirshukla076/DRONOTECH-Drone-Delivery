
#include <Servo.h>

// -------- Pin Setup --------
const int PIN_BUTTON    = 2;   // Push button (other side to GND)
const int PIN_SERVO     = 5;   // Servo signal pin
const int PIN_INDICATOR = 8;   // LED or buzzer (optional)

// -------- Servo Positions --------
const int SERVO_CLOSED_POS = 0;    // Gate closed
const int SERVO_OPEN_POS   = 90;   // Gate open (drop)

// For button debounce
bool lastButtonState = HIGH;        // because of INPUT_PULLUP
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;  // 50 ms

Servo dropServo;

void setup() {
  Serial.begin(9600);

  pinMode(PIN_BUTTON, INPUT_PULLUP);  // Button active LOW
  pinMode(PIN_INDICATOR, OUTPUT);

  dropServo.attach(PIN_SERVO);
  dropServo.write(SERVO_CLOSED_POS);  // start closed

  digitalWrite(PIN_INDICATOR, LOW);

  Serial.println("DRONOTECH: Button-based Payload Drop System Ready.");
}

void loop() {
  int reading = digitalRead(PIN_BUTTON);

  // Check if button state changed → debounce
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Stable state
    if (reading == LOW && lastButtonState == HIGH) {
      // Button was just pressed
      Serial.println("Button pressed → Dropping payload...");
      dropPayload();
    }
  }

  lastButtonState = reading;
}

// -------- Helper: Drop Payload --------
void dropPayload() {
  digitalWrite(PIN_INDICATOR, HIGH);   // Turn on LED/Buzzer (optional)

  dropServo.write(SERVO_OPEN_POS);     // Open gate
  delay(1000);                         // Keep open for 1 second (adjust if needed)
  dropServo.write(SERVO_CLOSED_POS);   // Close gate
  delay(300);                          // Let servo settle

  digitalWrite(PIN_INDICATOR, LOW);    // Turn off LED/Buzzer
}
