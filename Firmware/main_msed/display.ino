void show_display(){
	display.clearDisplay();   
	display.setCursor(0, OLED_LINE1);
	display.print("-> Receptor <-");
	display.setCursor(0, OLED_LINE2);
	display.print("RSSI: ");
	display.println(lora_rssi);
	display.setCursor(0, OLED_LINE3);
	display.print("Informacao: ");
	display.setCursor(0, OLED_LINE4);
	display.println(packet);
	display.setCursor(0, OLED_LINE5);
	display.print("H: "); display.print(humidity); display.print("%");
	display.setCursor(0, OLED_LINE6);
	display.print("D: "); display.print(distance); display.print("m");
	display.display();      
}