#include <ESP8266WiFi.h>
#include <ThingSpeak.h> 
#define relay   12 
const char* SSID = "Your_WiFi_Name";  Replace with your WiFi network name
const char* PASSWORD = "Your_WiFi_Password";     Replace with your WiFi network password
const unsigned long CHANNEL_ID = 1234567; // Replace with your ThingSpeak Channel ID
const char* READ_API_KEY = "XXXXXXXXXX";  Replace with your ThingSpeak keys 
const char* WRITE_API_KEY = "XXXXXXXXXX"; Replace with your ThingSpeak keys

const int FieldNumber1 = 1; 
WiFiClient client;
bool relayTriggered = false; // keep track of whether the relay has been triggered or not

void setup() {
  Serial.begin(9600);
  delay(1000);  // Wait for serial to initialize
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  WiFi.mode(WIFI_STA);  // Set the NodeMCU to station mode
  WiFi.begin(ssid, password);  // Connect to the WiFi network

  while (WiFi.status() != WL_CONNECTED) {  // Wait for the NodeMCU to connect to the WiFi network
    delay(1000);
    Serial.print("Connecting to ");
    Serial.print(ssid);
    Serial.println("...");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  // Print the NodeMCU's local IP address
  ThingSpeak.begin(client);
}

void loop() {
  int A = ThingSpeak.readLongField(ChannelNumber, FieldNumber1, ReadAPIKey);
  Serial.println(A);
  if (A == 1 && !relayTriggered) { // only trigger the relay if it hasn't been triggered before
    digitalWrite(relay, LOW);
    delay(200);
    digitalWrite(relay, HIGH);
    ThingSpeak.writeField(ChannelNumber, FieldNumber1, 0, WriteAPIKey);    // Write 0 back to FieldNumber1 using ThingSpeak API
    relayTriggered = true; // set the flag to true after the relay has been triggered
  } else if (A == 0) {
    relayTriggered = false; // reset the flag when the field value changes to 0
  }
}
