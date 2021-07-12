/**
 * brutal/init/main.c
 *
 * This file is part of Brutal which is released
 * under the Apache License 2.0. See file LICENSE.
 *
 * Copyright (c) 2021 ikb4l
 */

#include <brutal/tty.h>

void main(void) {
  tty_init();
  kprint("Hello Brutal!");
  for(;;) {}
}

