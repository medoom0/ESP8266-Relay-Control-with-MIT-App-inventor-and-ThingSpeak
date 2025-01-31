# ESP8266 Relay Control with MIT App Inventor & ThingSpeak
## Project Overview
This project allows users to remotely control a relay connected to an ESP8266 module using a custom-built MIT App Inventor Android app. The ESP8266 communicates with ThingSpeak, where it reads a field value to trigger the relay. The Android app updates the ThingSpeak field, enabling wireless relay activation.
## Features

- ✅ **Remote Relay Control**: Toggle the relay ON/OFF from anywhere using an Android app.
- ✅ **WiFi-Based Communication**: Uses ESP8266 to connect to the internet.
- ✅ **Cloud Integration**: ThingSpeak acts as a bridge between the app and the ESP8266.
- ✅ **Feedback Mechanism**: The ESP8266 reads the ThingSpeak field value and updates the relay accordingly.

## Components & Requirements
### Hardware Components

- ESP8266 (NodeMCU) WiFi Module
- Relay Module (5V or 3.3V compatible)
- Power Supply (5V/2A for ESP8266 & Relay)
- Connecting Wires

### Software & Platforms

- MIT App Inventor (for building the Android app)
- Arduino IDE (for programming the ESP8266)
- ThingSpeak (for cloud-based communication)

## Setup & Configuration
### 1️⃣ Create a ThingSpeak Channel

1. Go to [ThingSpeak](https://thingspeak.com) and sign in.
2. Click "New Channel" and create a field (Field 1) to store relay control data.
3. Note the Channel ID, Read API Key, and Write API Key.

### 2️⃣ Flash ESP8266 with Arduino Code

1. Install the ESP8266 board package in the Arduino IDE.
2. Install the ThingSpeak and ESP8266WiFi libraries.
3. Upload the following Arduino Sketch to your ESP8266:
### 2️⃣ Replace with your WiFi Credentials
```cpp
const char* SSID = "Your_WiFi_Name";  
const char* PASSWORD = "Your_WiFi_Password";  
```