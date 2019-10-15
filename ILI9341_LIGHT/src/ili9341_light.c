/*
 * ili9341_light.c
 *
 *  Created on: 15 זמגע. 2019 נ.
 *      Author: tabur
 */
#include "ili9341_light.h"
#include "main.h"
#include <stdbool.h>

enum {
  MemoryAccessControlNormalOrder,
  MemoryAccessControlReverseOrder
} MemoryAccessControlRefreshOrder;

enum {
	MemoryAccessControlColorOrderRGB,
	MemoryAccessControlColorOrderBGR
} MemoryAccessControlColorOrder;

static unsigned char lcdPortraitConfig = 0;
static unsigned char lcdLandscapeConfig = 0;
static unsigned char lcdPortraitMirrorConfig = 0;
static unsigned char lcdLandscapeMirrorConfig = 0;

// Write an 8 bit command to the IC driver
static void lcdWriteCommand(unsigned char command)
{
	LCD_CmdWrite(command);
}

// Write an 16 bit data word to the IC driver
static void lcdWriteData(unsigned short data)
{
	LCD_DataWrite(data);
}

static void lcdReset(void)
{
	lcdWriteCommand(ILI9341_SOFTRESET);
	HAL_Delay(50);
}

static unsigned char lcdBuildMemoryAccessControlConfig(
                        bool rowAddressOrder,
                        bool columnAddressOrder,
                        bool rowColumnExchange,
                        bool verticalRefreshOrder,
                        bool colorOrder,
                        bool horizontalRefreshOrder)
{
  unsigned char value 				= 0;
  if(horizontalRefreshOrder) value 	|= ILI9341_MADCTL_MH;
  if(colorOrder) value 				|= ILI9341_MADCTL_BGR;
  if(verticalRefreshOrder) value 	|= ILI9341_MADCTL_ML;
  if(rowColumnExchange) value 		|= ILI9341_MADCTL_MV;
  if(columnAddressOrder) value 		|= ILI9341_MADCTL_MX;
  if(rowAddressOrder) value 		|= ILI9341_MADCTL_MY;
  return value;
}

void lcdInit(void)
{
  lcdPortraitConfig = lcdBuildMemoryAccessControlConfig(
                                                    MemoryAccessControlNormalOrder,		// rowAddressOrder
                                                    MemoryAccessControlReverseOrder,	// columnAddressOrder
                                                    MemoryAccessControlNormalOrder,		// rowColumnExchange
                                                    MemoryAccessControlNormalOrder,		// verticalRefreshOrder
                                                    MemoryAccessControlColorOrderBGR,	// colorOrder
                                                    MemoryAccessControlNormalOrder);	// horizontalRefreshOrder

  lcdLandscapeConfig = lcdBuildMemoryAccessControlConfig(
                                                    MemoryAccessControlNormalOrder,		// rowAddressOrder
                                                    MemoryAccessControlNormalOrder,		// columnAddressOrder
                                                    MemoryAccessControlReverseOrder,	// rowColumnExchange
                                                    MemoryAccessControlNormalOrder,		// verticalRefreshOrder
                                                    MemoryAccessControlColorOrderBGR,	// colorOrder
                                                    MemoryAccessControlNormalOrder);	// horizontalRefreshOrder

  lcdPortraitMirrorConfig = lcdBuildMemoryAccessControlConfig(
		  	  	  	  	  	  	  	  	  	  	  	MemoryAccessControlReverseOrder,	// rowAddressOrder
		                                            MemoryAccessControlNormalOrder,		// columnAddressOrder
		                                            MemoryAccessControlNormalOrder,		// rowColumnExchange
		                                            MemoryAccessControlNormalOrder,		// verticalRefreshOrder
		                                            MemoryAccessControlColorOrderBGR,	// colorOrder
		                                            MemoryAccessControlNormalOrder);	// horizontalRefreshOrder

  lcdLandscapeMirrorConfig = lcdBuildMemoryAccessControlConfig(
                                                    MemoryAccessControlReverseOrder,	// rowAddressOrder
                                                    MemoryAccessControlReverseOrder,	// columnAddressOrder
                                                    MemoryAccessControlReverseOrder,	// rowColumnExchange
                                                    MemoryAccessControlNormalOrder,		// verticalRefreshOrder
                                                    MemoryAccessControlColorOrderBGR,	// colorOrder
                                                    MemoryAccessControlNormalOrder);	// horizontalRefreshOrder

  lcdReset();

  lcdWriteCommand(ILI9341_DISPLAYOFF);

  lcdWriteCommand(0xCF);
  lcdWriteData(0x00);
  lcdWriteData(0x83);
  lcdWriteData(0x30);

  lcdWriteCommand(0xED);
  lcdWriteData(0x64);
  lcdWriteData(0x03);
  lcdWriteData(0x12);
  lcdWriteData(0x81);

  lcdWriteCommand(0xE8);
  lcdWriteData(0x85);
  lcdWriteData(0x01);
  lcdWriteData(0x79);

  lcdWriteCommand(0xCB);
  lcdWriteData(0x39);
  lcdWriteData(0x2C);
  lcdWriteData(0x00);
  lcdWriteData(0x34);
  lcdWriteData(0x02);

  lcdWriteCommand(0xF7);
  lcdWriteData(0x20);

  lcdWriteCommand(0xEA);
  lcdWriteData(0x00);
  lcdWriteData(0x00);

  lcdWriteCommand(ILI9341_POWERCONTROL1);
  lcdWriteData(0x26);

  lcdWriteCommand(ILI9341_POWERCONTROL2);
  lcdWriteData(0x11);

  lcdWriteCommand(ILI9341_VCOMCONTROL1);
  lcdWriteData(0x35);
  lcdWriteData(0x3E);

  lcdWriteCommand(ILI9341_VCOMCONTROL2);
  lcdWriteData(0xBE);

  lcdWriteCommand(ILI9341_MEMCONTROL);
  lcdWriteData(lcdPortraitMirrorConfig);

  lcdWriteCommand(ILI9341_PIXELFORMAT);
  lcdWriteData(0x55);

  lcdWriteCommand(ILI9341_FRAMECONTROLNORMAL);
  lcdWriteData(0x00);
  lcdWriteData(0x1B);

  lcdWriteCommand(0xF2);
  lcdWriteData(0x08);

  lcdWriteCommand(ILI9341_GAMMASET);
  lcdWriteData(0x01);

  lcdWriteCommand(ILI9341_POSITIVEGAMMCORR);
  lcdWriteData(0x1F);
  lcdWriteData(0x1A);
  lcdWriteData(0x18);
  lcdWriteData(0x0A);
  lcdWriteData(0x0F);
  lcdWriteData(0x06);
  lcdWriteData(0x45);
  lcdWriteData(0x87);
  lcdWriteData(0x32);
  lcdWriteData(0x0A);
  lcdWriteData(0x07);
  lcdWriteData(0x02);
  lcdWriteData(0x07);
  lcdWriteData(0x05);
  lcdWriteData(0x00);

  lcdWriteCommand(ILI9341_NEGATIVEGAMMCORR);
  lcdWriteData(0x00);
  lcdWriteData(0x25);
  lcdWriteData(0x27);
  lcdWriteData(0x05);
  lcdWriteData(0x10);
  lcdWriteData(0x09);
  lcdWriteData(0x3A);
  lcdWriteData(0x78);
  lcdWriteData(0x4D);
  lcdWriteData(0x05);
  lcdWriteData(0x18);
  lcdWriteData(0x0D);
  lcdWriteData(0x38);
  lcdWriteData(0x3A);
  lcdWriteData(0x1F);

  lcdWriteCommand(ILI9341_COLADDRSET);
  lcdWriteData(0x00);
  lcdWriteData(0x00);
  lcdWriteData(0x00);
  lcdWriteData(0xEF);

  lcdWriteCommand(ILI9341_PAGEADDRSET);
  lcdWriteData(0x00);
  lcdWriteData(0x00);
  lcdWriteData(0x01);
  lcdWriteData(0x3F);

  lcdWriteCommand(ILI9341_ENTRYMODE);
  lcdWriteData(0x07);

  lcdWriteCommand(ILI9341_DISPLAYFUNC);
  lcdWriteData(0x0A);
  lcdWriteData(0x82);
  lcdWriteData(0x27);
  lcdWriteData(0x00);

  lcdWriteCommand(ILI9341_SLEEPOUT);
  HAL_Delay(100);
  lcdWriteCommand(ILI9341_DISPLAYON);
  HAL_Delay(100);
  lcdWriteCommand(ILI9341_MEMORYWRITE);
}

void lcdBacklightOff(void)
{
	LCD_BL_OFF();
}

void lcdBacklightOn(void)
{
	LCD_BL_ON();
}
