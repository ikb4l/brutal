#ifndef _TTY_H
  #define _TTY_H

  #include <brutal/types.h>
  #include <brutal/multiboot.h>

  struct tty_driver_t {
    uint32 bg;
    uint32 fg;
    uint8 padding_x;
    uint8 padding_y;
    uint32 cell_x;
    uint32 cell_y;
    uint32 width;
  };

  void tty_init(struct multiboot_info* info, uint32 bg, uint32 fg);
  void tty_putch(const char c);

#endif

