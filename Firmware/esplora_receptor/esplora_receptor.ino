#include "init.h"
 
/* Funcao de setup */
void setup(){
	init_disp_lora();       
	ConfigLEDS();
}
 
/* Programa principal */
void loop() 
{
	read_packet();
	show_display();
}