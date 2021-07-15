/**
 * brutal/init/main.c
 *
 * This file is part of Brutal which is released
 * under the Apache License 2.0. See file LICENSE.
 *
 * Copyright (c) 2021 ikb4l
 */

#include <brutal/types.h>
#include <brutal/multiboot.h>
#include <brutal/drivers/tty/tty.h>
#include <libk/io.h>

uint32* buffer;
uint32 width;
uint32 height;

void plot(int x, int y, uint32 color) {
  buffer[y * width + x] = color;
}

void main(uint32 magic, struct multiboot_info* boot_info) {
  tty_init(boot_info, 0x000000, 0xFFFFFF);

  if(magic != MB_BOOTLOADER_MAGIC) {
    print("Invalid bootloader. Halting.");
    for(;;) {}
  }
}

