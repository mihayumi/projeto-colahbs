#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//Coloque aqui o token de autenticação do seu projeto no Blynk.
char auth[] = "YourAuthToken";

//Coloque aqui o nome da WIFI
char ssid[] = "YourNetworkName";

//Coloque aqui a senha da WIFI
char pass[] = "YourPassword"; 

int pinoSensorMagJanelaQuarto = D1;
int pinoSensorChuva = D5;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  if (digitalRead(pinoSensorMagJanelaQuarto) == LOW && digitalRead(pinoSensorChuva) == LOW){
        Blynk.notify("Está chovendo e a janela do seu quarto está aberta.");
        delay(5*60*1000);
  }
}
