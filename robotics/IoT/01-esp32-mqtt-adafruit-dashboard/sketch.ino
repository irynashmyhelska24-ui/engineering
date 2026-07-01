#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// ─────────────────────────────────────────
// 👇 Твої дані з Adafruit IO
#define AIO_USERNAME    "------------"
#define AIO_KEY         "------------"
// ─────────────────────────────────────────


#define WIFI_SSID       "Wokwi-GUEST"
#define WIFI_PASSWORD   ""

#define AIO_SERVER      "io.adafruit.com"
#define AIO_PORT        1883

// Топіки фідів — формат: username/feeds/feedname
#define FEED_TEMP       AIO_USERNAME "/feeds/temperature"
#define FEED_HUM        AIO_USERNAME "/feeds/humidity"

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
WiFiClient espClient;
PubSubClient mqtt(espClient);

void connectWiFi() {
  Serial.print("Підключаємось до Wi-Fi");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ Wi-Fi підключено!");
}

void connectMQTT() {
  mqtt.setServer(AIO_SERVER, AIO_PORT);
  while (!mqtt.connected()) {
    Serial.print("Підключаємось до Adafruit IO...");
    if (mqtt.connect("esp32-iot-lab", AIO_USERNAME, AIO_KEY)) {
      Serial.println(" ✅ Підключено!");
    } else {
      Serial.print(" ❌ Помилка, код: ");
      Serial.println(mqtt.state());
      delay(3000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  connectWiFi();
  connectMQTT();
}

void loop() {
  if (!mqtt.connected()) connectMQTT();
  mqtt.loop();

  float temperature = dht.readTemperature();
  float humidity    = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("❌ Помилка читання DHT22");
    delay(2000);
    return;
  }

  char tempStr[8], humStr[8];
  dtostrf(temperature, 4, 2, tempStr);
  dtostrf(humidity,    4, 2, humStr);

  mqtt.publish(FEED_TEMP, tempStr);
  mqtt.publish(FEED_HUM,  humStr);

  Serial.printf("📤 Температура: %s°C | Вологість: %s%%\n", tempStr, humStr);

  delay(5000);
}
