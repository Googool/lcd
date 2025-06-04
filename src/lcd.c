#include "pico/lcd.h"
#include "pico/stdlib.h"

#include <stdint.h>
#include <math.h>

static lcd_t instance;

static uint8_t madctl;
static uint16_t caset[2];
static uint16_t raset[2];

static void write_blocking_dma(const uint8_t *src, size_t len) {
  gpio_put(instance.dc, 1);
  gpio_put(instance.cs, 0);
  while (dma_channel_is_busy(instance.dma)) tight_loop_contents();
  dma_channel_set_trans_count(instance.dma, len, false);
  dma_channel_set_read_addr(instance.dma, src, true);
  dma_channel_start(instance.dma);
  while (dma_channel_is_busy(instance.dma)) tight_loop_contents();
  gpio_put(instance.cs, 1);
}

static void write_command(uint8_t cmd) {
  gpio_put(instance.dc, 0);
  gpio_put(instance.cs, 0);
  spi_write_blocking(instance.spi, &cmd, sizeof(cmd));
  gpio_put(instance.cs, 1);
}

static void write_data(const uint8_t *data, size_t len) {
  gpio_put(instance.dc, 1);
  gpio_put(instance.cs, 0);
  spi_write_blocking(instance.spi, data, len);
  gpio_put(instance.cs, 1);
}

static void set_address_window(uint16_t x, uint16_t y, uint16_t w, uint16_t h) {
  //
}
