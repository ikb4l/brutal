/**
 * brutal/init/main.c
 *
 * This file is part of Brutal which is released
 * under the Apache License 2.0. See file LICENSE.
 *
 * Copyright (c) 2021 ikb4l
 */

#include <brutal/drivers/vga.h>
#include <brutal/types.h>
#include <libk/io.h>

#define USE_VGA_TEXT_MODE 1

void panic(const char* c) {
  vga_set_fg(BRIGHT_RED);
  puts("BRUTAL PANIC");
  vga_set_fg(GREY);
  vga_set_bg(BLACK);
  puts(c);

  for(;;) {}
}

void main(uint32 magic) {
  if(USE_VGA_TEXT_MODE) {
    vga_init();
  }

  if(magic != 0x2BADB002) {
    panic("Wrong bootloader. Halting.");
  }

  puts("Hello, Brutal!");
}

