void extract_values(String informacao_recebida){
	int pos = informacao_recebida.indexOf(',');
	humidity = informacao_recebida.substring(0, pos);
	distance = informacao_recebida.substring(pos+1);
}