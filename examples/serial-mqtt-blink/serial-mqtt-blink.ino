#ifdef ONLINE
#include <PubSubClient.h>
#else
#include <SerialPubSubClient.h>
#endif

IPAddress MQTT_SERVER(192, 168, 3, 67);
const int MQTT_PORT = 1883;
const byte mac[] = { 0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0x42 };

void callback(char* topic, byte* payload, unsigned int length) {
  digitalWrite(LED_BUILTIN, payload[0] - '0');
}

#include <UIPEthernet.h>
#include <utility/logging.h>
EthernetClient ethClient;

PubSubClient client(MQTT_SERVER, MQTT_PORT, callback, ethClient);
void setup() {
  Serial.begin(9600);
  while(!Serial) {}
  Serial.println("inicio");
  #ifdef ONLINE
  if(Ethernet.begin(mac)) {
    Serial.println(Ethernet.localIP());
  } else {
    Serial.println("DHCP Failed");
  }
  #endif

  if(client.connect("arduino-42")) {
    Serial.println("connected");
    client.subscribe("lampada");
    client.publish("lampada", "0");
  } else {
    Serial.println("Failed to connect to MQTT");
  }
}

void loop() {
  client.loop();
}