// Embedded Leakage Notification Demo
// Simulates a moisture/leakage sensor using a potentiometer.
// If the simulated moisture level passes a threshold,
// the system enters WARNING state and triggers LED/buzzer notification.

const int SENSOR_PIN = A0;
const int LED_PIN = 8;
const int BUZZER_PIN = 9;

const int LEAKAGE_THRESHOLD = 650;
const int RESET_THRESHOLD = 550;

const unsigned long SAMPLE_INTERVAL_MS = 500;
const unsigned long BUZZER_DURATION_MS = 150;

enum SystemState {
  NORMAL,
  WARNING
};

SystemState currentState = NORMAL;

unsigned long lastSampleTime = 0;
bool alertAlreadyTriggered = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("Embedded Leakage Notification Demo started");
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastSampleTime >= SAMPLE_INTERVAL_MS) {
    lastSampleTime = currentTime;

    int moistureLevel = readMoistureLevel();
    updateLeakageState(moistureLevel);
    printStatus(moistureLevel);
  }
}

int readMoistureLevel() {
  return analogRead(SENSOR_PIN);
}

void updateLeakageState(int moistureLevel) {
  if (currentState == NORMAL && moistureLevel >= LEAKAGE_THRESHOLD) {
    currentState = WARNING;
    triggerAlert();
  }

  if (currentState == WARNING && moistureLevel <= RESET_THRESHOLD) {
    currentState = NORMAL;
    clearAlert();
  }
}

void triggerAlert() {
  digitalWrite(LED_PIN, HIGH);

  if (!alertAlreadyTriggered) {
    tone(BUZZER_PIN, 1000);
    delay(BUZZER_DURATION_MS);
    noTone(BUZZER_PIN);

    alertAlreadyTriggered = true;
  }
}

void clearAlert() {
  digitalWrite(LED_PIN, LOW);
  alertAlreadyTriggered = false;
}

void printStatus(int moistureLevel) {
  Serial.print("Moisture level: ");
  Serial.print(moistureLevel);
  Serial.print(" | State: ");

  if (currentState == NORMAL) {
    Serial.println("NORMAL");
  } else {
    Serial.println("WARNING - leakage threshold reached");
  }
}