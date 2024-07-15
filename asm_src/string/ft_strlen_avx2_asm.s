section .text
global ft_strlen_avx_asm


ft_strlen_avx_asm:
	test rdi, rdi
	jz .return_zero

	mov rcx, rdi
	mov rax, rdi
	and rcx, 31
	jz .aligned

	vpxor ymm0, ymm0, ymm0
	vmovdqu ymm1, [rdi]
	vpcmpeqb ymm1, ymm0, ymm1
	vpmovmskb eax, ymm1
	test eax, eax
	jz .unaligned_next
	bsf eax, eax
	ret

.unaligned_next:
	neg rcx
	lea rax, [rdi + rcx]
	add rax, 32

.aligned:
	prefetchnta [rax + 32]
	mov rcx, rax
	sub rcx, rdi
	add rcx, -32
	add rax, 32
	vpxor ymm0, ymm0, ymm0

.align_loop:
	prefetchnta [rax + 32]
	vmovdqa ymm1, [rax - 32]
	vpcmpeqb ymm1, ymm0, ymm1
	vpmovmskb edx, ymm1
	add rcx, 32
	add rax, 32
	test edx, edx
	jz .align_loop
	bsf eax, edx
	add rax, rcx
	ret

.return_zero:
	xor eax, eax
	ret


