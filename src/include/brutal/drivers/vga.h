#ifndef _VGA_H
  #include <brutal/types.h>

  #define _VGA_H

  #define VGA_ADDRESS 0xB8000
  #define VGA_WIDTH   80
  #define VGA_HEIGHT  25

  enum vga_color_t {
    BLACK = 0,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARK_GREY,
    BRIGHT_BLUE,
    BRIGHT_GREEN,
    BRIGHT_CYAN,
    BRIGHT_RED,
    BRIGHT_MAGENTA,
    YELLOW,
    WHITE
  };

  struct vga_config_t {
    enum vga_color_t fore_color;
    enum vga_color_t back_color;
  };

  struct vga_driver_t {
    uint16* video_memory;
    uint16 vga_col;
    uint16 vga_row;
    struct vga_config_t config;
  };

  void vga_init();
  uint16 vga_create_entry(const char c);
  void vga_putch(const char c);
  void vga_set_fg(enum vga_color_t color);
  void vga_set_bg(enum vga_color_t color);

#endif

