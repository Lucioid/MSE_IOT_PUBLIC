bool read_packet(){
	/* Verifica se chegou alguma informação do tamanho esperado */
	packet_size = LoRa.parsePacket();
	informacao_recebida = "";
     
	if (packet_size ){
		Serial.print("[LoRa Receiver] Há dados a serem lidos");
			
		/* Recebe os dados conforme protocolo */               
		 while (LoRa.available()) {
      informacao_recebida += (char)LoRa.read();
    }  
		packet = informacao_recebida; 
		// while (LoRa.available()) 
		// {
		// 		byte_recebido = (char)LoRa.read();
		// 		*ptInformaraoRecebida = byte_recebido;
		// 		ptInformaraoRecebida++;
		// }

		/* Escreve RSSI de recepção e informação recebida */
		lora_rssi = LoRa.packetRssi();
		// extract_values(packet);
		return true;
	}else{
		return false;
	}
}