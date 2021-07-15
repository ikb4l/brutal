; brutal/boot/boot.asm
;
; This file is part of Brutal which is released
; under the Apache License 2.0. See file LICENSE.
;
; Copyright (c) 2021 ikb4l

[BITS 32]
[GLOBAL start]
[EXTERN main]

%define MAGIC         0x1BADB002
%define FLAGS         0x00000007

section .multiboot
  align 4
  dd MAGIC
  dd FLAGS
  dd -(MAGIC + FLAGS)
  dd 0, 0, 0, 0, 0
  dd 0
  dd 0, 0, 0

section .text
  start:
    push ebx
    push eax
    call main

