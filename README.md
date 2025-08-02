# Automatic Validation of ATMEL 8051 Testing Board

This project focuses on **software-based validation** of an **AT89C51 development board** using a **Proteus simulation**. It is designed to automatically test various peripherals on the board including:

- ✅ **16x2 LCD Display**
- ✅ **8-bit LED Array**
- ✅ **Buzzer**
- ✅ **On-Board USBasp ISP Programmer**

---

## Project Overview

The system emulates a test environment for verifying the functionality of the AT89C51-based development board by controlling and monitoring the I/O peripherals via software. It simulates user interaction and output verification through Proteus and Keil µVision (C code development).

---

## 💻 Tools & Technologies Used

| Tool              | Purpose                                |
|-------------------|----------------------------------------|
| **Keil µVision**  | Embedded C code development (8051)     |
| **Proteus**       | Virtual simulation of hardware setup   |
| **AT89C51 MCU**   | Target microcontroller (8051 core)     |
| **LCD 16x2**      | Output display for test messages       |
| **LEDs & Buzzer** | Peripheral status indicators           |
| **UART**          | Command line interface (simulated)     |

---

## 📁 Project Structure

/Automatic_Validation_Of_ATMEL_8051_Testing_Board
├── src/
│   ├── main.c               # Main application logic
│   ├── uart.c               # UART communication functions
│   ├── lcd.c                # LCD control functions
│   └── mkeys.c              # Multi-key input handling
|   |__ delay.c
│
├── include/                # Header files
│   ├── lcd.h
│   ├── delay.h
│   ├── uart.h
│   ├── global.h
│   ├── mkeys.h
│   └── 8051.h
│
├── wsp/
│   └── embedded_validation_project.pdsprj  # Proteus simulation project
│
├── images/
│   └── simulation_screenshot.png  # Screenshot from Proteus
│
├── README.md
└── LICENSE

## 🚀 How to Use

### ▶️ 1. Simulate in Proteus
- Open `.pdsprj` in Proteus
- Start simulation
- Interact via virtual terminal (UART)

### 🧪 2. Use the UART Menu
- Choose test options:
  - 1: Test LEDs
  - 2: Test Buzzer
  - 3: Test LCD
  - 4: Exit

### 🛠 3. Program to Hardware (Optional)
- Flash compiled `.hex` to your AT89C51 using USBasp
- Connect LCD, buzzer, LEDs, and UART interface on breadboard/dev board

---

## 📖 Learning Objectives

- Understand peripheral testing automation for embedded systems
- Simulate embedded projects using Proteus
- Implement UART communication in 8051
- Modular C programming for 8051

---

## 🤝 Contributions

Pull requests are welcome! If you’d like to contribute more test cases or add external modules (e.g., relay, sensor testing), feel free to fork and enhance the project.

---

## 📬 Contact

For feedback or queries, open an issue or contact the maintainer at:
**📧 rk.jpr283@gmail.com**

