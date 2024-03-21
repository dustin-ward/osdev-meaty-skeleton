#include <stdio.h>
#include <kernel/tty.h>

#if defined(__linux__) || !defined(__i386__)
#error "Not using proper cross-compiler setup"
#endif

void kernel_main(void) {
	terminal_init();
	printf("Hello from my libc!\n");
}
