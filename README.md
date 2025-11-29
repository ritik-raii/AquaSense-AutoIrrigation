/*───────────────────────────────────────────────────────────────
   Project: AquaSense Auto Irrigation System
   Type: Smart Moisture-Controlled Watering Automation
   Purpose: Water only when needed. Save plants. Save water.
────────────────────────────────────────────────────────────────*/

MODULE :: INTRODUCTION
{
    AquaSense is a soil-intelligent irrigation controller.
    It watches the moisture readings like a guard on duty.
    If the soil dries past a threshold → it activates the pump.
    If moisture returns → it cuts water instantly.

    Zero human reminder required. Nature gets what it needs.
}

/*───────────────────────────────────────────────────────────────*/

MODULE :: FEATURES
{
    ✦ Automated watering based on live soil readings
    ✦ No WiFi or cloud dependency; works offline forever
    ✦ Fully adjustable threshold for different soil types
    ✦ Serial monitor output for analysis + calibration
    ✦ Extendable into IoT, mobile dashboard, solar setup
}

/*───────────────────────────────────────────────────────────────*/

MODULE :: COMPONENTS_REQUIRED
{
    - Arduino Uno/Nano
    - Soil moisture sensor (analog)
    - Relay module
    - DC water pump + external power
    - jumper wires + soil + plants (obviously)
}

/*───────────────────────────────────────────────────────────────*/

DIAGRAM :: WIRING_MAP
{
    SoilSensor.VCC  → 5V
    SoilSensor.GND  → GND
    SoilSensor.A0   → A0

    Relay.VCC       → 5V
    Relay.GND       → GND
    Relay.IN        → D9

    Pump           → Relay output → external power supply

    Condition:
       if (moisture > threshold) → Pump ON
       else                      → Pump OFF
}

/*───────────────────────────────────────────────────────────────*/

MODULE :: ARDUINO_CODE
{
    ```cpp
    int sensorPin = A0;
    int relayPin = 9;
    int moistureValue;
    int threshold = 700;

    void setup() {
      pinMode(relayPin, OUTPUT);
      digitalWrite(relayPin, HIGH);
      Serial.begin(9600);
      Serial.println("Smart Irrigation System Initialized");
    }

    void loop() {
      moistureValue = analogRead(sensorPin);
      Serial.print("Moisture: ");
      Serial.println(moistureValue);

      if (moistureValue > threshold) {
        digitalWrite(relayPin, LOW);
        Serial.println("Pump → ON [Soil Dry]");
      } else {
        digitalWrite(relayPin, HIGH);
        Serial.println("Pump → OFF [Soil Moist]");
      }

      delay(1000);
    }
    ```
}

/*───────────────────────────────────────────────────────────────*/

MODULE :: CALIBRATION
{
    1. Open Serial Monitor → test dry vs wet soil.
    2. Adjust threshold (400-800 ideal range).
    3. When live readings stabilize → deploy in field.

    Plants don’t guess moisture. You shouldn’t either.
}

/*───────────────────────────────────────────────────────────────*/

FUTURE_EXPANSION()
{
    + ESP32 + Blynk/MQTT cloud monitoring dashboard
    + Water Level + Rain detection hybrid logic
    + Solar power + Li-ion backup for outdoor farming
    + Auto-learning irrigation schedule (ML based)
}

/*───────────────────────────────────────────────────────────────*/

STATUS :: COMPLETE
AquaSense stands ready. Drop into your garden,
and let intelligence irrigate silently.
