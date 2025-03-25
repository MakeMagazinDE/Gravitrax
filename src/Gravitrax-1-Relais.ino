// Definieren des Relais-Pins
const int RELAY_PIN = 13;

// Variablen für den Relais-Status
bool relayState = false;

// Zeitintervall für das Umschalten (in Millisekunden)
const unsigned long INTERVAL = 5000;  // 5 Sekunden
unsigned long previousMillis = 0;

void setup() {
  // Serielle Kommunikation starten
  Serial.begin(9600);
  
  // Relais-Pin als Ausgang konfigurieren
  pinMode(RELAY_PIN, OUTPUT);
  
  // Relais initial ausschalten
  digitalWrite(RELAY_PIN, LOW);
  relayState = false;
  
  Serial.println("ESP32 Relais-Steuerung gestartet");
}

void loop() {
  // Aktuelle Zeit erfassen
  unsigned long currentMillis = millis();

  // Prüfen ob das Intervall abgelaufen ist
  if (currentMillis - previousMillis >= INTERVAL) {
    // Relais-Zustand umschalten
    relayState = !relayState;
    
    // Relais schalten
    digitalWrite(RELAY_PIN, relayState ? HIGH : LOW);
    
    // Status ausgeben
    Serial.print("Relais Status: ");
    Serial.println(relayState ? "AN" : "AUS");
    
    // Zeitstempel aktualisieren
    previousMillis = currentMillis;
  }
}
