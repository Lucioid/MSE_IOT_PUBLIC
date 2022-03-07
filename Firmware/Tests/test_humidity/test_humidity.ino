int umidade;
float umid_percentual;

void setup()
{
 Serial.begin(9600);
 Serial.println("Teste de Sensor de umidade!");
 pinMode(13, OUTPUT);
}
void loop()
{
 umidade = analogRead(4);
 umidade = abs(umidade - 4095);
 umid_percentual = map(umidade, 0, 2200, 0, 100);
 
 Serial.print(Porcento);
 Serial.println("%");
 Serial.println(umidade);
 delay(1000);
}