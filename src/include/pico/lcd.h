#ifndef _LCD_H_
#define _LCD_H_

#include "hardware/spi.h"
#include "hardware/pwm.h"
#include "hardware/dma.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MADCTL_MY  0x80  // Row Address Order
#define MADCTL_MX  0x40  // Column Address Order
#define MADCTL_MV  0x20  // Row/Column Exchange
#define MADCTL_BGR 0x08  // BGR color order

typedef struct  {
  spi_inst_t *spi;
  uint8_t     mosi, sck, cs, dc, rst, blk, dma;
  uint16_t    width, height;
  uint16_t    x_offset, y_offset;
} lcd_t;

typedef enum {
  ROTATE_0,
  ROTATE_90,
  ROTATE_180,
  ROTATE_270
} lcd_rotation_t;

#ifdef __cplusplus
}
#endif

#endif /* _LCD_H_ */
