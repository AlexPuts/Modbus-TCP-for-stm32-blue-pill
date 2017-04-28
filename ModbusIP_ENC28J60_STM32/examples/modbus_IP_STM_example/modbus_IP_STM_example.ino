 /*
  Originally library comes from:
  http://github.com/andresarmento/modbus-arduino
  Copyright by André Sarmento Barbosa

 Some modifications were added to provide compatibility
  with stm32 duino blue pill board. by AlexPutz

PIN Connections (Using STM32F103):
///////////////////////
ENC28J60  STM32F103
Q3 3.3V
SCK PA5
SO  PA6
SI  PA7
CS  PA8
RST 3.3V
//////////////////////
*/

#include <EtherCard_STM.h>
#include <Modbus.h>
#include <ModbusIP_ENC28J60_STM.h>

//ModbusIP object
ModbusIP mb;

void setup() {
  
    // The media access control (ethernet hardware) address for the shield
    byte mac[] = { 0xDE, 0xAD, 0xB1, 0xFF, 0xFD, 0xED };
    // The IP address for the shield
    byte ip[] = { 192, 168, 0, 121 };
    //Config Modbus IP
    if (ether.begin(500*8, mac) == 0){
    Serial.println( "Failed to access Ethernet controller");
    }
    mb.config(mac, ip);
    //Create 50 empty modbus registers
    for(int i = 0; i <= 50; i++) 
    {
    mb.addHreg(i,0);
    }
    
}

void loop() {
   //Call once inside loop() - all magic here
   mb.task();
   //Setup the registers to contain some numbers;
   mb.Hreg(2,1488617171/65536);
   mb.Hreg(3,1488617171%65536);
   
}
