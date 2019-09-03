include <WiFi.h>

const char * ssid = "Emprendedores"
const char * password = "AxtVvm13"



void scanNetworks(){

    int numberNetworks = WiFi.scanNetworks()

    Serial.print("Redes encontradas");
    Serial.print(numberNetworks);

    for (int i = 0; i < numberNetworks; i++)
    {
        Serial.print("Nombre:");
    }
    


}