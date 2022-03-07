
 #include "init.h"

/* Funcao de setup */
void setup() {
	init_display();
	init_sensors();

}
 
/* Programa principal */
void loop() 
{

	// umid_percentual = read_humidity();
	distance = read_distance();
	if(abs(distance-last_distance) > 20 ){
		Serial.println("Diferenca: ");
		Serial.println(distance-last_distance);
		// packet = String(umid_percentual) + "," + String(distance);
		packet = String(distance);
		send_packet(packet);
	}
	packet = String(distance);
	// packet = String(umid_percentual) + "," + String(distance);
	delay(1000);
	show_display();
	last_distance = distance;	 
}
