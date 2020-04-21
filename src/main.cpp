#include <Arduino.h>
#include <Button.h>
#include <Potentiometer.h>
#include <Joystick.h>

//giving information about the wifi
const char * ssid = "ZAQK";
const char * password = "199zia66";

//setting pins for different sensors
int pinButton = 23;
Button button(pinButton);
Potentiometer potentiometer (34);
Joystick joystick (36, 35);


void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  potentiometer.setSensitivity(100);
}

void loop() {
  button.notPressed();
  delay(1000);
  joystick.movement();
  potentiometer.changePixelColour();
}