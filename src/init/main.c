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
#include <brutal/multiboot.h>
#include <libk/io.h>

#define USE_VGA_TEXT_MODE 1

void panic(const char* c) {
  vga_reset();
  print("[ PANIC ] ");
  puts(c);

  for(;;) {}
}

void main(uint32 magic) {
  if(USE_VGA_TEXT_MODE) {
    vga_init(WHITE, BLACK);
  }

  if(magic != MB_BOOTLOADER_MAGIC) {
    panic("Wrong bootloader. Halting.");
  }
  
  print("hello world");
}

