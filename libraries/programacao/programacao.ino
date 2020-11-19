
#define sensorUmidade A0 //Sensor de umidade

int bomba = 6; //Porta da bomba de agua


void setup()
{
  //Inicia o serial com a bomba off

  Serial.begin(9600);
  pinMode(bomba, OUTPUT);
  
}

void loop()
{
  //Processo em loop
  int leitura = analogRead(sensorUmidade); //Ler o valor da umidade do solo

  if (leitura >= 800){
    
    Serial.println("Solo seco: ");
    digitalWrite(bomba, HIGH); //Bomba é ATIVADA
    
  }
  else{
    Serial.println("Solo umido: ");
    digitalWrite(bomba, LOW); //Bomba DESATIVADA
  }

}
