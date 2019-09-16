/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ili9341.h"
/* USER CODE END Includes */

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
uint16_t colorArray[8] = { COLOR_BLUE, COLOR_CYAN, COLOR_GREEN, COLOR_MAGENTA, COLOR_ORANGE, COLOR_PURPLE, COLOR_YELLOW, COLOR_RED };
/* USER CODE END PV */

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
void demoLCD(int i);
/* USER CODE END PFP */

/* USER CODE BEGIN 2 */
  LCD_BL_ON();
  lcdInit();
  int i = 0;
  /* USER CODE END 2 */

/* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  demoLCD(i);
	  HAL_Delay(1000);
	  i++;
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

/* USER CODE BEGIN 4 */
void demoLCD(int i)
{
	uint32_t tick = 0;

	lcdSetOrientation(i % 4);

	tick = HAL_GetTick();
	lcdFillRGB(COLOR_BLACK);
	lcdSetTextFont(&Font16);
	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("Time: %4lu ms", HAL_GetTick() - tick);
	lcdSetCursor(0, 0);
	lcdSetTextFont(&Font24);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("BLACK");
	HAL_Delay(1000);

	tick = HAL_GetTick();
	lcdFillRGB(COLOR_GREEN);
	lcdSetTextFont(&Font16);
	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("Time: %4lu ms", HAL_GetTick() - tick);
	lcdSetCursor(0, 0);
	lcdSetTextFont(&Font24);
	lcdSetTextColor(COLOR_BLACK, COLOR_GREEN);
	lcdPrintf("GREEN");
	HAL_Delay(1000);

	tick = HAL_GetTick();
	lcdFillRGB(COLOR_RED);
	lcdSetTextFont(&Font16);
	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("Time: %4lu ms", HAL_GetTick() - tick);
	lcdSetCursor(0, 0);
	lcdSetTextFont(&Font24);
	lcdSetTextColor(COLOR_BLACK, COLOR_RED);
	lcdPrintf("RED");
	HAL_Delay(1000);

	tick = HAL_GetTick();
	lcdFillRGB(COLOR_BLUE);
	lcdSetTextFont(&Font16);
	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("Time: %4lu ms", HAL_GetTick() - tick);
	lcdSetCursor(0, 0);
	lcdSetTextFont(&Font24);
	lcdSetTextColor(COLOR_BLACK, COLOR_BLUE);
	lcdPrintf("BLUE");
	HAL_Delay(1000);

	lcdHome();

	tick = HAL_GetTick();
	lcdTest();
	lcdSetTextFont(&Font16);
	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("Time: %4lu ms", HAL_GetTick() - tick);
	HAL_Delay(1000);

	lcdFillRGB(COLOR_BLACK);
	tick = HAL_GetTick();
	lcdHome();
	lcdSetTextFont(&Font24);
	lcdSetTextColor(COLOR_GREEN, COLOR_BLUE);
	lcdPrintf("Hello, World!\r\n");
	lcdSetTextFont(&Font20);
	lcdSetTextColor(COLOR_BLACK, COLOR_RED);
	lcdPrintf("Hello, World! 1234567890\r\n");
	lcdSetTextFont(&Font16);
	lcdSetTextColor(COLOR_DARKGREY, COLOR_CYAN);
	lcdPrintf("Hello, World! 1234567890\r\n");
	lcdSetTextFont(&Font12);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("Hello, World! 1234567890\r\n");
	lcdSetTextFont(&Font16);
	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("Time: %4lu ms", HAL_GetTick() - tick);
	HAL_Delay(1000);
	lcdFillRGB(COLOR_BLACK);
	lcdDrawHLine(0, lcdGetWidth() - 1, 0, COLOR_RED);
	lcdDrawVLine(0, 0, lcdGetHeight() - 1, COLOR_RED);
	lcdDrawHLine(0, lcdGetWidth() - 1, lcdGetHeight() - 1, COLOR_RED);
	lcdDrawVLine(lcdGetWidth() - 1, 0, lcdGetHeight() - 1, COLOR_RED);
	lcdDrawLine(0, 0, lcdGetWidth() - 1, lcdGetHeight() - 1, COLOR_RED);
	lcdDrawLine(lcdGetWidth() - 1, 0, 0, lcdGetHeight() - 1, COLOR_RED);
	HAL_Delay(1000);
	lcdFillRGB(COLOR_BLACK);
	for (int i = 0; i < lcdGetHeight() / 2; i += 4)
	{
		lcdDrawRect(0 + i, 0 + i, (lcdGetWidth() - 1) - (i * 2), (lcdGetHeight() - 1) - (i * 2), COLOR_WHITE);
	}
	HAL_Delay(1000);
	lcdFillRGB(COLOR_BLACK);
	for (int i = 0; i < lcdGetWidth() / 2; i += 4)
	{
		lcdDrawCircle(lcdGetWidth() / 2, lcdGetHeight() / 2, i, COLOR_DARKGREEN);
	}
	HAL_Delay(1000);
	lcdFillRGB(COLOR_BLACK);
	for (int i = 0; i < 8; ++i)
	{
		lcdFillRect(10 + i * 8, 15 + i * 10, 100, 150, colorArray[i]);
		HAL_Delay(500);
	}
	HAL_Delay(1000);
	lcdFillRGB(COLOR_BLACK);
	for (int i = 0; i < 8; ++i)
	{
		tick = HAL_GetTick();
		lcdFillCircle(lcdGetWidth() / 2 + i * 8, lcdGetHeight() / 2 + i * 10, 100, colorArray[i]);
		lcdSetTextFont(&Font16);
		lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
		lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
		lcdPrintf("Time: %4lu ms", HAL_GetTick() - tick);
		HAL_Delay(500);
	}
	HAL_Delay(1000);
	lcdFillRGB(COLOR_BLACK);
	for (int i = 0; i < 8; ++i)
	{
		lcdFillTriangle(20 + i * 10, 40 + i * 15, 20 + i * 10 + 90, 40 + i * 15 + 90, 20 + i * 10 + 90, 40 + i * 15 + 20, colorArray[i]);
		HAL_Delay(500);
	}
	HAL_Delay(1000);
	lcdFillRGB(COLOR_BLACK);
	if (lcdGetOrientation() == LCD_ORIENTATION_LANDSCAPE || lcdGetOrientation() == LCD_ORIENTATION_LANDSCAPE_MIRROR)
	{
		tick = HAL_GetTick();
		lcdDrawImage((lcdGetWidth() - bmSTLogo.xSize) / 2, 0, &bmSTLogo);
		lcdSetTextFont(&Font16);
		lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
		lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
		lcdPrintf("Time: %4lu ms", HAL_GetTick() - tick);
	}
	else
	{
		tick = HAL_GetTick();
		lcdDrawImage(0, (lcdGetHeight() - bmSTLogo.ySize) / 2, &bmSTLogo);
		lcdSetTextFont(&Font16);
		lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
		lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
		lcdPrintf("Time: %4lu ms", HAL_GetTick() - tick);
	}
}
/* USER CODE END 4 */