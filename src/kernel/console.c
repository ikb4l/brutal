#include <brutal/tty.h>

size_t CON_COL;
size_t CON_ROW;
uint8 CON_DEF_COLOR;
uint16* VGA_BUFFER;

void con_init() {
  CON_COL = 0;
  CON_ROW = 0;
  CON_DEF_COLOR = (0x00 << 4) | 0x07;
  VGA_BUFFER = (uint16*) VGA_ADDRESS;

  for(size_t x = 0; x < VGA_WIDTH; x++) {
    for(size_t y = 0; y < VGA_HEIGHT; y++) {
      VGA_BUFFER[y * VGA_WIDTH + x] = (CON_DEF_COLOR << 8) | '\0';
    }
  }
}

void con_write(const char c) {
  uint16 entry = (CON_DEF_COLOR << 8) | c;
  VGA_BUFFER[CON_ROW * VGA_WIDTH + CON_COL] = entry;
  ++CON_COL;
}

