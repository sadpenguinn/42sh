/*
**	size_t	ft_strlen(const char *str);
**			|			          |
**			|		              V
**	  %rax<-+                     %rdi
*/

.text
.global	_ft_strlen

_ft_strlen:
	mov		%rdi, %rax
loop:
	testb	$0xFF, (%rax)
	jz		rtn
	inc		%rax
	jmp		loop
rtn:
	sub		%rdi, %rax

	/* xor		%rcx, %rcx */
	/* not		%rcx */
	/* xor		%rax, %rax */
	/* repne	scasb */
	/* not		%rcx */
	/* dec		%rcx */
	/* mov		%rcx, %rax */

	/* mov		%rdi, %rsi */
	/* mov		%rdi, %rdx */
	/* and		$0b111, %rdx */
	/* cmp		$0,	%rdx */
	/* je		aligned */
	/* mov		$8,	%rcx */
	/* sub		%rdx, %rcx */

	/* xor		%rax, %rax */
	/* repne	scasb */
	/* testb	$0xFF, -1(%rdi) */
	/* je		rtn */

/* aligned: */
	/* mov		$0x0101010101010101, %r8 */
	/* mov		$0x8080808080808080, %r9 */

/* loop: */
	/* movq	(%rdi), %rdx */
	/* sub		%r8, %rdx */
	/* test	%r9, %rdx */
	/* jne		check */
	/* add		$8, %rdi */
	/* jmp		loop */

/* check: */
	/* xor		%rax, %rax */
	/* mov		$8, %rcx */
	/* repne	scasb */

/* rtn: */
	/* sub		%rsi, %rdi */
	/* mov		%rdi, %rax */
	/* dec		%rax */
	ret
