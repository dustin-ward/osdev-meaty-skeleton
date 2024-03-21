.set MAGIC, 0x1BADB002	// Magic Number
.set FLAGS, 0b11		// Flags [Align, Memmap]

// Multiboot Header
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long -(MAGIC + FLAGS)	// Checksum

// Initial Stack
.section .bss
.align 16
stack_bottom:
.skip 0x4000
stack_top:

// Kernel Entry Point
.section .text
.global _start
.type _start, @function
_start:
	mov $stack_top, %esp	// Set stack pointer
	call _init				// Call global constructors
	call kernel_main		// Entry point into C
	cli
1:	hlt						// End of Kernel
	jmp 1b
.size _start, . - _start
