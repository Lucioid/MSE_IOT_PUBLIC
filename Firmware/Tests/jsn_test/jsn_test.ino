/* Sketch de exemplo do Arduino para controlar um sensor de distância ultrassônico JSN-SR04T com o Arduino. Nenhuma biblioteca necessária. */
// Defina o Trig e o pino de eco:
#define trigPin D3
#define echoPin D2
// Defina as variáveis:
long duration;
int distance;
void setup() {  
  // Definir entradas e saídas
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(LED_BUILTIN,OUTPUT);

  
  // Comece a comunicação serial a uma taxa de transmissão de 9600:
  Serial.begin(9600);
}
void loop() {
  distance = read_distance();
  
  // Imprima a distância no Monitor Serial
  Serial.print("Distancia = ");
  Serial.print(distance);
  Serial.println(" cm");
  if(distance <= 100){
    digitalWrite(LED_BUILTIN,HIGH);
  }else{
    digitalWrite(LED_BUILTIN,LOW);
  }
  
  delay(1000);
}