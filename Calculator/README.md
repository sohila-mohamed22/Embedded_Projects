
### **📌 Project Name: AVR Calculator Using Keypad & LCD**
This project implements a **simple calculator** on an **AVR microcontroller** using a **4x4 keypad** for input and an **LCD display** for output. The calculator supports **addition, subtraction, multiplication, and division**.

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
The AVR-based calculator allows users to perform **basic arithmetic operations** by pressing keys on a **4x4 keypad**. The numbers and results are displayed on a **16x2 LCD**. It continuously waits for input, processes the operation, and displays the result.

---

## **✨ Features**
✅ Supports **Addition (+), Subtraction (-), Multiplication (*), and Division (/)**  
✅ Displays results on a **16x2 LCD**  
✅ Supports **2-digit operations** (e.g., `12 + 34 = 46`)  
✅ Clears the screen with a **reset button (A key)**  
✅ Displays `"ERROR"` for invalid inputs like `division by zero`  

---

## **🛠️ Hardware Requirements**
- **ATmega32** (or any AVR microcontroller)  
- **4x4 Keypad** (to input numbers and operations)  
- **16x2 LCD Display**  
- **10kΩ Potentiometer** (for LCD contrast control)  
- **Crystal Oscillator (8MHz)**  
- **Capacitors (22pF)**  
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
- **Keypad** connected to **PORTC**
- **LCD** connected to **PORTD**  
- **Microcontroller** runs at **8MHz**

💡 **A full circuit diagram can be found in the `docs/` folder.**

---

## **⚙️ How It Works**
1. **User Inputs:** Numbers and operations are entered using the **keypad**.  
2. **Processing:** The microcontroller stores the inputs and detects valid operations.  
3. **Calculation:** The arithmetic operation is performed, and the result is calculated.  
4. **Display:** The result is displayed on the **16x2 LCD**.  
5. **Error Handling:** If an invalid input is detected, the LCD displays `"ERROR"`.

---

## **🛠 Installation & Compilation**
### **🔹 1. Clone the Repository**
```sh
git clone https://github.com/yourusername/AVR_Calculator.git
cd AVR_Calculator
```

### **🔹 2. Open the Project in Atmel Studio**
- Open **Atmel Studio**  
- Load the **calculator.c** file  

### **🔹 3. Compile & Upload**
#### **Using AVRDUDE (Command Line)**
```sh
avr-gcc -mmcu=atmega32 -Os calculator.c -o calculator.hex
avrdude -c usbasp -p m32 -U flash:w:calculator.hex:i
```

#### **Using Atmel Studio**
- Click **Build** → **Compile**
- Click **Tools** → **Program Device** → **Upload**

---

## **📁 Code Structure**
```
📂 AVR_Calculator
│── 📁 src
│   ├── calculator.c        # Main program logic
│   ├── LCD.c               # LCD display functions
│   ├── LCD.h               # LCD header file
│   ├── key_pad.c           # Keypad scanning functions
│   ├── key_pad.h           # Keypad header file
│── 📁 docs
│   ├── circuit_diagram.png # Circuit diagram
│   ├── README.md           # Project documentation
│── 📁 bin
│   ├── calculator.hex      # Compiled HEX file
│── 📁 simulation
│   ├── calculator.pdsprj   # Proteus simulation file
│── README.md               # This file
```

---

## **📌 Usage**
1. **Power on the system** → LCD initializes.  
2. **Enter numbers** using the keypad.  
3. **Press an operator** (`+`, `-`, `*`, `/`).  
4. **Enter the second number**.  
5. **Press `=`** → The result appears on the LCD.  
6. **To clear** the display, press **`A` (Reset)**.

### **Example Calculations**
| Input  | Output  |
|--------|--------|
| `5 + 3 =` | `8` |
| `9 - 2 =` | `7` |
| `4 * 6 =` | `24` |
| `8 / 2 =` | `4` |
| `7 / 0 =` | `ERROR` |

---

## **❗ Troubleshooting**
| Issue | Solution |
|-------|----------|
| LCD not displaying | Check **VCC & GND connections** and **10kΩ potentiometer** |
| No keypad response | Ensure keypad is **connected to PORTC** properly |
| Incorrect calculations | Check array indexing and **ASCII conversion (`-48`)** |
| AVR not detected | Ensure **drivers for USBasp** are installed |

---

## **🛠️ Future Improvements**
✅ **Support more than 2-digit numbers**  
✅ **Implement floating-point calculations**  
✅ **Optimize the keypad debounce handling**  
