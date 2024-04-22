# IoT Plant Monitoring System

This project provides a simple IoT-based solution for monitoring temperature, humidity, and soil moisture levels of plants using an ESP8266 NodeMCU board, DHT11 sensor, soil moisture sensor, and an LCD display. It utilizes the Blynk platform for real-time data visualization and monitoring.

## Features

- Real-time monitoring of temperature, humidity, and soil moisture levels.
- Automatic warnings when soil moisture levels drop below a specified threshold.
- Integration with the Blynk app for remote monitoring and control.

## Hardware Requirements

- ESP8266 NodeMCU board
- DHT11 temperature and humidity sensor
- Soil moisture sensor
- LCD display (compatible with the LiquidCrystal_I2C library)
- Jumper wires

## Setup Instructions

1. **Clone the Repository**: Clone this repository to your local machine.

2. **Hardware Connections**:
   - Connect the DHT11 sensor to pin D4 of the NodeMCU.
   - Connect the soil moisture sensor to the A0 pin of the NodeMCU.
   - Connect the LCD's SCL pin to the D1 pin of the NodeMCU.
   - Connect the LCD's SDA pin to the D2 pin of the NodeMCU.

3. **Blynk Setup**:
   - Create a Blynk account and project.
   - Obtain the authentication token for your Blynk project.
   - Update the `BLYNK_AUTH_TOKEN`, `ssid`, and `pass` variables in the `plant_monitor.ino` file with your Blynk authentication token and WiFi credentials.

4. **Upload Code**: Upload the `plant_monitor.ino` sketch to your ESP8266 board using the Arduino IDE or a similar platform.

5. **Monitor**: Open the Blynk app on your smartphone and monitor the temperature, humidity, and soil moisture levels in real-time.

## Usage

- Once the hardware is set up and the code is uploaded, the device will start monitoring and displaying the temperature, humidity, and soil moisture levels on the LCD display.
- Additionally, the data can be accessed remotely using the Blynk app.

## Troubleshooting

- If you encounter any issues, ensure that the hardware connections are correct and that the Blynk authentication token and WiFi credentials are properly configured.

## Contributing

Contributions are welcome! If you have any ideas for improvement or new features, feel free to open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).
