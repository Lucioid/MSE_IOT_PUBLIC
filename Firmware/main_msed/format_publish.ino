// A funcao Format_publish prepara as strings chaves e valores concatenando as variáveis para enviá-las a funcao publishMessage()
void publishMessage(String AWS_IOT_PUBLISH_TOPIC, String keys, String values);
// void format_publish(){
// 	String chaves = "status,teste,debug";
// 	chaves += ",outra_chave"; 
// 	String valores = "status_val,teste_val,debug_val";
// 	valores += ",outra_chave_val";
// 	publishMessage(TOPIC_PUB_STATUS, chaves, valores);
// }

void publishMessage(String AWS_IOT_PUBLISH_TOPIC,  String keys,  String values){
  yield();
  Serial.println("entrando em publish");
	StaticJsonDocument<200> doc;

  // ---- Explode das strings keys e values e atribuicao a objeto json doc -----
  int pos_key = 0;
  int pos_val = 0;
  int pos_ini = 0;
  String key_sub;
  String val_sub;
		while(keys.length() != 0)
	{
      pos_key = keys.indexOf(',');
      pos_val = values.indexOf(',');
      key_sub = keys.substring(pos_ini, pos_key);
      val_sub = values.substring(pos_ini, pos_val);
			doc[key_sub] = val_sub;
      keys.remove(0, key_sub.length()+1);
      values.remove(0, val_sub.length()+1);
      Serial.print("Estados das strings nessa rodada:");
      
      Serial.println(keys);
      Serial.println(values);
		
	}
  // ---------------------------------------
  char jsonBuffer[512];
  serializeJson(doc, jsonBuffer); // print to client
	#ifdef DEBUG
		Serial.println(String(jsonBuffer));
	#endif
  client.publish(AWS_IOT_PUBLISH_TOPIC.c_str(), jsonBuffer);
}