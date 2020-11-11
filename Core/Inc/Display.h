/*
 * Display.h
 *
 *  Created on: Nov 9, 2020
 *      Author: nicolas-kruger
 */
#include "stm32f1xx_hal.h"
#include "main.h"
#include <string>
#include "Map.h"
using namespace std;
#ifndef DISPLAY_H_
#define DISPLAY_H_
#define LCD_RESET_PIN LCD_RST_Pin // Usar o nome do pino de reset configurado.
#define LCD_RESET_PORT LCD_RST_GPIO_Port  // Usar o nome da porta de reset configurado.

#define LCD_CE_PIN LCD_CE_Pin // Usar o nome do pino de chip enable configurado
#define LCD_CE_PORT LCD_CE_GPIO_Port // Usar o nome da porta de chip enable configurado

#define LCD_DC_PIN LCD_DC_Pin // Usar o nome do pino de data/comando configurado
#define LCD_DC_PORT LCD_DC_GPIO_Port // Usar o nome da porta de data/comando configurado

#define LCD_SPI_INTERFACE hspi1 // usar a struct da variavel extern

extern SPI_HandleTypeDef hspi1;

class Display {
protected:
	Display();
public:
  static unsigned char font6x8[][6];
  static uint8_t spiOK;
  static void LCD_Init(void);
  static void LCD_Reset(void);
  static void LCD_Write_Command(uint8_t cmd);
  static void LCD_Write_Data(uint8_t data);
  static void LCD_Set_Postion(uint8_t PosX, uint8_t PosY);
  static void LCD_Clear(void);
  static void LCD_Write_Char(uint8_t ch);
  static void LCD_Write_String(uint8_t PosX, uint8_t PosY,const char * str);
  static void LCD_Write_String(uint8_t PosX, uint8_t PosY,string str);
  static void LCD_Write_String_Grid(uint8_t PosX, uint8_t PosY,string str);
  virtual ~Display();
};
//uint8_t Display::spiOK = 0U;

#endif /* DISPLAY_H_ */
