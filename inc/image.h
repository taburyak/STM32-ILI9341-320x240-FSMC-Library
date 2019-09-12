/*
 * image.h
 *
 *  Created on: 31 ρεπο. 2019 π.
 *      Author: tabur
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include <stdint.h>

typedef struct _tImage
{
  uint16_t 					xSize;
  uint16_t 					ySize;
  uint16_t 					bytesPerLine;
  uint8_t					bitsPerPixel;
  const unsigned char* 		pData;
} sImage;

#define GUI_BITMAP			sImage
#define GUI_CONST_STORAGE	const

extern GUI_CONST_STORAGE GUI_BITMAP bmSTLogo;

#endif /* IMAGE_H_ */
