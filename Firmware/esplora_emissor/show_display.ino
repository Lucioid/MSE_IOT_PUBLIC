void show_display(){
	display.clearDisplay();   
	display.setCursor(0, OLED_LINE1);
	display.print("-> Emissor <-");
	display.setCursor(0, OLED_LINE3);
	display.print("Umidade: ");
	display.print(umid_percentual);
	display.print("%");
	display.setCursor(0, OLED_LINE5);
	display.print("Distancia: ");
	display.print(distance);
	display.print(" m");
	display.setCursor(0, OLED_LINE6);
	display.print("Packet: ");
	display.print(packet);
	display.display();
}