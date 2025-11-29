# AquaSense: Smart Automatic Irrigation

A simple soil-moisture based irrigation system that turns a water pump ON only when soil becomes dry. Designed for gardens, home plants and small scale automation. No supervision required once installed.

---

## 📌 Features
| Capability | Description |
|----------|-------------|
| Auto-water control | Pump activates only when soil is dry |
| Adjustable threshold | Tune moisture limit as needed |
| Low power | Runs continuously without monitoring |
| Hardware-ready | Works on Arduino, Nano, Uno, ATmega etc. |

---

## 🔧 Hardware Required
- Arduino board
- Soil Moisture Sensor
- Relay Module
- DC Water Pump
- Jumper wires + external power supply

---

## 📡 Working Overview
1. Moisture sensor continuously reads soil hydration.
2. If dryness exceeds the defined threshold, relay triggers pump.
3. When soil moisture rises, pump turns off automatically.
4. No cloud control needed. Local logic runs forever.

---

## 🛠 Wiring Setup (Basic)
Sensor A0 → Arduino A0  
Relay IN  → Pin D9  
VCC + GND connections common  
Pump connected through relay switching

*(This setup can be scaled to IoT or app monitoring later.)*

---

## 📷 Media Preview 

![System Setup](Assets/IMG_20251129_000058.jpg)

STATUS :: COMPLETE
AquaSense stands ready. Drop into your garden,
and let intelligence irrigate silently.

---

## Future Upgrades
- ESP32 dashboard with live soil data  
- Water tank level + rain sensing  
- Solar powered outdoor deployment  

---

**AquaSense keeps plants alive while you focus on bigger things.**
