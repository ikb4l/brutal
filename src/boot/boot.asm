[BITS 32]
[GLOBAL start]
[EXTERN main]

section .multiboot
  align 4
  dd 0x1BADB002
  dd 0x00000000
  dd -(0x1BADB002)

section .text
  start:
    call main

