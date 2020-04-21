#include <Arduino.h>
#include "Connector.h"

class Potentiometer{
   public: int pinNumber; 
   public: int lastRead;
   public: int currentRead;
   public: int sensitivity;
   String color ="";

    Connector connect;

    public: 
    Potentiometer(int pinNumber){
        this->pinNumber = pinNumber;
            pinMode(pinNumber, INPUT);
            this->lastRead = this->readPotentiometer();
    }

    int readPotentiometer()
        {
            return analogRead(pinNumber);
        }
 
        void setSensitivity(int sensitivity)
        {
            this->sensitivity = sensitivity;
        }
        bool changed()
        {
            return abs(lastRead-analogRead(pinNumber)) > sensitivity;
        }

    void changePixelColour(){
        if (this->changed()){
            currentRead = readPotentiometer();
            Serial.println(analogRead(pinNumber));

            if (currentRead <= 1356){
                connect.broadcast("color 255 0 0");
            }
            else if (currentRead > 1356 && currentRead >= 2712){
                connect.broadcast("color 0 255 0");
            }
            else{
                connect.broadcast("color 0 0 255");
            }
        }
    }
};