### **📌 Project Name: AVR Temperature Meter Using ADC & LCD**  
This project implements a **temperature monitoring system** using an **AVR microcontroller**, an **ADC (Analog-to-Digital Converter)** to read the temperature sensor values, and an **LCD display** to show the temperature in real-time.

---

## **📖 Table of Contents**
1. [Project Overview](#project-overview)  
2. [Features](#features)  
3. [Hardware Requirements](#hardware-requirements)  
4. [Software Requirements](#software-requirements)  
5. [Circuit Diagram](#circuit-diagram)  
6. [How It Works](#how-it-works)  
7. [Installation & Compilation](#installation--compilation)  
8. [Code Structure](#code-structure)  
9. [Usage](#usage)  
10. [Troubleshooting](#troubleshooting)  

---

## **📝 Project Overview**  
The **temperature meter** reads **analog voltage** from a **temperature sensor (e.g., LM35)** using **ADC** and converts it into **temperature in Celsius**. The calculated temperature is displayed on a **16x2 LCD screen**.

---

## **✨ Features**  
✅ **Real-time temperature monitoring**  
✅ **Displays temperature on a 16x2 LCD**  
✅ **Handles positive and negative temperatures**  
✅ **Accurate ADC conversion using 2.5mV per step**  
✅ **Compact and efficient design**  

---

## **🛠️ Hardware Requirements**  
- **ATmega32** (or any AVR microcontroller)  
- **LM35 Temperature Sensor**  
- **16x2 LCD Display**  
- **10kΩ Potentiometer** (For LCD contrast control)  
- **Resistors (1kΩ, 10kΩ)**  
- **Power Supply (5V DC)**  
- **Connecting Wires**  
- **Breadboard / PCB**  

---

## **🖥️ Software Requirements**  
- **Atmel Studio / AVR-GCC Compiler**  
- **AVR Dude / Proteus for Simulation**  
- **USBasp / Arduino as ISP for Programming**  

---

## **🔌 Circuit Diagram**  
📌 **Connections:**  
- **LM35 Sensor Output** → **ADC Channel (e.g., ADC0, PA0)**  
- **LCD** connected to **PORTD**  
- **Microcontroller** runs at **8MHz**  

💡 **A full circuit diagram can be found in the `docs/` folder.**  

---

## **⚙️ How It Works**  
1. **Sensor Reads Temperature:** The **LM35 sensor** outputs **10mV per °C**.  
2. **ADC Converts Analog to Digital:** The **ADC** reads the **analog voltage** and converts it to a digital value.  
3. **Temperature Calculation:** The **voltage is converted** into a temperature value using:  
   \[
   Temperature = \frac{Voltage - 1000}{10}
   \]
4. **Display on LCD:** The temperature is displayed **in °C** on the **LCD screen**.  

---

## **🛠 Installation & Compilation**  
### **🔹 1. Clone the Repository**  
```sh
git clone https://github.com/yourusername/AVR_Temperature_Meter.git
cd AVR_Temperature_Meter
```

### **🔹 2. Open the Project in Atmel Studio**  
- Open **Atmel Studio**  
- Load the **temperature_meter.c** file  

### **🔹 3. Compile & Upload**  
#### **Using AVRDUDE (Command Line)**  
```sh
avr-gcc -mmcu=atmega32 -Os temperature_meter.c -o temperature_meter.hex
avrdude -c usbasp -p m32 -U flash:w:temperature_meter.hex:i
```

#### **Using Atmel Studio**  
- Click **Build** → **Compile**  
- Click **Tools** → **Program Device** → **Upload**  

---

## **📁 Code Structure**  
```
📂 AVR_Temperature_Meter
│── 📁 src
│   ├── temperature_meter.c  # Main program logic
│   ├── LCD.c                # LCD display functions
│   ├── LCD.h                # LCD header file
│   ├── ADC.c                # ADC functions
│   ├── ADC.h                # ADC header file
│── 📁 docs
│   ├── circuit_diagram.png  # Circuit diagram
│   ├── README.md            # Project documentation
│── 📁 bin
│   ├── temperature_meter.hex # Compiled HEX file
│── 📁 simulation
│   ├── temperature_meter.pdsprj # Proteus simulation file
│── README.md                # This file
```

---

## **📌 Usage**  
1. **Power on the system** → LCD initializes.  
2. **The LM35 sensor starts reading temperature.**  
3. **The temperature is displayed on the LCD.**  
4. **If temperature changes, the LCD updates in real-time.**  

### **Example Temperature Readings**  
| Sensor Voltage | Display Output |
|---------------|---------------|
| 2.5V | `Temperature: 25°C` |
| 1.5V | `Temperature: 15°C` |
| 3.0V | `Temperature: 30°C` |
| 0.5V | `Temperature: 5°C` |

---

## **❗ Troubleshooting**  
| Issue | Solution |
|-------|----------|
| LCD not displaying | Check **VCC & GND connections** and **10kΩ potentiometer** |
| Incorrect readings | Ensure ADC reference voltage is **set correctly** |
| No ADC response | Check if **ADC is initialized** in code |
| AVR not detected | Ensure **drivers for USBasp** are installed |

---

## **🛠️ Future Improvements**  
✅ **Support Fahrenheit conversion (`°F = °C × 1.8 + 32`)**  
✅ **Add temperature threshold alerts (e.g., LED indicator)**  
✅ **Implement EEPROM storage for temperature history**  
