.PHONY: all clean run

ASM = nasm
ASM_FLAGS = -f elf32
CC = gcc
CC_FLAGS = -Isrc/include -nostdlib -ffreestanding -m32
LD = ld
LD_FLAGS = -T scripts/linker.ld -m elf_i386

C_SOURCES = $(shell find src/ -type f -name '*.c')
ASM_SOURCES = $(shell find src/ -type f -name '*.asm')
OBJECTS = $(C_SOURCES:.c=.o) $(ASM_SOURCES:.asm=.o)

TARGET = brutal.elf
IMAGE = brutal.iso

$(IMAGE): $(TARGET)
	@mkdir -p iso/boot/grub
	@mv brutal.elf iso/boot
	@cp scripts/grub.cfg iso/boot/grub
	@grub-mkrescue -o brutal.iso iso
	@rm -rf iso

$(TARGET): $(OBJECTS)
	@echo Link: $(TARGET)
	@$(LD) $(LD_FLAGS) $(OBJECTS) -o $(TARGET)
	@echo DONE!

%.o: %.c
	@echo Compile: $@
	@$(CC) $(CC_FLAGS) -c $< -o $@

%.o: %.asm
	@echo Assemble: $@
	@$(ASM) $(ASM_FLAGS) -o $@ $<

clean:
	@echo Clean
	@rm $(OBJECTS) $(TARGET)

all: clean $(TARGET)

run: $(IMAGE)
	@qemu-system-i386 -cdrom brutal.iso

