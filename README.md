# Password-Based Door Lock System  

This repository contains the design, implementation, and documentation of a password-based door lock system. The system enhances security by using a keypad for password entry, a microcontroller for validation, and an electric lock for access control. Incorrect attempts trigger notifications, making it suitable for residential and commercial applications.

---

## Overview  

Traditional lock-and-key systems have inherent security risks. This project addresses those limitations with a digital solution that is secure, user-friendly, and economical. The system allows access via a correct password entered on a keypad and displays real-time feedback on a 16x2 LCD.  

---

## Features  

- **Password Authentication**: Validates password input for access.  
- **Access Notifications**: Sends a notification to the owner after three incorrect attempts.  
- **User Interface**: Guides the user with an LCD display and keypad input.  
- **Secure and Reliable**: Implements encryption for password storage and validation.  
- **Scalable Design**: Easily extendable with additional features like biometrics or remote access.  

---

## Components  

### Hardware:  
- **Microcontroller**: ATMEGA328P  
- **Input Devices**: 4x4 Keypad  
- **Output Devices**: 16x2 LCD display, Electric lock, Servo motor  
- **Communication**: GSM module  
- **Power Source**: 5V regulated power supply  

### Software:  
- Programmed in C++ for embedded systems  
- Password handling, input validation, and lock control logic  

---

## How It Works  

1. **Password Entry**: The user enters a password using the 4x4 keypad.  
2. **Verification**: The system checks the input against a stored password.  
3. **Access Control**:  
   - Correct password: Unlocks the electric lock and activates the servo motor.  
   - Incorrect password: Denies access and displays an error message.  
   - Three consecutive wrong attempts: Sends an alert to the owner's phone via GSM.  
4. **Reset and Re-entry**: The system resets for new input after each attempt.  

---

## Challenges  

- Ensuring hardware-software integration for seamless functionality  
- Addressing timing and synchronization between components  
- Implementing secure password storage and efficient power management  

