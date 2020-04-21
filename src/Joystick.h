#include <Arduino.h>
#include "Connector.h"

class Joystick{
    public: int pinX; 
    public: int pinY; 
    public: int currentX;
    public: int currentY;
    Connector connect;

    Joystick (int pinX, int pinY){
        this->pinX = pinX;
        this->pinY = pinY;
        pinMode(pinX, INPUT);
        pinMode(pinY, INPUT);

    }

    void movement(){

    connect.broadcast("speed 8");
    currentX = analogRead(pinX);
    currentY = analogRead(pinY);

    Serial.print("X: ");
    Serial.println(analogRead(pinX));
    Serial.print("Y: ");
    Serial.println(analogRead(pinY));


    if (currentX>1500 && currentX <1900 && currentY > 1500 && currentY <1900){
connect.broadcast ("stop");
} 
    else if(currentX > 1900){
      connect.broadcast("moveright");
    }else if(currentX < 1500){
      connect.broadcast("moveleft");
    }
    if(currentY > 1900){
      connect.broadcast("moveup");
    } else if(currentY < 1500){
      connect.broadcast("movedown");
    }  
  } 
};