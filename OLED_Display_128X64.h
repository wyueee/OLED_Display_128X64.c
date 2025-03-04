#ifndef OLED_DISPLAY_H
#define OLED_DISPLAY_H

#include "../../Drivers/BSP/B-L475E-IOT01/stm32l475e_iot01.h"
#include <stdint.h>
 

#define OLED_DISPLAY_ADDR 0x3C << 1

extern I2C_HandleTypeDef BaseShield_I2C_Struct;

extern uint8_t BasicFont[][8];

void OLED_Display_Init();
void OLED_sendCommand(uint8_t command);
void OLED_sendData(uint8_t data);
void OLED_setTextXY(uint8_t row, uint8_t column);
void OLED_clearDisplay();
void OLED_putChar(char C);
void OLED_putStr(uint8_t *pData, uint16_t Size);
void OLED_putPicture(uint8_t *picture);
void OLED_putStr_fast(uint8_t *pData, uint16_t Size);

extern char ghost_picture[1024];
extern char normal_picture[1024];
extern char ghost_busted_picture[1024];



#endif 
