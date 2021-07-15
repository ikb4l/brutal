; brutal/boot/boot.asm
;
; This file is part of Brutal which is released
; under the Apache License 2.0. See file LICENSE.
;
; Copyright (c) 2021 ikb4l

[BITS 32]
[GLOBAL START]
[EXTERN main]

%DEFINE MAGIC         0x1BADB002
%DEFINE FLAGS         0x00000007

SECTION .multiboot
  ALIGN 4
  DD MAGIC
  DD FLAGS
  DD -(MAGIC + FLAGS)
  DD 0, 0, 0, 0, 0
  DD 0
  DD 0, 0, 0

SECTION .text
  START:
    PUSH EBX
    PUSH EAX
    CALL main

    .HALT:
      HLT
      JMP .HALT

