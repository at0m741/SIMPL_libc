	.text
	.intel_syntax noprefix
	.file	"ft_strlen.c"
	.globl	ft_strlen                       # -- Begin function ft_strlen
	.p2align	4, 0x90
	.type	ft_strlen,@function
ft_strlen:                              # @ft_strlen
	.cfi_startproc
# %bb.0:
	mov	rcx, rdi
	mov	rax, rdi
	and	rcx, 31
	je	.LBB0_3
# %bb.1:
	vpxor	xmm0, xmm0, xmm0
	vpcmpeqb	ymm0, ymm0, ymmword ptr [rdi]
	vpmovmskb	eax, ymm0
	test	eax, eax
	je	.LBB0_2
# %bb.7:
	bsf	eax, eax
	vzeroupper
	ret
.LBB0_2:
	mov	rax, rdi
	sub	rax, rcx
	add	rax, 32
.LBB0_3:
	prefetcht0	byte ptr [rax]
	vpxor	xmm0, xmm0, xmm0
	vpcmpeqb	ymm1, ymm0, ymmword ptr [rax]
	vpmovmskb	edx, ymm1
	test	edx, edx
	je	.LBB0_6
# %bb.4:
	mov	rcx, rax
	jmp	.LBB0_5
	.p2align	4, 0x90
.LBB0_6:                                # =>This Inner Loop Header: Depth=1
	lea	rcx, [rax + 32]
	prefetcht0	byte ptr [rax + 32]
	prefetcht0	byte ptr [rax + 4128]
	vpcmpeqb	ymm1, ymm0, ymmword ptr [rax + 32]
	vpmovmskb	edx, ymm1
	mov	rax, rcx
	test	edx, edx
	je	.LBB0_6
.LBB0_5:
	sub	rcx, rdi
	bsf	eax, edx
	add	rax, rcx
	vzeroupper
	ret
.Lfunc_end0:
	.size	ft_strlen, .Lfunc_end0-ft_strlen
	.cfi_endproc
                                        # -- End function
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	push	rax
	.cfi_def_cfa_offset 16
	lea	rax, [rip + .L.str]
	test	al, 31
	jne	.LBB1_2
# %bb.1:
	prefetcht0	byte ptr [rip + .L.str]
.LBB1_2:
	lea	rdi, [rip + .L.str.1]
	mov	esi, 13
	xor	eax, eax
	call	printf@PLT
	lea	rdi, [rip + .L.str.2]
	mov	esi, 13
	xor	eax, eax
	call	printf@PLT
	lea	rax, [rip + .L.str.3]
	mov	rcx, rax
	and	rcx, -32
	add	rcx, 32
	test	al, 31
	mov	rdx, rcx
	cmove	rdx, rax
	prefetcht0	byte ptr [rdx]
	vpxor	xmm0, xmm0, xmm0
	vpcmpeqb	ymm1, ymm0, ymmword ptr [rdx]
	vpmovmskb	esi, ymm1
	test	esi, esi
	jne	.LBB1_5
# %bb.3:
	test	al, 31
	cmove	rcx, rax
	.p2align	4, 0x90
.LBB1_4:                                # =>This Inner Loop Header: Depth=1
	lea	rdx, [rcx + 32]
	prefetcht0	byte ptr [rcx + 32]
	prefetcht0	byte ptr [rcx + 4128]
	vpcmpeqb	ymm1, ymm0, ymmword ptr [rcx + 32]
	vpmovmskb	esi, ymm1
	mov	rcx, rdx
	test	esi, esi
	je	.LBB1_4
.LBB1_5:
	sub	rdx, rax
	bsf	esi, esi
	add	rsi, rdx
	lea	rdi, [rip + .L.str.1]
	xor	eax, eax
	vzeroupper
	call	printf@PLT
	lea	rdi, [rip + .L.str.2]
	mov	esi, 90
	xor	eax, eax
	call	printf@PLT
	xor	eax, eax
	pop	rcx
	.cfi_def_cfa_offset 8
	ret
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Hello, world!"
	.size	.L.str, 14

	.type	.L.str.1,@object                # @.str.1
.L.str.1:
	.asciz	"ft_strlen: %zu\n"
	.size	.L.str.1, 16

	.type	.L.str.2,@object                # @.str.2
.L.str.2:
	.asciz	"strlen: %zu\n"
	.size	.L.str.2, 13

	.type	.L.str.3,@object                # @.str.3
.L.str.3:
	.asciz	"This is a much longer string that we are using to test the AVX2 optimized strlen function."
	.size	.L.str.3, 91

	.ident	"Ubuntu clang version 14.0.0-1ubuntu1.1"
	.section	".note.GNU-stack","",@progbits
	.addrsig
