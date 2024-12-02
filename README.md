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

