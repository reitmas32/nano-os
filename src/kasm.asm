;;kasm.asm
bits 32		;directiva nasm
section .text
	;Especificacion multiboot para que GRUB cargue el kernel
	align 4
	dd 0x1BADB002			;Campo magico que identifica la cabecera
	dd 0x00			;Campo flags en cero
	dd - (0x1BADB002 + 0x00)	;Campo checksum. m+f+c deben ser cero

global start

extern kmain				;La funcion kmain() esta definida en el archivo boot.c

start:
	cli				;block interrupts
	call kmain			;llama a kmain
	hlt				;detiene el CPU
	
section .bss
stack_space: resb 8192			; Pila de 8KB