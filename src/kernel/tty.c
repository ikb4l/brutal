#include <brutal/tty.h>

void tty_init() {
  con_init();
}

void kprint(char* buf) {
  while(*buf) {
    con_write(*buf);
    buf++;
  }
}

