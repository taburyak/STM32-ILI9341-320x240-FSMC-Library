/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ili9341.h"
/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define min(a,b) (((a)<(b))?(a):(b))
/* USER CODE END PD */

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
void demoLCD(int i);
unsigned long testFillScreen();
unsigned long testText();
unsigned long testLines(uint16_t color);
unsigned long testFastLines(uint16_t color1, uint16_t color2);
unsigned long testRects(uint16_t color);
unsigned long testFilledRects(uint16_t color1, uint16_t color2);
unsigned long testFilledCircles(uint8_t radius, uint16_t color);
unsigned long testCircles(uint8_t radius, uint16_t color);
unsigned long testTriangles();
unsigned long testFilledTriangles();
unsigned long testRoundRects();
unsigned long testFilledRoundRects();
unsigned long testDrawImage();
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
	  i++;
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

/* USER CODE BEGIN 4 */
void demoLCD(int i)
{
	lcdSetOrientation(i % 4);

	uint32_t t = testFillScreen();
	lcdSetTextFont(&Font16);
	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("Time: %4lu ms", t);
	HAL_Delay(2000);

	t = HAL_GetTick();
	lcdTest();
	lcdSetTextFont(&Font16);
	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("Time: %4lu ms", HAL_GetTick() - t);
	HAL_Delay(2000);

	t = testText();
	lcdSetTextFont(&Font16);
	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("Time: %4lu ms", t);
	HAL_Delay(2000);

	lcdSetTextFont(&Font16);
	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("Time: %4lu ms", testLines(COLOR_CYAN));
	HAL_Delay(2000);

	lcdSetTextFont(&Font16);
	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("Time: %4lu ms", testFastLines(COLOR_RED, COLOR_BLUE));
	HAL_Delay(2000);

	lcdSetTextFont(&Font16);
	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("Time: %4lu ms", testRects(COLOR_GREEN));
	HAL_Delay(2000);

	lcdSetTextFont(&Font16);
	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("Time: %4lu ms", testFilledRects(COLOR_YELLOW, COLOR_MAGENTA));
	HAL_Delay(2000);

	lcdSetTextFont(&Font16);
	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("Time: %4lu ms", testFilledCircles(10, COLOR_MAGENTA));
	HAL_Delay(2000);

	lcdSetTextFont(&Font16);
	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("Time: %4lu ms", testCircles(10, COLOR_WHITE));
	HAL_Delay(2000);

	lcdSetTextFont(&Font16);
	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("Time: %4lu ms", testTriangles());
	HAL_Delay(2000);

	lcdSetTextFont(&Font16);
	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("Time: %4lu ms", testFilledTriangles());
	HAL_Delay(2000);

	lcdSetTextFont(&Font16);
	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("Time: %4lu ms", testRoundRects());
	HAL_Delay(2000);

	lcdSetTextFont(&Font16);
	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("Time: %4lu ms", testFilledRoundRects());
	HAL_Delay(2000);

	lcdSetTextFont(&Font16);
	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("Time: %4lu ms", testDrawImage());
	HAL_Delay(2000);
}

unsigned long testFillScreen()
{
	unsigned long start = HAL_GetTick(), t = 0;
	lcdFillRGB(COLOR_BLACK);
	t += HAL_GetTick() - start;
	lcdSetCursor(0, 0);
	lcdSetTextFont(&Font24);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("BLACK");
	HAL_Delay(1000);
	start = HAL_GetTick();
	lcdFillRGB(COLOR_RED);
	t += HAL_GetTick() - start;
	lcdSetCursor(0, 0);
	lcdSetTextFont(&Font24);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("RED");
	HAL_Delay(1000);
	start = HAL_GetTick();
	lcdFillRGB(COLOR_GREEN);
	t += HAL_GetTick() - start;
	lcdSetCursor(0, 0);
	lcdSetTextFont(&Font24);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("GREEN");
	HAL_Delay(1000);
	start = HAL_GetTick();
	lcdFillRGB(COLOR_BLUE);
	t += HAL_GetTick() - start;
	lcdSetCursor(0, 0);
	lcdSetTextFont(&Font24);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdPrintf("BLUE");
	HAL_Delay(1000);
	start = HAL_GetTick();
	lcdFillRGB(COLOR_BLACK);
	return t += HAL_GetTick() - start;
}

unsigned long testText()
{
	lcdFillRGB(COLOR_BLACK);
	unsigned long start = HAL_GetTick();
	lcdSetCursor(0, 0);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdSetTextFont(&Font8);
	lcdPrintf("Hello World!\r\n");
	lcdSetTextColor(COLOR_YELLOW, COLOR_BLACK);
	lcdSetTextFont(&Font12);
	lcdPrintf("%i\r\n", 1234567890);
	lcdSetTextColor(COLOR_RED, COLOR_BLACK);
	lcdSetTextFont(&Font16);
	lcdPrintf("%#X\r\n", 0xDEADBEEF);
	lcdPrintf("\r\n");
	lcdSetTextColor(COLOR_GREEN, COLOR_BLACK);
	lcdSetTextFont(&Font20);
	lcdPrintf("Groop\r\n");
	lcdSetTextFont(&Font12);
	lcdPrintf("I implore thee,\r\n");
	lcdSetTextFont(&Font12);
	lcdPrintf("my foonting turlingdromes.\r\n");
	lcdPrintf("And hooptiously drangle me\r\n");
	lcdPrintf("with crinkly bindlewurdles,\r\n");
	lcdPrintf("Or I will rend thee\r\n");
	lcdPrintf("in the gobberwarts\r\n");
	lcdPrintf("with my blurglecruncheon,\r\n");
	lcdPrintf("see if I don't!\r\n");
	return HAL_GetTick() - start;
}

unsigned long testLines(uint16_t color)
{
  unsigned long start, t;
  int           x1, y1, x2, y2,
                w = lcdGetWidth(),
                h = lcdGetHeight();

  lcdFillRGB(COLOR_BLACK);

  x1 = y1 = 0;
  y2    = h - 1;
  start = HAL_GetTick();
  for(x2 = 0; x2 < w; x2 += 6) lcdDrawLine(x1, y1, x2, y2, color);
  x2 = w - 1;
  for(y2 = 0; y2 < h; y2 += 6) lcdDrawLine(x1, y1, x2, y2, color);
  t = HAL_GetTick() - start; // fillScreen doesn't count against timing

  HAL_Delay(1000);
  lcdFillRGB(COLOR_BLACK);

  x1 = w - 1;
  y1 = 0;
  y2 = h - 1;

  start = HAL_GetTick();

  for(x2 = 0; x2 < w; x2 += 6) lcdDrawLine(x1, y1, x2, y2, color);
  x2 = 0;
  for(y2 = 0; y2 < h; y2 += 6) lcdDrawLine(x1, y1, x2, y2, color);
  t += HAL_GetTick() - start;

  HAL_Delay(1000);
  lcdFillRGB(COLOR_BLACK);

  x1 = 0;
  y1 = h - 1;
  y2 = 0;
  start = HAL_GetTick();

  for(x2 = 0; x2 < w; x2 += 6) lcdDrawLine(x1, y1, x2, y2, color);
  x2 = w - 1;
  for(y2 = 0; y2 < h; y2 += 6) lcdDrawLine(x1, y1, x2, y2, color);
  t += HAL_GetTick() - start;

  HAL_Delay(1000);
  lcdFillRGB(COLOR_BLACK);

  x1 = w - 1;
  y1 = h - 1;
  y2 = 0;

  start = HAL_GetTick();

  for(x2 = 0; x2 < w; x2 += 6) lcdDrawLine(x1, y1, x2, y2, color);
  x2 = 0;
  for(y2 = 0; y2 < h; y2 += 6) lcdDrawLine(x1, y1, x2, y2, color);

  return t += HAL_GetTick() - start;
}

unsigned long testFastLines(uint16_t color1, uint16_t color2)
{
  unsigned long start;
  int x, y, w = lcdGetWidth(), h = lcdGetHeight();

  lcdFillRGB(COLOR_BLACK);
  start = HAL_GetTick();
  for(y = 0; y < h; y += 5) lcdDrawHLine(0, w, y, color1);
  for(x = 0; x < w; x += 5) lcdDrawVLine(x, 0, h, color2);

  return HAL_GetTick() - start;
}

unsigned long testRects(uint16_t color)
{
  unsigned long start;
  int n, i, i2,
      cx = lcdGetWidth()  / 2,
      cy = lcdGetHeight() / 2;

  lcdFillRGB(COLOR_BLACK);
  n = min(lcdGetWidth(), lcdGetHeight());
  start = HAL_GetTick();
  for(i = 2; i < n; i += 6)
  {
    i2 = i / 2;
    lcdDrawRect(cx - i2, cy - i2, i, i, color);
  }

  return HAL_GetTick() - start;
}

unsigned long testFilledRects(uint16_t color1, uint16_t color2)
{
  unsigned long start, t = 0;
  int n, i, i2,
      cx = lcdGetWidth() / 2 - 1,
      cy = lcdGetHeight() / 2 - 1;

  lcdFillRGB(COLOR_BLACK);
  n = min(lcdGetWidth(), lcdGetHeight());

  for(i = n; i > 0; i -= 6)
  {
    i2 = i / 2;
    start = HAL_GetTick();
    lcdFillRect(cx-i2, cy-i2, i, i, color1);
    t    += HAL_GetTick() - start;
    // Outlines are not included in timing results
    lcdDrawRect(cx-i2, cy-i2, i, i, color1);
  }

  return t;
}

unsigned long testFilledCircles(uint8_t radius, uint16_t color)
{
  unsigned long start;
  int x, y, w = lcdGetWidth(), h = lcdGetHeight(), r2 = radius * 2;

  lcdFillRGB(COLOR_BLACK);
  start = HAL_GetTick();
  for(x = radius; x < w; x += r2)
  {
    for(y = radius; y < h; y += r2)
    {
      lcdFillCircle(x, y, radius, color);
    }
  }

  return HAL_GetTick() - start;
}

unsigned long testCircles(uint8_t radius, uint16_t color)
{
  unsigned long start;
  int x, y, r2 = radius * 2,
      w = lcdGetWidth()  + radius,
      h = lcdGetHeight() + radius;

  // Screen is not cleared for this one -- this is
  // intentional and does not affect the reported time.
  start = HAL_GetTick();
  for(x = 0; x < w; x += r2)
  {
    for(y = 0; y < h; y += r2)
    {
      lcdDrawCircle(x, y, radius, color);
    }
  }

  return HAL_GetTick() - start;
}

unsigned long testTriangles()
{
  unsigned long start;
  int n, i, cx = lcdGetWidth() / 2 - 1,
            cy = lcdGetHeight() / 2 - 1;

  lcdFillRGB(COLOR_BLACK);
  n = min(cx, cy);
  start = HAL_GetTick();
  for(i = 0; i < n; i += 5)
  {
    lcdDrawTriangle(
      cx    , cy - i, // peak
      cx - i, cy + i, // bottom left
      cx + i, cy + i, // bottom right
      lcdColor565(i, i, i));
  }

  return HAL_GetTick() - start;
}

unsigned long testFilledTriangles()
{
  unsigned long start, t = 0;
  int i, cx = lcdGetWidth() / 2 - 1,
         cy = lcdGetHeight() / 2 - 1;

  lcdFillRGB(COLOR_BLACK);
  for(i = min(cx, cy); i > 10; i -= 5)
  {
    start = HAL_GetTick();
    lcdFillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i, lcdColor565(0, i*10, i*10));
    t += HAL_GetTick() - start;
    lcdFillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i, lcdColor565(i*10, i*10, 0));
  }

  return t;
}

unsigned long testRoundRects()
{
  unsigned long start;
  int w, i, i2,
      cx = lcdGetWidth() / 2 - 1,
      cy = lcdGetHeight() / 2 - 1;

  lcdFillRGB(COLOR_BLACK);
  w = lcdGetWidth(), lcdGetHeight();
  start = HAL_GetTick();
  for(i = 0; i < w; i += 6)
  {
    i2 = i / 2;
    lcdDrawRoundRect(cx-i2, cy-i2, i, i, i/8, lcdColor565(i, 0, 0));
  }

  return HAL_GetTick() - start;
}

unsigned long testFilledRoundRects()
{
  unsigned long start;
  int i, i2,
      cx = lcdGetWidth()  / 2 - 1,
      cy = lcdGetHeight() / 2 - 1;

  lcdFillRGB(COLOR_BLACK);
  start = HAL_GetTick();
  for(i = min(lcdGetWidth(), lcdGetHeight()); i > 20; i -=6 )
  {
    i2 = i / 2;
    lcdFillRoundRect(cx - i2, cy - i2, i, i, i / 8, lcdColor565(0, i, 0));
  }

  return HAL_GetTick() - start;
}

unsigned long testDrawImage()
{
	unsigned long start;

	lcdFillRGB(COLOR_BLACK);
	start = HAL_GetTick();
	if (lcdGetOrientation() == LCD_ORIENTATION_LANDSCAPE || lcdGetOrientation() == LCD_ORIENTATION_LANDSCAPE_MIRROR)
	{
		lcdDrawImage((lcdGetWidth() - bmSTLogo.xSize) / 2, 0, &bmSTLogo);
	}
	else
	{
		lcdDrawImage(0, (lcdGetHeight() - bmSTLogo.ySize) / 2, &bmSTLogo);
	}
	return HAL_GetTick() - start;
}
/* USER CODE END 4 */