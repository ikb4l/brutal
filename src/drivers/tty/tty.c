#include <brutal/drivers/tty/tty.h>
#include <brutal/drivers/framebuffer.h>
#include <brutal/drivers/tty/font.h>

struct tty_driver_t driver;

void tty_init(struct multiboot_info* info, uint32 bg, uint32 fg) {
  driver.bg = bg;
  driver.fg = fg;
  driver.cell_x = 0;
  driver.cell_y = 0;
  fb_init(info);
  fb_clear(bg);
}

void tty_putch(const char c) {
  for(uint8 iy = 0; iy < 8; iy++) {
    for(uint8 ix = 0; ix < 8; ix++) {
      fb_plot(
        ix + driver.cell_x * 8,
        iy + driver.cell_y * 8,
        driver.bg
      );

      if(
        (FONT[(uint8)c][iy] >> ix) & 1
      ) {
        fb_plot(
          ix + driver.cell_x * 8,
          iy + driver.cell_y * 8,
          driver.fg
        );
      }
    }
  }

  if(++driver.cell_x*8 >= fb_info()->width) {
    driver.cell_x = 0;
    ++driver.cell_y;
  }
}

