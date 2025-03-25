// Definieren der Relais-Pins
const int RELAY_PINS[] = {5, 16, 17};  // GPIO 5, 16, 17
const int NUM_RELAYS = 3;              // Anzahl der Relais

// Array für die Relais-Status
bool relayStates[NUM_RELAYS] = {false, false, false};

// Zeitintervall für das Umschalten (in Millisekunden)
const unsigned long INTERVAL = 5000;  // 5 Sekunden
unsigned long previousMillis = 0;

void setup() {
  // Serielle Kommunikation starten (für Debugging)
  Serial.begin(115200);
  
  // Relais-Pins als Ausgang konfigurieren
  for (int i = 0; i < NUM_RELAYS; i++) {
    pinMode(RELAY_PINS[i], OUTPUT);
    // Relais initial ausschalten
    digitalWrite(RELAY_PINS[i], LOW);
  }
  
  Serial.println("ESP32 Relais-Steuerung (3 Relais) gestartet");
}

void loop() {
  // Aktuelle Zeit erfassen
  unsigned long currentMillis = millis();

  // Prüfen ob das Intervall abgelaufen ist
  if (currentMillis - previousMillis >= INTERVAL) {
    // Relais-Zustände umschalten
    for (int i = 0; i < NUM_RELAYS; i++) {
      relayStates[i] = !relayStates[i];
      // Relais schalten
      digitalWrite(RELAY_PINS[i], relayStates[i] ? HIGH : LOW);
      
      // Status ausgeben
      Serial.print("Relais ");
      Serial.print(i + 1);
      Serial.print(" (GPIO ");
      Serial.print(RELAY_PINS[i]);
      Serial.print("): ");
      Serial.println(relayStates[i] ? "AN" : "AUS");
    }
    
    Serial.println("---");
    // Zeitstempel aktualisieren
    previousMillis = currentMillis;
  }
}