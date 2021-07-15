#include <brutal/drivers/framebuffer.h>
#include <brutal/types.h>

struct fb_info_t fbinfo;

void fb_init(struct multiboot_info* info) {
  fbinfo.buffer = (uint32*) info->framebuffer_addr;
  fbinfo.width = info->framebuffer_width;
  fbinfo.height = info->framebuffer_height;
}

void fb_plot(uint32 x, uint32 y, uint32 color) {
  fbinfo.buffer[y * fbinfo.width + x] = color;
}

void fb_clear(uint32 color) {
  for(uint32 y = 0; y < fbinfo.height; y++) {
    for(uint32 x = 0; x < fbinfo.width; x++) {
      fb_plot(x, y, color);
    }
  }
}

struct fb_info_t* fb_info() {
  return &fbinfo;
}


