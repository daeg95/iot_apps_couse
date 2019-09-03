#if define (ESP8266)
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#else
#include <WiFi.h>
#include <WebServer.h>
#endif

#include <DNSServer.h>
#include <WiFiManager.h>


const int PIN_AP= 2;

void configModeCallback(WiFiManager *myWiFimanager)
{
    Serial.println("Modo de configuracion...");
    Serial.println(WifI.softAPIP());
    Serial.println(myWiFimanager->getConfigPortalSSID());
}

void saveConfigCallback()
{
    Serial.println("Configuracion guardada");
    Serial.println(Wifi.softAPIP());
}

void setup ()
{
    Serial.begin(115200);
    pinMode(PIN_AP, INPUT);

    WiFiManager wifiManager;

    wifiManager.setAPCallback(configModeCallback);
    wifiManager.setSaveConfigCallback(saveConfigCallback);

    wifiManager.autoConnect("Daniela","12345678");
}

void loop()
{
    WiFiManager wifiManager;

    if (digitalRead(PIN_AP)== HIGH)
    {
        if (!wifiManager.startConfigPortal("Daniela","12345678"))
        {
            delay(2000);
            ESP.restart();
            delay(1000);
        }

        
    }
    


}