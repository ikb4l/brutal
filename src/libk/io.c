/**
 * brutal/libk/io.c
 *
 * This file is part of Brutal which is released
 * under the Apache License 2.0. See file LICENSE.
 *
 * Copyright (c) 2021 ikb4l
 */

#include <brutal/drivers/tty/tty.h>
#include <libk/io.h>

void print(const char* c) {
  while(*c) {
    tty_putch(*c);
    c++;
  }
}

