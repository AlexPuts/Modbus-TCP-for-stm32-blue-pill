# Modbus-TCP-for-stm32-blue-pill
This project features few corrections for original modbus TCP ENC28J60 in order for it to work with stm32 (stm32duino) blue pill

PIN Connections (Using STM32F103):

ENC28J60             | STM32F103        |
------------------   |------------------|
Q3                   | 3.3V             |
SCK                  |PA5               |
SO                   |PA6               |
SI                   |PA7               |
CS                   |PA8               |
RST                  |3.3V              |


For reference see the page of original library.
https://github.com/andresarmento/modbus-arduino 
