### **📌 Project Name: Real-Time Clock Using AVR (RTC)**
This project implements a **real-time clock (RTC)** using an **AVR microcontroller**, a **timer interrupt**, a **keypad for manual time setting**, and a **seven-segment display** to show the time in **HH:MM:SS format**.

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
The **real-time clock (RTC)** keeps track of **hours, minutes, and seconds** using an **AVR timer interrupt**. Users can **set the time** using a **keypad**, and the time is displayed on a **seven-segment display** in **HH:MM:SS** format.

---

## **✨ Features**
✅ **Real-time tracking of hours, minutes, and seconds**  
✅ **Manual time setting using a keypad**  
✅ **Seven-segment display output in HH:MM:SS format**  
✅ **Uses Timer2 Overflow Interrupt for accurate timekeeping**  
✅ **Error handling for incorrect time inputs**  

---

## **🛠️ Hardware Requirements**
- **ATmega32** (or any AVR microcontroller)  
- **4x4 Keypad** (for setting the clock)  
- **Seven-segment display (6-digit, multiplexed)**  
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
- **Seven-segment display connected to PORTB**  
- **Keypad connected to PORTD**  
- **Microcontroller runs at 8MHz**  
- **Timer2 used for timekeeping**  

💡 **A full circuit diagram can be found in the `docs/` folder.**  

---

## **⚙️ How It Works**
1. **Timekeeping:**  
   - The **Timer2 Overflow Interrupt** increments the **seconds counter** every **1 second**.  
   - If **seconds reach 60**, they reset to `00` and **minutes increase**.  
   - If **minutes reach 60**, they reset to `00` and **hours increase**.  
   - If **hours reach 24**, they reset to `00`.  

2. **Time Display:**  
   - The **seven-segment display** shows time in **HH:MM:SS format**.  

3. **Time Setting:**  
   - Users press `1` to enter **time setting mode**.  
   - The keypad is used to enter **hours, minutes, and seconds**.  
   - The system validates the input and updates the **RTC values** accordingly.  

4. **Error Handling:**  
   - The system checks if the entered time is **valid** (e.g., **hours < 24, minutes < 60, seconds < 60**).  
   - If invalid, it displays `"ERROR"` and resets the input.  

---

## **🛠 Installation & Compilation**
### **🔹 1. Clone the Repository**
```sh
git clone https://github.com/yourusername/AVR_RTC.git
cd AVR_RTC
```

### **🔹 2. Open the Project in Atmel Studio**
- Open **Atmel Studio**  
- Load the **real_time_clock.c** file  

### **🔹 3. Compile & Upload**
#### **Using AVRDUDE (Command Line)**
```sh
avr-gcc -mmcu=atmega32 -Os real_time_clock.c -o real_time_clock.hex
avrdude -c usbasp -p m32 -U flash:w:real_time_clock.hex:i
```

#### **Using Atmel Studio**
- Click **Build** → **Compile**
- Click **Tools** → **Program Device** → **Upload**  

---

## **📁 Code Structure**
```
📂 AVR_RTC
│── 📁 src
│   ├── real_time_clock.c  # Main program logic
│   ├── LCD.c              # LCD display functions
│   ├── LCD.h              # LCD header file
│   ├── key_pad.c          # Keypad handling functions
│   ├── key_pad.h          # Keypad header file
│   ├── seven_segment.c    # Seven-segment display functions
│   ├── seven_segment.h    # Seven-segment display header file
│   ├── timer.c            # Timer2 overflow interrupt setup
│   ├── timer.h            # Timer header file
│── 📁 docs
│   ├── circuit_diagram.png  # Circuit diagram
│   ├── README.md            # Project documentation
│── 📁 bin
│   ├── real_time_clock.hex   # Compiled HEX file
│── 📁 simulation
│   ├── real_time_clock.pdsprj # Proteus simulation file
│── README.md                # This file
```

---

## **📌 Usage**
1. **Power on the system** → Seven-segment displays `00:00:00`.  
2. **The clock starts running** automatically.  
3. **Press `1` on the keypad** to enter **time-setting mode**.  
4. **Enter hours, minutes, and seconds** using the keypad.  
5. **The system validates the input and updates the time**.  
6. **The new time starts running** and updates in real-time.  

### **Example Time Settings**
| Input  | Display Output |
|--------|---------------|
| `12:45:30` | `12:45:30` |
| `23:59:59` | `23:59:59` |
| `24:00:00` | `ERROR` |
| `12:75:30` | `ERROR` |

---

## **❗ Troubleshooting**
| Issue | Solution |
|-------|----------|
| Seven-segment not displaying | Check **VCC & GND connections** |
| No keypad response | Ensure keypad is **connected properly** to PORTD |
| Incorrect time updates | Check **Timer2 configuration** in code |
| AVR not detected | Ensure **drivers for USBasp** are installed |

---

## **🛠️ Future Improvements**
✅ **Add EEPROM support to retain time after power loss**  
✅ **Implement 12-hour format (AM/PM)**  
✅ **Include RTC module (DS3231) for accuracy**  

