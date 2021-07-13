/**
 * brutal/drivers/vga.c
 *
 * This file is part of Brutal which is released
 * under the Apache License 2.0. See file LICENSE.
 *
 * Copyright (c) 2021 ikb4l
 */

#include <brutal/drivers/vga.h>

struct vga_driver_t driver;

void vga_init() {
  struct vga_config_t config;
  config.fore_color = GREY;
  config.back_color = BLACK;

  driver.video_memory = (uint16*) VGA_ADDRESS;
  driver.vga_col = 0;
  driver.vga_row = 0;
  driver.config = config;

  for(uint16 i = 0; i < VGA_HEIGHT*VGA_WIDTH; i++) {
    vga_putch(0);
  }

  driver.vga_col = 0;
  driver.vga_row = 0;
}

uint16 vga_create_entry(const char c) {
  uint16 entry = (driver.config.back_color << 4 | driver.config.fore_color) << 8;
  entry |= c;
  return entry;
}

void vga_putch(const char c) {
  if(c == '\n') {
    driver.vga_col = 0;
    ++driver.vga_row;
  } else {
    uint16 entry = vga_create_entry(c);
    driver.video_memory[driver.vga_row * VGA_WIDTH + driver.vga_col] = entry;
    if(++driver.vga_col == VGA_WIDTH) {
      ++driver.vga_row;
    }
  }
}

void vga_set_fg(enum vga_color_t color) {
  driver.config.fore_color = color;
}

void vga_set_bg(enum vga_color_t color) {
  driver.config.back_color = color;
}

