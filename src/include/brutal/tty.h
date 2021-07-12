#ifndef _TTY_H
#define _TTY_H

#include <brutal/types.h>
#include <stddef.h>

#define VGA_ADDRESS 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

void tty_init(void);
void kprint(char* buf);

void con_init(void);
void con_write(const char c);

#endif

