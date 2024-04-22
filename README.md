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
   - Create a Blynk account.
   - Go to Developer Zone and click on `New Template`.
   - Give a name and set Hardware to `ESP8266`, connection type WiFi.
   - After creation of New Template, open that template click on `Data Streams` -> `New Datastream` -> `Virtual Pin`.
   - Give the name as `Temperature` and set virtual pin to `V0`. Also set the data type to `double` and MAX value to 100.
   - Again click on `New Datastream` -> `Virtual Pin`.
   - Give the name as `Humidity` and set virtual pin to `V1`. Also set the data type to `double` and MAX value to 100.
   - Again click on `New Datastream` -> `Virtual Pin`.
   - Give the name as `Soil Moisture` and set virtual pin to `V3`. Let the datatype be integer and set MAX value to 100.
   - Go to `Event and Notification` -> `Create Event`.
   - In General Give the `event name`, set the type to `Warning`. Make the below changes in `limit`.
   - `Every 1 message will trigger the event Event will be sent to user only once per 1 minute`.
   - Enable `Show event in Notifications section of mobile app` and `Send event to Timeline`.
   - Go to notification -> `Enable Notifications`.
   - Set `E-MAIL TO` and `PUSH NOTIFICATIONS TO` to `DEVICE OWNER`, and enable `Deliver push notifications as alerts`.
   - Update the event name in the code.
   - Go to `Web Dashboard` and click on `Guage` widget. Choose a datastream for the guage widget (Create 3 Gauge widgets).
   - Now go to `Devices` -> `New Devices` -> `From Template` -> Choose the created template -> Click `Done`.
   - Copy the `BLYNK_TEMPLATE_ID`, `BLYNK_TEMPLATE_NAME`, and `BLYNK_AUTH_TOKEN` and update it in the code.
   - Update the `BLYNK_AUTH_TOKEN`, `ssid`, and `pass` variables in the `app.ino` file with your Blynk authentication token and WiFi credentials.

4. **Upload Code**: Upload the `app.ino` sketch to your ESP8266 board using the Arduino IDE or a similar platform.

5. **Monitor**: Open the Blynk app on your smartphone and monitor the temperature, humidity, and soil moisture levels in real-time.

## Usage

- Once the hardware is set up and the code is uploaded, the device will start monitoring and displaying the temperature, humidity, and soil moisture levels on the LCD display.
- Additionally, the data can be accessed remotely using the Blynk app.

### Images

1. **Circuit Diagram**: [(https://github.com/Anirudhabg/NodeMCU_Based_Soil_and_Weather_data_Monitoring_system/blob/342d7cdd6d77269daf3ae2c31612f1304c4e4c68/Circuit%20Diagram/Circuit%20Diagram.png)]
2. **Web Dashboard Screenshot**: [(https://github.com/Anirudhabg/NodeMCU_Based_Soil_and_Weather_data_Monitoring_system/blob/f32451039ad24289d582c5b8762fdeeb1fd866a5/Application/Web%20Application.png)]
3. **Mobile Application Screenshots**: [(https://github.com/Anirudhabg/NodeMCU_Based_Soil_and_Weather_data_Monitoring_system/blob/342d7cdd6d77269daf3ae2c31612f1304c4e4c68/Application/Mobile%20Application.jpg)]
