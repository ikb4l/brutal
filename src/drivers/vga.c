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

void vga_init(enum vga_color_t def_fg, enum vga_color_t def_bg) {
  struct vga_config_t config;
  config.def_fg = def_fg;
  config.def_bg = def_bg;
  config.fg = config.def_fg;
  config.bg = config.def_bg;

  driver.video_memory = (uint16*) VGA_ADDRESS;
  driver.vga_col = 0;
  driver.vga_row = 0;
  driver.config = config;

  vga_clear_buffer();
}

void vga_reset() {
  vga_colors_default();
  vga_clear_buffer();
}

void vga_clear_buffer() {
  vga_clear_positions();
  for(uint16 y = 0; y < VGA_HEIGHT; y++) {
    for(uint16 x = 0; x < VGA_WIDTH; x++) {
      vga_putch('\0');
    }
  }
  vga_clear_positions();
}

void vga_clear_positions() {
  driver.vga_col = 0;
  driver.vga_row = 0;
}

void vga_set_fg(enum vga_color_t color) {
  driver.config.fg = color;
}

void vga_set_bg(enum vga_color_t color) {
  driver.config.bg = color;
}

void vga_colors_default() {
  driver.config.fg = driver.config.def_fg;
  driver.config.bg = driver.config.def_bg;
}

uint16 vga_create_entry(const char c) {
  uint16 entry = (driver.config.bg << 4 | driver.config.fg) << 8;
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
      driver.vga_col = 0;
      ++driver.vga_row;
    }
  }
}

