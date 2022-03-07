void connect_wifi(){
	wifiMulti.addAP(SSID1.c_str(), PWD1.c_str());
	wifiMulti.addAP(SSID2.c_str(), PWD2.c_str());
	wifiMulti.addAP("ssid_from_AP_3", "your_password_for_AP_3");
	#ifdef DEBUG
    Serial.println("Connecting Wifi...");
	#endif  

	if(wifiMulti.run() == WL_CONNECTED) {
		#ifdef DEBUG
			Serial.println("");
			Serial.println("WiFi connected");
			Serial.println("IP address: ");
			Serial.println(WiFi.localIP());
		#endif  
	}
	// WiFi.mode(WIFI_STA);
  // WiFi.begin(WIFI_SSID, WIFI_PASSWORD);


  // while (WiFi.status() != WL_CONNECTED){
  //   delay(500);
  //   Serial.print(".");
  // }

}

void reconecta_wifi(){
	if(wifiMulti.run() != WL_CONNECTED) {
		Serial.println("WiFi not connected!");
		connect_wifi();
		delay(500);
	}
	// if(WiFi.status() != WL_CONNECTED){
  //   delay(500);
  //   Serial.print(".");
	// 	connect_wifi();
  // }
}
