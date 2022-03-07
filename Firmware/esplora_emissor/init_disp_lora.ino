/* Funcao: inicializa comunicacao com o display OLED
 * Parametros: nenhnum
 * Retorno: nenhnum
*/ 


void display_init(void)
{
	if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) 
	{
		Serial.println("[LoRa Receiver] Falha ao inicializar comunicacao com OLED");        
	}
	else
	{
		Serial.println("[LoRa Receiver] Comunicacao com OLED inicializada com sucesso");
	
		/* Limpa display e configura tamanho de fonte */
		display.clearDisplay();
		display.setTextSize(1);
		display.setTextColor(WHITE);
	}
}

/* Funcao: inicia comunicação com chip LoRa
 * Parametros: nenhum
 * Retorno: true: comunicacao ok
 *          false: falha na comunicacao
*/
bool init_comunicacao_lora(void)
{
	bool status_init = false;
	Serial.println("[LoRa Sender] Tentando iniciar comunicacao com o radio LoRa...");
	SPI.begin(SCK_LORA, MISO_LORA, MOSI_LORA, SS_PIN_LORA);
	LoRa.setPins(SS_PIN_LORA, RESET_PIN_LORA, LORA_DEFAULT_DIO0_PIN);
		
	if (!LoRa.begin(BAND)) 
	{
		Serial.println("[LoRa Sender] Comunicacao com o radio LoRa falhou. Nova tentativa em 1 segundo...");        
		delay(1000);
		status_init = false;
	}
	else
	{
		/* Configura o ganho do receptor LoRa para 20dBm, o maior ganho possível (visando maior alcance possível) */
		LoRa.setTxPower(HIGH_GAIN_LORA); 
		Serial.println("[LoRa Sender] Comunicacao com o radio LoRa ok");
		status_init = true;
	}

	return status_init;
}
 

void init_display(){
    /* Configuracao da I²C para o display OLED */
	Wire.begin(OLED_SDA_PIN, OLED_SCL_PIN);  

	/* Display init */
	display_init();

	/* Print message telling to wait */
	display.clearDisplay();    
	display.setCursor(0, OLED_LINE1);
	display.print("Aguarde...");
	display.display();
	
	Serial.begin(DEBUG_SERIAL_BAUDRATE);   
	while (!Serial);
    /* Tenta, até obter sucesso, comunicacao com o chip LoRa */
	while(init_comunicacao_lora() == false); 
}