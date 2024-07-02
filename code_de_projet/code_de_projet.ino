#include <WiFi.h>
#include <PubSubClient.h>

#define ID 2
 // Déclaration et initialisation des broches d'entrées
int Analog_pin = 35; // Entrée analogique

 float a ;
// WiFi
const char *ssid = "safa"; // Enter your WiFi name
const char *password = "123456789s";  // Enter WiFi password

// MQTT Broker
const char *mqtt_broker = "broker.emqx.io";
const char *topic = "projet/bruit";

const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  {
  pinMode (Analog_pin, INPUT);
      
  Serial.begin (9600); // Sortie série à 9600 bauds
}
  
// Le programme lit les valeurs des broches d'entrée et les envoie à la sortie série

 // Set software serial baud to 115200;
 Serial.begin(115200);
 // connecting to a WiFi network
  WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.println("Connecting to WiFi..");
 }
 Serial.println("Connected to the WiFi network");
 //connecting to a mqtt broker
 client.setServer(mqtt_broker, mqtt_port);
 client.setCallback(callback);
 while (!client.connected()) {
     String client_id = "esp32-jgjggggj46546-";
     //client_id += String(WiFi.macAddress());
     Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
     if (client.connect("jgtf756bcdky58jr")) {
         Serial.println("Public emqx mqtt broker connected");
     } else {
         Serial.print("failed with state ");
         Serial.print(client.state());
         delay(2000);
     }
 }
 // publish and subscribe
 client.publish(topic, "Hi EMQX I'm ESP32 ^^");
 client.subscribe(topic);

}

void callback(char *topic, byte *payload, unsigned int length) {
 Serial.print("Message arrived in topic: ");
 Serial.println(topic);
 Serial.print("Message:");
 for (int i = 0; i < length; i++) {
     Serial.print((char) payload[i]);
 }
 Serial.println();
 Serial.println("-----------------------");
}


int c = 20;
int tot =0;
void loop() {
  {
  
  float Analog;
  int Digital;
  Analog = analogRead (Analog_pin) ; 
  //... et envoyées à la sortie série.
  
  delay (100);
  a = map(Analog,0,3200,30,70);
  tot +=a;
  c--;

  if(c<=0){
    tot /=20;
    tot +=20;
    String ss = "{\"value\":"+String(tot)+",\"id\":"+String(ID)+"}";
  Serial.print (ss);  
  Serial.println ("----------------------------------------------------------------");
client.publish (topic, ss.c_str());
tot = 0;
c = 20;
  }



}
 client.loop();
}
