void get_credentials(){

	EEPROM.begin(1024);

	int newStr1AddrOffset = readStringFromEEPROM(0, &DEVICE_ID);
	int newStr2AddrOffset = readStringFromEEPROM(newStr1AddrOffset, &SSID1);
	int newStr3AddrOffset = readStringFromEEPROM(newStr2AddrOffset, &PWD1);
	int newStr4AddrOffset = readStringFromEEPROM(newStr3AddrOffset, &SSID2);
	int newStr5AddrOffset = readStringFromEEPROM(newStr4AddrOffset, &PWD2);
	int newStr6AddrOffset = readStringFromEEPROM(newStr5AddrOffset, &ADM_COD);
	int newStr7AddrOffset = readStringFromEEPROM(newStr6AddrOffset, &HOSTNAME_OTA);
	readStringFromEEPROM(newStr7AddrOffset, &PREFIX_TOPIC);
	THINGNAME = "MSE-" + DEVICE_ID;

	#ifdef DEBUG
		Serial.println("Strings armazenadas: ");
		Serial.println(DEVICE_ID);
		Serial.println(SSID1);
		Serial.println(PWD1);
		Serial.println(SSID2);
		Serial.println(PWD2);
		Serial.println(ADM_COD);
		Serial.println(HOSTNAME_OTA);
		Serial.println(PREFIX_TOPIC);
		Serial.println(THINGNAME);
	#endif
	EEPROM.end();
}

int readStringFromEEPROM(int addrOffset, String *strToRead)
{
  int newStrLen = EEPROM.read(addrOffset);
  char data[newStrLen + 1];
  for (int i = 0; i < newStrLen; i++)
  {
	data[i] = EEPROM.read(addrOffset + 1 + i);
  }
  data[newStrLen] = '\0'; // !!! NOTE !!! Remove the space between the slash "/" and "0" (I've added a space because otherwise there is a display bug)
  *strToRead = String(data);
  return addrOffset + 1 + newStrLen;
}

void config_topics(){
	TOPIC_SUB_UPDATE = PREFIX_TOPIC + '/' + DEVICE_ID + '/' + "update";
	TOPIC_PUB_STATUS = PREFIX_TOPIC + '/' + DEVICE_ID + '/' + "status";

	#ifdef DEBUG
		Serial.println(TOPIC_SUB_UPDATE);
		Serial.println(TOPIC_PUB_STATUS);
	#endif

}

