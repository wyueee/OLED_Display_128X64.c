# OLED_Display_128X64.c  

<img src=https://statics3.seeedstudio.com/seeed/img/2016-09/6hLLXlBnfODAcWlp2wlaep3j.jpg width=400>   <img src=https://statics3.seeedstudio.com/seeed/img/2016-09/DwdeSLxipUJdCgsFZDI2wtYD.jpg width=400>  

C driver for [Grove - OLED Display 0.96"](https://www.seeedstudio.com/s/Grove-OLED-Display-0.96%22-p-781.html), adapted from the [C++ driver](https://github.com/Seeed-Studio/OLED_Display_128X64).

Tested on **B-L475E-IOT01A**, with the OLED screen connected to the I2C port via the [Base Shield V2](https://wiki.seeedstudio.com/Base_Shield_V2/).

## Pre-requisites  
- Download `LCDAssistant.exe` from [this repository](https://github.com/mcauser/Grove-OLED-Display-96x96) (located in `Make A 96X96 Image.zip`) to convert `.bmp` images into patterns for displaying on the OLED screen.

## Installation  
1. Download `OLED_Display_128X64.c` and place it in `<project>/Core/Src`.
2. Download `OLED_Display_128X64.h` and place it in `<project>/Core/Inc`.
3. In `main.c`, add the following line:
   ```c
   #include "OLED_Display_128X64.h"
   ```
4. Inside `int main(void)`, initialize the OLED screen by calling:
   ```c
   OLED_Display_Init();
   ```

## Usage  

### Clearing the Display  
```c
OLED_clearDisplay();
```
Clears the entire screen.

### Displaying Text  
```c
char oled_msg[64];
sprintf(oled_msg, "Hello, world!");
OLED_putStr((uint8_t*)oled_msg, strlen(oled_msg));
```
Prints a string on the screen. **Note:** The refresh rate of the OLED is slow, so printing long strings is not recommended, as the microcontroller will pause while updating the screen.

### Displaying an Image  
```c
char pic[1024] = {0x00, 0x00, ...}; // Pattern generated from LCDAssistant.exe
OLED_putPicture((uint8_t*)pic);
```
Displays an image on the screen using a bitmap pattern generated from `LCDAssistant.exe`.

### Optimized String Printing  
```c
char oled_msg[64];
sprintf(oled_msg, "Hello, world!");
OLED_putStr((uint8_t*)oled_msg, strlen(oled_msg));

sprintf(oled_msg, "Hello, world!!!");
OLED_putStr_fast((uint8_t*)oled_msg, strlen(oled_msg));
```
`OLED_putStr_fast()` is a faster version of `OLED_putStr()`. It updates only the characters that have changed instead of redrawing the entire string, improving performance. In this example, only the two additional exclamation marks (`!!`) will be updated, significantly reducing update time.

