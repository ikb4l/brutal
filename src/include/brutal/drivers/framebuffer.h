#ifndef _FB_H
  #define _FB_H

  #include <brutal/types.h>
  #include <brutal/multiboot.h>
  
  struct fb_info_t {
    uint32* buffer;
    uint32 width;
    uint32 height;
  };

  void fb_init(struct multiboot_info* info);
  void fb_plot(uint32 x, uint32 y, uint32 color);
  void fb_clear(uint32 color);
  struct fb_info_t* fb_info();

#endif

