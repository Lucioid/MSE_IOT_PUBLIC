/* Sketch de exemplo do Arduino para controlar um sensor de distância ultrassônico JSN-SR04T com o Arduino. Nenhuma biblioteca necessária. */
// Defina o Trig e o pino de eco:
#define trigPin 5
#define echoPin 18
// Defina as variáveis:
long duration;
int distance;
void setup() {  
  // Definir entradas e saídas
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(2,OUTPUT);

  
  // Comece a comunicação serial a uma taxa de transmissão de 9600:
  Serial.begin(9600);
}
void loop() {
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
  distance = duration*0.034/2;
  
  // Imprima a distância no Monitor Serial (Ctrl + Shift + M):
  Serial.print("Distancia = ");
  Serial.print(distance);
  Serial.println(" cm");
  if(distance <= 100){
    digitalWrite(2,HIGH);
  }else{
    digitalWrite(2,LOW);
  }
  
  delay(1000);
}