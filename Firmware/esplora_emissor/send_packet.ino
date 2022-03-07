void send_packet(String packet){
	/* Envia a informação */
	LoRa.beginPacket();
	// LoRa.write((unsigned char *)&packet, sizeof(packet));
	LoRa.print(packet);
	LoRa.endPacket();
	
}