
### **📌 Project Name: Electronic Voting Machine Using AVR**
This project implements a **simple electronic voting system** on an **AVR microcontroller** using **push buttons for voting** and an **LCD display for results**. The system allows users to vote for four candidates (A, B, C, D), and results are displayed in real-time.

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
The **electronic voting machine (EVM)** allows users to **cast votes** by pressing dedicated **buttons** for candidates **A, B, C, and D**. The LCD display keeps track of votes and updates in real-time. A **reset button** is also included to reset vote counts.

---

## **✨ Features**
✅ Supports **four candidates (A, B, C, D)**  
✅ Displays real-time **vote counts on LCD**  
✅ **Reset button** to clear votes and restart  
✅ **Debouncing delay** to prevent false counts  
✅ Simple **button-based** input for easy voting  

---

## **🛠️ Hardware Requirements**
- **ATmega32** (or any AVR microcontroller)  
- **Push Buttons (5 pcs.)** (For candidates & reset)  
- **16x2 LCD Display** (For vote count display)  
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
- **Push buttons** connected to **PORTB (PB3 - PB7)**  
- **LCD** connected to **PORTD**  
- **Microcontroller** runs at **8MHz**

💡 **A full circuit diagram can be found in the `docs/` folder.**

---

## **⚙️ How It Works**
1. **Voting Begins:** Each candidate has a dedicated **button** (PB3 - PB6).  
2. **User Votes:** Pressing a button increases the vote count for that candidate.  
3. **Display Updates:** The LCD updates the vote count immediately.  
4. **Reset Function:** A reset button (PB7) clears all votes.  

---

## **🛠 Installation & Compilation**
### **🔹 1. Clone the Repository**
```sh
git clone https://github.com/yourusername/AVR_Voting_Machine.git
cd AVR_Voting_Machine
```

### **🔹 2. Open the Project in Atmel Studio**
- Open **Atmel Studio**  
- Load the **Electronic_voting_machine.c** file  

### **🔹 3. Compile & Upload**
#### **Using AVRDUDE (Command Line)**
```sh
avr-gcc -mmcu=atmega32 -Os Electronic_voting_machine.c -o voting_machine.hex
avrdude -c usbasp -p m32 -U flash:w:voting_machine.hex:i
```

#### **Using Atmel Studio**
- Click **Build** → **Compile**
- Click **Tools** → **Program Device** → **Upload**

---

## **📁 Code Structure**
```
📂 AVR_Voting_Machine
│── 📁 src
│   ├── Electronic_voting_machine.c  # Main program logic
│   ├── LCD.c                        # LCD display functions
│   ├── LCD.h                        # LCD header file
│   ├── button.c                     # Button handling functions
│   ├── button.h                     # Button header file
│── 📁 docs
│   ├── circuit_diagram.png          # Circuit diagram
│   ├── README.md                    # Project documentation
│── 📁 bin
│   ├── voting_machine.hex           # Compiled HEX file
│── 📁 simulation
│   ├── voting_machine.pdsprj        # Proteus simulation file
│── README.md                        # This file
```

---

## **📌 Usage**
1. **Power on the system** → LCD initializes.  
2. **Press a candidate's button** (`A`, `B`, `C`, `D`) to cast a vote.  
3. **The vote count appears** and updates on the LCD.  
4. **Press the reset button (`PB7`)** to clear votes.  

### **Example Voting Results**
| Action  | LCD Output  |
|--------|------------|
| Press `A` | `A=1 B=0 C=0 D=0` |
| Press `B` twice | `A=1 B=2 C=0 D=0` |
| Press `C` | `A=1 B=2 C=1 D=0` |
| Press `D` | `A=1 B=2 C=1 D=1` |
| Press Reset | `A=0 B=0 C=0 D=0` |

---

## **❗ Troubleshooting**
| Issue | Solution |
|-------|----------|
| LCD not displaying | Check **VCC & GND connections** and **10kΩ potentiometer** |
| No button response | Ensure buttons are **connected to PORTB** properly |
| Incorrect vote counts | Check button debounce delay (_increase delay if necessary_) |
| AVR not detected | Ensure **drivers for USBasp** are installed |

---

## **🛠️ Future Improvements**
✅ **Secure voting using RFID authentication**  
✅ **Display winner automatically after voting ends**  
✅ **Store vote count in EEPROM to prevent resets**  

