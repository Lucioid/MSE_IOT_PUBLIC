int read_distance(){
    // Limpe o trigPin configurando-o como LOW:
  digitalWrite(trigPin, LOW);
  
  delayMicroseconds(50);
  // Acione o sensor definindo o trigPin alto por 10 microssegundos:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(50);
  digitalWrite(trigPin, LOW);
  
  // Leia o echoPin. pulseIn() retorna a duração (comprimento do pulso) em microssegundos:
  duration = pulseIn(echoPin, HIGH);
  
  // Calcule e retorne a distância:
  return duration*0.034/2;
}