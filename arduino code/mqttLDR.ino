#include<ESP8266WiFi.h>
#include<PubSubClient.h>

const char* ssid="HARLEEN KAUR";
const char* pass="KARMANSINGH2712";
const char* server="broker.mqtt-dashboard.com"; 
int ldrPin=A0;
int ledPin=13;
int ldrvalue;
unsigned long lastmsg=0;
String str;
char msgbuff[100];

WiFiClient espclient;
PubSubClient client(espclient);     

void setup()
{
   pinMode(ledPin,OUTPUT);
   pinMode(ldrPin,INPUT);
   Serial.begin(115200);
   wifi_setup();
   client.setServer(server,1883);
  client.setCallback(callback);
   
 }
 void wifi_setup()
 {
  Serial.println();
  Serial.print("CONNECTING TO:");
  Serial.println(ssid);
  WiFi.begin(ssid,pass);
  while(WiFi.status()!=WL_CONNECTED)
  {
   delay(500); 
    Serial.print(".");
    }
  Serial.println("WIFI CONNECTED");
  Serial.print("IP ADDRESS:");
  Serial.println(WiFi.localIP());
  
 }

 void callback(char* topic,byte* payload,unsigned int length)
 {
  int i;
  Serial.print("MESSAGE ARRIVED[");
  Serial.print(topic);
  Serial.print("]");
  for(i=0;i<=length;i++)
  {
    msgbuff[i]=payload[i];
    if(i==length)
  msgbuff[i]='\0';
  }
  String msgstr=(String)msgbuff;
  Serial.println(msgstr);
  if(msgstr.equals("LIGHT ON"))
  {
    digitalWrite(ledPin,HIGH);
    }
  else
   if(msgstr.equals("LIGHT OFF"))
  {
    digitalWrite(ledPin,LOW);
    }
 }

void reconnect()
{
  while(!client.connected())
  {
    Serial.println("ATTEMPTING MQTT CONNECTION...");
    if(client.connect("esp8266client"))
    {
      Serial.println("CONNECTED");
      client.subscribe("ledstatus");
    }
  else
  {
    Serial.print("UNABLE TO CONNECT rc=");
    Serial.println(client.state());
    Serial.println("TRY AGAIN IN 5 SEC");
    delay(5000);  
  }
   
  }
}
void loop()
{
  ldrvalue=analogRead(ldrPin);
   
if(!client.connected())
{
  reconnect();
  }
client.loop();  
long newtime=millis();
if(newtime-lastmsg>5000)
{
  lastmsg=newtime;
  Serial.print("PUBLISH MESSAGE::");
  str=(String)ldrvalue;
  int str_len=str.length()+1;
  char char_array[str_len];
  str.toCharArray(char_array,str_len);
 Serial.println(ldrvalue);
  client.publish("ldrval",char_array);
 
  }
  
}

