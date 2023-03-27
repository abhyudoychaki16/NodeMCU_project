/*************************************************************

  Blynk using a LED widget on your phone!

  App dashboard setup:
    LED widget on V1
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL7jOWFyde"
#define BLYNK_DEVICE_NAME "Quickstart Device"
#define BLYNK_AUTH_TOKEN "P-ibSxndA5H0BWxUAWDgxRdza8bR7V8b"



/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#define ANALOG_PIN A0


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266_SSL.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Mayank";
char pass[] = "mayank10101";

int ledPin = D0;
BlynkTimer timer;
static int choiceOfTemp;
BLYNK_WRITE(V4){
  choiceOfTemp=param.asInt();
}
void readTemperature(){
  int reading = analogRead(ANALOG_PIN); // read the analog pin
  float voltage = reading * (3.3 / 1023.0); // convert the analog reading to voltage
  float temperature = voltage * 100.0;     // convert the voltage to temperature in degrees Celsius
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" degrees Celsius");
  if(temperature<choiceOfTemp){
    digitalWrite(ledPin,0);
  }
  else if(temperature>choiceOfTemp+20){
    digitalWrite(ledPin,1);
  }
}
void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN,ssid, pass);
  pinMode(ANALOG_PIN, INPUT);
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN,ssid, pass);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin,1);
  timer.setInterval(10000L,readTemperature);
}
void loop() {
  Blynk.run();
  timer.run();
}

// BLYNK_WRITE(V1) {
//   int ledState = param.asInt();
//   digitalWrite(ledPin, ledState);
// }
