/*
**	void	*ft_memcpy(void *dst, const void *src, size_t size);
**		     |			     |                |           |
**		     |		         V                V           V
**	   %rax<-+               %rdi             %rsi        %rdx
*/

.text
.global _ft_memcpy

_ft_memcpy:
	mov		%rdi, %r8

	mov		%rdx, %rcx
	shr		$3, %rcx

	rep		movsq

	mov		%rdx, %rcx
	and		$7, %rcx

	rep		movsb

	mov		%r8, %rax
	ret
