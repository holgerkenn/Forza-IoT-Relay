#include "AZ3166WiFi.h"
#include "DevKitMQTTClient.h"
#include <AZ3166WiFiUdp.h>

#include "forza.h"

const int packetsize = 1024;
static bool hasWifi = false;
static bool hasIoTHub = false;
WiFiUDP Udp;

byte receiveBuffer[packetsize];
telemetry *receivedTelemetry;

unsigned int packetCount=0;

void connectWifi()
{
  if (WiFi.begin() == WL_CONNECTED)
  {
    
    hasWifi = true;
    Screen.print(1, "Running...");

    if (!DevKitMQTTClient_Init())
    {
      hasIoTHub = false;
      return;
    }
    hasIoTHub = true;
  }
  else
  {
    hasWifi = false;
    Screen.print(1, "No Wi-Fi");
  }

}

void setup() {
  char screenBuffer[24];
  // put your setup code here, to run once:
  Serial.begin(115200);
  connectWifi();
  if (!hasIoTHub)
  {
    Screen.print(1,"Failed");
    Serial.println("Failed");

  }

  Udp.begin(6669);
  snprintf(screenBuffer,24,"%s",WiFi.localIP().get_address());
  Screen.print(0,screenBuffer);
  

}

bool receivePacket()
{
  int length;

  length =Udp.read(receiveBuffer, packetsize);
  if(length>0)
    {
      Serial.print("Packed received, length "); Serial.println(length);
      if (length==324) {
        //lenght as expected
        return true;
      }
      else return false;
    }
    return false;
}

bool parsePacket()
{
char screenBuffer[24];

receivedTelemetry=(telemetry*)receiveBuffer;
//Serial.print("IsRaceOn");Serial.println(receivedTelemetry->IsRaceOn);
//Serial.print("Timestamp");Serial.println(receivedTelemetry->TimestampMS);
snprintf(screenBuffer,24,"TS:%d",receivedTelemetry->TimestampMS);
Screen.print(1,screenBuffer);
//snprintf(screenBuffer,24,"PC:%d",packetCount++);
//Screen.print(2,screenBuffer);
snprintf(screenBuffer,24,"Spd:%2.2fkmh",receivedTelemetry->Speed*3.6);
Screen.print(2,screenBuffer);
snprintf(screenBuffer,24,"Rpm:%2.0f G:%d",receivedTelemetry->CurrentEngineRpm,receivedTelemetry->Gear+1);
Screen.print(3,screenBuffer);
return true;

}

void loop() {
 char buff[256];
 // put your main code here, to run repeatedly:
  if (hasIoTHub && hasWifi)
  {
    if (receivePacket())
    {
      if (parsePacket())
      {
    // replace the following line with your data sent to Azure IoTHub
    snprintf(buff, 256, "{\"timestamp\":%d,\"speed\":%f,\"rpm\":%f,\"gear\":%d}",receivedTelemetry->TimestampMS,receivedTelemetry->Speed,receivedTelemetry->CurrentEngineRpm,receivedTelemetry->Gear);
    
    if (DevKitMQTTClient_SendEvent(buff))
    {
      Screen.print(1, "Sending...");
    }
    else
    {
      Screen.print(1, "Failure...");
    }

      }
    }

 
    // delay(2000);
  }
}
