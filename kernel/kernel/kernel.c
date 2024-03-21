#include <stdio.h>
#include <kernel/tty.h>

#if defined(__linux__) || !defined(__i386__)
#error "Not using proper cross-compiler setup"
#endif

void kernel_main(void) {
	terminal_init();

	terminal_setcolor(1);
	printf("H");
	terminal_setcolor(2);
	printf("e");
	terminal_setcolor(3);
	printf("l");
	terminal_setcolor(4);
	printf("l");
	terminal_setcolor(5);
	printf("o");
	terminal_setcolor(15);
	printf(" from the kernel with freestanding libc!\n");
}
