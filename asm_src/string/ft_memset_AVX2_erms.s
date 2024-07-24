section .text
global ft_memset_avx_erms

ft_memset_avx_erms:
	test edi, edi
	vmovd xmm0, edi
	mov rax, rsi
	and rsi, 31
	vpbroadcastb ymm0, xmm0
	vmovdqa ymm1, ymm0
	mov rcx, rdx

.loop:
	prefetcht0 [rax + 32]
	vmovntdq [rax], ymm1
	add rax, 32
	sub rcx, 32
	jnz .loop

	ret

