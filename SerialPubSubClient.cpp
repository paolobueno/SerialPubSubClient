#include "SerialPubSubClient.h"
PubSubClient::PubSubClient(MQTT_CALLBACK_SIGNATURE) {
  setCallback(callback);
}
PubSubClient::PubSubClient(IPAddress ip, uint16_t port, MQTT_CALLBACK_SIGNATURE, Client& client) {
  setCallback(callback);
}

PubSubClient::PubSubClient(const char* domain, uint16_t port, MQTT_CALLBACK_SIGNATURE, Client& client) {
  setCallback(callback);
}

PubSubClient& PubSubClient::setCallback(MQTT_CALLBACK_SIGNATURE) {
  this->callback = callback;
  return *this;
}

boolean PubSubClient::connect(const char* id) {
  return true;
}

boolean PubSubClient::connect(const char* id, const char* user, const char* pass) {
  return true;
}

boolean PubSubClient::publish(const char* topic, const char* payload) {
  return publish(topic, payload, false);
}

boolean PubSubClient::publish(const char* topic, const char* payload, boolean retained) {
  Serial.print("Publishing to topic :"); Serial.println(topic);
  Serial.print("payload: "); Serial.println(payload);
  Serial.print("retained: "); Serial.println(retained);
  return true;
}

boolean PubSubClient::subscribe(const char* topic, uint8_t qos) {
  Serial.print("Subscribing to topic: "); Serial.print(topic); Serial.print(" with QoS "); Serial.println(qos);
  return true;
}

boolean PubSubClient::subscribe(const char* topic) {
  return subscribe(topic, 0);
}

boolean PubSubClient::loop() {
  if(Serial.available()) {
    while (Serial.available()) {
      String topic = Serial.readStringUntil('|');
      String payload = Serial.readStringUntil('\n');
      Serial.print("Receiving message on topic "); Serial.println(topic);
      Serial.print("payload: "); Serial.println(payload);
      if (this->callback) {
        this->callback(topic.c_str(), payload.c_str(), payload.length());
      }
    }
  }
  return connected();
}

boolean PubSubClient::connected() {
  return !!Serial;
}

void PubSubClient::disconnect() {
}

int state() {
  return 0;
}
