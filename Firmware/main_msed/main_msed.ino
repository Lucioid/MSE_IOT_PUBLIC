#include "init.h"
void publishMessage(String AWS_IOT_PUBLISH_TOPIC, String keys, String values);
void setup() {
  
  init_display(); 
  get_credentials();
  config_topics();
  yield();
  ConfigLEDS();
		Serial.println("debug");
  connect_wifi();
  connectAWS();
}

void loop() {
  if(read_packet()){
    liga_blue();
    extract_values(packet);
    if (!client.connected())  {
      liga_red();
      reconecta_wifi();
      connectAWS();
    }else { 
      client.loop();
      publishMessage(TOPIC_PUB_STATUS, "distancia", packet);
    }
  }
  if (client.connected()){
    if(luz_azul){
      liga_green();
    }
  }else{
    liga_red();
    reconecta_wifi();
    connectAWS();
  }
	show_display();
  delay(200);
}
