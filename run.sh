#!/bin/bash

set -xue

# Environment variables
QEMU=$HOME/Projects/practice/qemu/build/qemu-system-riscv32
CC=clang
CFLAGS="-std=c11 -O2 -g3 -Wall -Wextra --target=riscv32-unknown-elf \
        -fno-stack-protector -ffreestanding -nostdlib -mno-relax"

# Build the kernel
$CC $CFLAGS -Wl,-Tkernel.ld -Wl,-Map=kernel.map -o kernel.elf \
    kernel.c common.c

# Start QEMU
$QEMU -machine virt -bios default -nographic -serial mon:stdio --no-reboot \
    -kernel kernel.elf
