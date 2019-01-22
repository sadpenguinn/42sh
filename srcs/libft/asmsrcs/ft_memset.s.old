/*
** void *ft_memset(void *buff, int byte, size_t buffsize);
**       |               |         |            |
**       |               v         v            v
** %rax<-+               %rdi      %rsi         %rdx
*/

.text
.globl  _ft_memset

_ft_memset:
	pushq	%rdi
	and		$0xff, %rsi

	cmp		$10000, %rdx
	jb		smallsize

	mov		%rsi, %rax			/*	Помещаем заполнитель в RAX	*/
	shl		$8, %rax			/*	Сдвигаем его на 8 бит (RAX << 8)	*/
	or		%rax, %rsi			/*	получаем 0:0:0:0:0:0:b:b	*/
	or		%rsi, %rax			/*		*/
	shl		$16, %rax			/*		*/
	or		%rax, %rsi			/*	получаем 0:0:0:0:b:b:b:b	*/
	or		%rsi, %rax			/*		*/
	shl		$32, %rax			/*		*/
	or		%rax, %rsi			/*	получаем b:b:b:b:b:b:b:b	*/
	or		%rsi, %rax

/*
** buff:RDI byte:RAX buffend:RDX
*/

	mov		%rdx, %rcx
	shr		$3, %rcx
	rep		stosq

	mov		%rdx, %rcx
	and		$7, %rcx
	rep		stosb

rtn:
	popq	%rax
	ret

smallsize:
	mov		%rsi, %rax
	mov		%rdx, %rcx
	rep		stosb
	popq	%rax
	ret
