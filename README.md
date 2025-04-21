<b>🔥 Smart Safety System using Arduino</b>

An Arduino-based safety system designed to detect **gas leaks** and **flames**, provide real-time alerts using a buzzer, OLED display, and Bluetooth communication. Ideal for use in homes, kitchens, or industrial environments where fire and gas threats must be monitored continuously.

---

<b>📌 Features </b>

- ✅ <b>MQ-135 Gas Sensor</b> – Detects air pollution and harmful gases
- 🔥 <b>IR Flame Sensor</b> – Detects fire or flame presence
- 🔊 <b>Buzzer</b> – Emits a loud beep when flame or gas is detected
- 📺 <b>OLED Display (SSD1306)</b> – Displays gas value and flame alert
- 📡 <b>Bluetooth (HC-05)</b> – Sends alerts to a connected mobile device
- 🧠 <b>Serial Monitor Support</b> – For debug and live status messages

---

<b>🔧 Components Used</b>

| Component         | Quantity |
|------------------|----------|
| Arduino Uno      | 1        |
| MQ-135 Sensor    | 1        |
| IR Flame Sensor  | 1        |
| OLED Display     | 1        |
| HC-05 Bluetooth Module | 1 |
| Buzzer           | 1        |
| Breadboard + Jumpers | 1 set  |
| Power Source     | USB / Battery |

---

<b>⚙️ How It Works</b>

1. MQ-135 constantly reads air quality levels.
2. Flame sensor checks for IR light (from flame/fire).
3. If unsafe gas or flame is detected:
   - Buzzer beeps using `tone()`
   - OLED shows real-time alert
   - Bluetooth sends a warning to your phone
   - Serial Monitor also logs the event

---
