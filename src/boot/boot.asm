; brutal/boot/boot.asm
;
; This file is part of Brutal which is released
; under the Apache License 2.0. See file LICENSE.
;
; Copyright (c) 2021 ikb4l


[BITS 32]
[GLOBAL start]
[EXTERN main]

%define FLAGS 0x00000000
%define MAGIC 0x1BADB002

section .multiboot
  align 4
  dd MAGIC
  dd FLAGS
  dd -(MAGIC + FLAGS)

section .text
  start:
    push eax
    call main

