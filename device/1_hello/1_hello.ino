#include <ESP8266WiFi.h>

const char* ssid = "Emprendedores";
const char* password = "AxtVvm13";


void ScanNetwork ()
{
    int numberNetworks = WiFi.scanNetworks();
    Serial.print("Numero de redes: ");
    Serial.println(numberNetworks);

    for (int i = 0; i < numberNetworks; i++)
    {
        Serial.print("Nombre de la red: ");
        Serial.println(WiFi.SSID(i));
        Serial.print("Fuerza de la red: ");
        Serial.println(WiFi.RSSI(i));
        Serial.print("MAC: ");
        Serial.println(WiFi.BSSIDstr(i));
        Serial.print("Encriptación de la red: "); 
        //Serial.println(EncryptionType(WiFi.encryptionType(i)));
        Serial.println("========****=========");
    }
    
}

void connectToNetwork() 
{
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Tratando de establecer conexión...");
    }
    Serial.println("Conexión establecida :D");
}

void setup ()
{
    Serial.begin(115200);
    ScanNetwork();
    connectToNetwork();
    Serial.println(WiFi.macAddress());
    Serial.println(WiFi.localIP());
    //WiFi.disconnect(true);
}
void loop(){}