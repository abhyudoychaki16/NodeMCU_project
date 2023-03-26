/*************************************************************

  Blynk using a LED widget on your phone!

  App dashboard setup:
    LED widget on V1
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           "TMPLsRfvH0sI"
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "Yc9uzByFd2_2YmMzATkhQ5Ml1EIf8PqO"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266_SSL.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "*****";
char pass[] = "*********";

int ledPin = D0; // Pin for LED

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN,ssid, pass);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(V1) {
  int ledState = param.asInt();
  digitalWrite(ledPin, ledState);
}
