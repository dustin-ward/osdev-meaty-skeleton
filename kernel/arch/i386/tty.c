#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "vga.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;
 
size_t terminal_row;
size_t terminal_col;
uint8_t terminal_color;
uint16_t* terminal_buffer;

void terminal_init() {
	terminal_row = 0;
	terminal_col = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = VGA_MEMORY;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

void terminal_setcolor(uint8_t color) {
	terminal_color = color;
}
 
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c) {
	if (c == '\n') {
		terminal_col = VGA_HEIGHT-1;
	} else {
		terminal_putentryat(c, terminal_color, terminal_col, terminal_row);
	}
	if (++terminal_col == VGA_WIDTH) {
		terminal_col = 0;
		if (++terminal_row == VGA_HEIGHT)
			terminal_row = 0;
	}
}

void terminal_write(const char* str, size_t size) {
	for (size_t i = 0; i < size; i++) {
		terminal_putchar(str[i]);
	}
}

void terminal_writestring(const char* data) {
	terminal_write(data, strlen(data));
}
