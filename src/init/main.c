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

#define USE_VGA_TEXT_MODE 0

void panic(const char* c) {
  vga_reset();
  print("[ PANIC ] ");
  puts(c);
}

uint32* buffer;
uint32 width;
uint32 height;

void plot(int x, int y, uint32 color) {
  buffer[y * width + x] = color;
}

void main(uint32 magic, struct multiboot_info* boot_info) {
  if(USE_VGA_TEXT_MODE) {
    vga_init(WHITE, BLACK);
  }

  if(magic != MB_BOOTLOADER_MAGIC) {
    panic("Wrong bootloader. Halting.");
  }
  width = boot_info->framebuffer_width;
  height = boot_info->framebuffer_height;
  buffer = (uint32*) boot_info->framebuffer_addr;

  for(int i = 0; i < 350; i++) {
    for(int j = 1; j < 100; j++) {
      plot(j, i, 0x41D0EE);
    }
  }
  
  for(int i = 0; i < 350; i++) {
    for(int j = 100; j < 200; j++) {
      plot(j, i, 0xF69AC9);
    }
  }

  for(int i = 0; i < 350; i++) {
    for(int j = 200; j < 300; j++) {
      plot(j, i, 0xFFFFFF);
    }
  }

  for(int i = 0; i < 350; i++) {
    for(int j = 300; j < 400; j++) {
      plot(j, i, 0xF69AC9);
    }
  }

  for(int i = 0; i < 350; i++) {
    for(int j = 400; j < 500; j++) {
      plot(j, i, 0x41D0EE);
    }
  }

  // made for testing, sorry for the shitcode 

  for(;;){}
}

