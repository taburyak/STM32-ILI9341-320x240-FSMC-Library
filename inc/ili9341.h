/*
 * ili9341.h
 *
 *  Created on: 22 бер. 2018 р.
 *  Author: Andriy Honcharenko
 *  Version 1.1 date: 24.09.2019
 */

#ifndef ILI9341_H_
#define ILI9341_H_

#include "main.h"
#include "colors.h"
#include "registers.h"
#include "fonts.h"
#include "image.h"
#include <stdbool.h>

#define LCD_BL_ON() HAL_GPIO_WritePin(LCD_BL_GPIO_Port, LCD_BL_Pin, GPIO_PIN_SET)
#define LCD_BL_OFF() HAL_GPIO_WritePin(LCD_BL_GPIO_Port, LCD_BL_Pin, GPIO_PIN_RESET)

#define LCD_BASE0        		((uint32_t)0x60000000)
#define LCD_BASE1        		((uint32_t)0x60080000)

#define LCD_CmdWrite(command)	*(volatile uint16_t *) (LCD_BASE0) = (command)
#define LCD_DataWrite(data)		*(volatile uint16_t *) (LCD_BASE1) = (data)
#define	LCD_StatusRead()		*(volatile uint16_t *) (LCD_BASE0) //if use read  Mcu interface DB0~DB15 needs increase pull high
#define	LCD_DataRead()			*(volatile uint16_t *) (LCD_BASE1) //if use read  Mcu interface DB0~DB15 needs increase pull high

#define swap(a, b) { int16_t t = a; a = b; b = t; }

#define ILI9341_PIXEL_WIDTH		240
#define ILI9341_PIXEL_HEIGHT 	320
#define ILI9341_PIXEL_COUNT		ILI9341_PIXEL_WIDTH * ILI9341_PIXEL_HEIGHT

// Any LCD needs to implement these common methods, which allow the low-level
// initialisation and pixel-setting details to be abstracted away from the
// higher level drawing and graphics code.

typedef enum
{
	LCD_ORIENTATION_PORTRAIT 			= 0,
	LCD_ORIENTATION_LANDSCAPE 			= 1,
	LCD_ORIENTATION_PORTRAIT_MIRROR 	= 2,
	LCD_ORIENTATION_LANDSCAPE_MIRROR 	= 3
} lcdOrientationTypeDef;

/**
  * @brief  Draw Properties structures definition
  */
typedef struct
{
	uint32_t 	TextColor;
	uint32_t 	BackColor;
	sFONT*    	pFont;
	uint8_t		TextWrap;
}lcdFontPropTypeDef;

typedef struct
{
	unsigned short	x;
	unsigned short	y;
}lcdCursorPosTypeDef;

// This struct is used to indicate the capabilities of different LCDs
typedef struct
{
  uint16_t				width;         // LCD width in pixels (default orientation)
  uint16_t				height;        // LCD height in pixels (default orientation)
  lcdOrientationTypeDef	orientation;   // Whether the LCD orientation can be modified
  bool					touchscreen;   // Whether the LCD has a touch screen
  bool					hwscrolling;   // Whether the LCD support HW scrolling
} lcdPropertiesTypeDef;

void					lcdInit(void);
void              		lcdTest(void);
void					lcdFillRGB(uint16_t color);
void					lcdDrawPixel(uint16_t x, uint16_t y, uint16_t color);
void              		lcdDrawHLine(uint16_t x0, uint16_t x1, uint16_t y, uint16_t color);
void              		lcdDrawVLine(uint16_t x, uint16_t y0, uint16_t y1, uint16_t color);
void 					lcdDrawLine(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void					lcdDrawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void					lcdDrawRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color);
void					lcdDrawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color);
void					lcdDrawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
void 					lcdDrawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void					lcdFillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
void					lcdFillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color);
void					lcdFillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t fillcolor);
void					lcdFillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color);
void 					lcdFillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void					lcdDrawImage(uint16_t x, uint16_t y, GUI_CONST_STORAGE GUI_BITMAP* pBitmap);
void              		lcdHome(void);
void 					lcdDrawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg);
void					lcdPrintf(const char *fmt, ...);
void					lcdSetTextFont(sFONT* font);
void					lcdSetTextColor(uint16_t c, uint16_t b);
void					lcdSetTextWrap(uint8_t w);
void              		lcdSetOrientation(lcdOrientationTypeDef orientation);
void					lcdSetCursor(unsigned short x, unsigned short y);
void              		lcdSetWindow(unsigned short x0, unsigned short y0, unsigned short x1, unsigned short y1);
void					lcdBacklightOff(void);
void					lcdBacklightOn(void);
void					lcdInversionOff(void);
void					lcdInversionOn(void);
void					lcdDisplayOff(void);
void					lcdDisplayOn(void);
void					lcdTearingOff(void);
void					lcdTearingOn(bool m);
uint16_t          		lcdGetWidth(void);
uint16_t          		lcdGetHeight(void);
uint16_t          		lcdGetControllerID(void);
lcdOrientationTypeDef  	lcdGetOrientation(void);
sFONT*					lcdGetTextFont(void);
lcdPropertiesTypeDef   	lcdGetProperties(void);
uint16_t				lcdReadPixel(uint16_t x, uint16_t y);
uint16_t 				lcdColor565(uint8_t r, uint8_t g, uint8_t b);

#endif /* ILI9341_H_ */
