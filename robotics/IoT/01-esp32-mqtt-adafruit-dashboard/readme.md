ESP32 → MQTT → Adafruit IO (Virtual IoT Pipeline)

OVERVIEW

This introductory lab demonstrates a complete cloud-connected IoT data pipeline using a virtual ESP32 microcontroller.
The project simulates an ESP32 equipped with a DHT22 temperature and humidity sensor, publishes telemetry via the MQTT protocol, and visualizes real-time data using Adafruit IO dashboards.
Although the hardware is virtual, the communication architecture is identical to what would be used on a physical ESP32 device.

OBJECTIVES

Learn the basic architecture of an IoT telemetry pipeline.
Connect an ESP32 device to a cloud MQTT broker.
Publish sensor measurements.
Visualize live telemetry using cloud dashboards.
Understand the relationship between embedded firmware and cloud services.

TECHNOLOGIES

- ESP32 (simulated)
- DHT22 sensor
- MQTT
- Adafruit IO
- Wokwi Simulator

ARCHITECTURE

Virtual DHT22
      │
      ▼
    ESP32
      │
 MQTT Publish
      │
      ▼
 Adafruit IO Feeds
      │
      ▼
 Real-time Dashboard

 WHAT I UMPLEMENTED
 
1. Cloud account setup
  - Created an Adafruit IO account
  - Generated authentication credentials
  - Retrieved:
    - Username
    - Active API Key

2. MQTT feeds

Created two telemetry feeds:
  - temperature
  - humidity
These feeds receive measurements from the ESP32.

3. ESP32 configuration

Configured the provided ESP32 firmware by replacing placeholder credentials with my own Adafruit IO credentials.

Updated:
  - #define AIO_USERNAME "..."
  - #define AIO_KEY "..."

4. Device simulation

Executed the project inside Wokwi Simulator.

Verified that the virtual ESP32:
  - connected successfully
  - authenticated with Adafruit IO
  - published sensor data every 5 seconds
  
5. Dashboard

Created an Adafruit IO dashboard consisting of:
  - Temperature Line Chart
  - Humidity Gauge
  
Observed real-time updates from the virtual device.

6. Sensor simulation

Modified DHT22 values inside Wokwi during runtime.

Verified that:
  - MQTT messages were transmitted immediately
  - Dashboard values updated in real time

SKILLS PRACTICED

- IoT architecture
- MQTT messaging
- ESP32 cloud connectivity
- Telemetry
- Real-time dashboards
- Embedded device configuration
- Cloud IoT services

KEY TAKEAWAYS
- Learned the complete data flow from sensor to cloud visualization.
- Understood how MQTT enables lightweight communication between embedded devices and cloud platforms.
- Gained hands-on experience configuring IoT credentials and telemetry feeds.
- Observed real-time synchronization between simulated hardware and cloud dashboards.
