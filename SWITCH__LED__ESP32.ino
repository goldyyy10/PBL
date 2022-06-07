// this header is needed for Bluetooth Serial -> works ONLY on ESP32
#include "BluetoothSerial.h" 
//#include <ezButton.h>

// init Class:
BluetoothSerial ESP_BT; 

// We assigned a name LED pin to pin number 5
const int LEDPIN = 5;

// We assigned a name PushButton to pin number 23
const int PushButton = 23;


// This Setup function is used to initialize everything 
void setup()
{
  Serial.begin(19200);
  ESP_BT.begin("ESP32_Control");
  
  // This statement will declare pin 23 as digital input
  pinMode(PushButton, INPUT);
  
  // This statement will declare pin 5 as digital output 
  pinMode(LEDPIN, OUTPUT);

  digitalWrite(LEDPIN, LOW);

}


void loop()
{
  int Push_button_state = digitalRead(PushButton);
  
  if ( Push_button_state == LOW )
  {
        digitalWrite(LEDPIN,HIGH);
        ESP_BT.write(10);
  }

  else
  {
        digitalWrite(LEDPIN, LOW);
  }
}
