#include <Ultrasonic.h>

#define pinoTrig 9
#define pinoEcho 8

int distanciaMinima = 200;
int distanciaMaxima = 50;

//inicializa o sensor ultrassonico
Ultrasonic ultrasonic(pinoTrig, pinoEcho);

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  
  Serial.begin(9600);
}
void loop() {

  long microsec = ultrasonic.timing();
  float cm = ultrasonic.convert(microsec,Ultrasonic::CM);
  
  Serial.println(cm);
  
  if ((cm <= distanciaMinima) && (cm > distanciaMaxima)){
    digitalWrite(12, HIGH);
    delay(1000);
    digitalWrite(12, LOW);
  }else
  if(cm <= distanciaMaxima){
    digitalWrite(13, HIGH);
    delay(1000); 
    digitalWrite(13, LOW);
  }

}
