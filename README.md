# Wi-Fi-Enabled Wristwatch with OLED Display

## Overview
This project involves creating a wristwatch using an **ESP32 WROOM** module and an **OLED display**. The watch connects to Wi-Fi and retrieves real-time data from NTP (Network Time Protocol) servers to display the current time and date.

## Features
- **Wi-Fi Connectivity**: Automatically connects to Wi-Fi for time synchronization.
- **NTP Time Sync**: Retrieves real-time data from NTP servers.
- **OLED Display**: Shows current time and date with periodic updates.
- **Compact Design**: Suitable for wearable applications.

## Components
- **ESP32 WROOM Module**
- **128x32 OLED Display**
- **Wi-Fi & NTP Services**

## How It Works
1. Connect the ESP32 to a Wi-Fi network.
2. Sync with NTP servers to get accurate time.
3. Display the current date and time on the OLED screen.
4. Updates occur every few seconds.

## Installation
1. Clone the repository.
2. Upload the provided code to the ESP32 using the Arduino IDE.
3. Connect to the specified Wi-Fi and watch the time update in real-time.

## License
This project is licensed under the MIT License.
