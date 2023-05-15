; lab 4, variant 18
; nasm -f elf64 name.asm
; ld -o name name.o

section .text
global product_asm

; product_asm
; equal to int32_t product_asm(int32_t* arr,
;			    int32_t arr_siz,
;			    int32_t lower,
;			    int32_t upper);
; Input:
; RDI = a pointer to the first element of the array
; ESI = array's size
; EDX = lower bound
; ECX = upper bound
; Output:
; EAX = a product of all the elements in the array
product_asm:
	push rbp
	mov rbp, rsp

	mov rbp, rdi ; save the address of the first element
	mov r8d, 0 ; counter
	mov eax, 1 ; result
.loop:
	mov r9d, dword [rbp] ; save the current integer
	cmp r8d, esi ; compare counter and size
	je .done ; done if equal

	cmp r9d, edx ; compare array[counter] with lower bound
	jl .skip ; skip if less

	cmp r9d, ecx ; compare array[counter] with upper bound
	jg .skip ; skip if bigger

	imul eax, r9d ; result = result * array[counter]
.skip:
	add rbp, 4 ; array++
	inc r8d ; counter++

	jmp .loop
.done:
	pop	rbp
	ret
