#include "libraries.h"
String str;
String DEVICE_ID = "1";
String SSID1 = "wifi_mse";
String PWD1 = "gfjffl9898";
String SSID2 = "wifi_mse2";
String PWD2 = "gfjffl9898";
String ADM_COD = "998850";
String HOSTNAME_OTA = "msed-" + String(DEVICE_ID);
String PREFIX_TOPIC = "msed/viabr";


void setup(){
    Serial.begin(9600);
    EEPROM.begin(1024);
    int eepromOffset = 0;
    int fimstr1 = set_EEPROM(eepromOffset, DEVICE_ID);
    int fimstr2 = set_EEPROM(fimstr1, SSID1);
    int fimstr3 = set_EEPROM(fimstr2, PWD1);
    int fimstr4 = set_EEPROM(fimstr3, SSID2);
    int fimstr5 = set_EEPROM(fimstr4, PWD2);
    int fimstr6 = set_EEPROM(fimstr5, ADM_COD);
    int fimstr7 = set_EEPROM(fimstr6, HOSTNAME_OTA);
    set_EEPROM(fimstr7, PREFIX_TOPIC);
    EEPROM.commit();

    // String str1 = "sizeof DEVICE_ID: " + String(sizeof(DEVICE_ID));
    // String str2 = "sizeof SSID1: " + String(sizeof(SSID1));
    // String str3 = "sizeof PWD1: " + String(sizeof(PWD1));
    // String str4 = "sizeof SSID2: " + String(sizeof(SSID2));
    // String str5 = "sizeof PWD2: " + String(sizeof(PWD2));
    // String str6 = "sizeof ADM_COD: " + String(sizeof(ADM_COD));
    // String str7 = "sizeof HOSTNAME_OTA: " + String(sizeof(HOSTNAME_OTA));

}

void loop(){

		int newStr1AddrOffset = get_EEPROM(0, &DEVICE_ID);
		int newStr2AddrOffset = get_EEPROM(newStr1AddrOffset, &SSID1);
		int newStr3AddrOffset = get_EEPROM(newStr2AddrOffset, &PWD1);
		int newStr4AddrOffset = get_EEPROM(newStr3AddrOffset, &SSID2);
		int newStr5AddrOffset = get_EEPROM(newStr4AddrOffset, &PWD2);
		int newStr6AddrOffset = get_EEPROM(newStr5AddrOffset, &ADM_COD);
		int newStr7AddrOffset = get_EEPROM(newStr6AddrOffset, &HOSTNAME_OTA);
    get_EEPROM(newStr7AddrOffset, &PREFIX_TOPIC);

    Serial.println("Strings armazenadas: ");
    Serial.println(DEVICE_ID);
    Serial.println(SSID1);
    Serial.println(PWD1);
    Serial.println(SSID2);
    Serial.println(PWD2);
    Serial.println(ADM_COD);
    Serial.println(HOSTNAME_OTA);
    Serial.println(PREFIX_TOPIC);
    Serial.println("\n\n");
    delay(5000);
}

int set_EEPROM(int addrOffset, const String &strToWrite) {
  byte len = strToWrite.length();
  EEPROM.write(addrOffset, len);
  for (int i = 0; i < len; i++)
  {
    EEPROM.write(addrOffset + 1 + i, strToWrite[i]);
  }
  return addrOffset + 1 + len;
  EEPROM.commit();

}


int get_EEPROM(int addrOffset, String *strToRead)
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
