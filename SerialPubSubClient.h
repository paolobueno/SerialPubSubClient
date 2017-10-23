#include <Arduino.h>
#include <Serial.h>
#include "Client.h"
#include "Stream.h"
#ifndef PubSubClient_h
#define PubSubClient_h

#define MQTT_CALLBACK_SIGNATURE void (*callback)(char*, uint8_t*, unsigned int)

class PubSubClient {
private:
	callback;
public:
   PubSubClient();
   PubSubClient(IPAddress, uint16_t, MQTT_CALLBACK_SIGNATURE,Client& client);
   PubSubClient(uint8_t *, uint16_t, MQTT_CALLBACK_SIGNATURE,Client& client);
   PubSubClient(uint8_t *, uint16_t, MQTT_CALLBACK_SIGNATURE,Client& client, Stream&);
   PubSubClient(const char*, uint16_t, Client& client);
   PubSubClient(const char*, uint16_t, Client& client, Stream&);
   PubSubClient(const char*, uint16_t, MQTT_CALLBACK_SIGNATURE,Client& client);
   PubSubClient(const char*, uint16_t, MQTT_CALLBACK_SIGNATURE,Client& client, Stream&);

   PubSubClient& setCallback(MQTT_CALLBACK_SIGNATURE);
   PubSubClient& setClient(Client& client);
   PubSubClient& setStream(Stream& stream);

   boolean connect(const char* id);
   boolean connect(const char* id, const char* user, const char* pass);
   void disconnect();
   boolean publish(const char* topic, const char* payload);
   boolean publish(const char* topic, const char* payload, boolean retained);
   boolean subscribe(const char* topic);
   boolean subscribe(const char* topic, uint8_t qos);
   boolean unsubscribe(const char* topic);
   boolean loop();
   boolean connected();
   int state();
};


#endif
