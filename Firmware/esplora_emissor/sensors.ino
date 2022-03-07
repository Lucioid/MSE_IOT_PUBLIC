void init_sensors(){
	// Pino umidade
	pinMode(13, OUTPUT);

	//Trig e echo do JSN 
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

// float read_humidity(){
//   umidade = analogRead(humidpin);
// 	umidade = abs(umidade - 4095);
// 	umid_percentual = map(umidade, 0, 2200, 0, 100);
	
// 	return umid_percentual;

// }

float read_distance(){
	// Limpe o trigPin configurando-o como LOW:
  digitalWrite(trigPin, LOW);
  
  delayMicroseconds(50);
  // Acione o sensor definindo o trigPin alto por 10 microssegundos:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(50);
  digitalWrite(trigPin, LOW);
  
  // Leia o echoPin. pulseIn() retorna a duração (comprimento do pulso) em microssegundos:
  duration = pulseIn(echoPin, HIGH);
  
  // Calcule a distância:
  return duration*0.034/2;
}