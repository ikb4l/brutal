ENTRY(start)
SECTIONS {
  . = 0x100000;

  .multiboot BLOCK(4K) : ALIGN(4K) {
    *(.multiboot)
  }

  .text : {
    *(.text)
  }

  .data : {
    *(.data)
  }

  .bss : {
    *(.bss)
  }
}

