	.text
	.intel_syntax noprefix
	.file	"ft_strlen_v2.c"
	.globl	ft_strlen_avx                   # -- Begin function ft_strlen_avx
	.p2align	4, 0x90
	.type	ft_strlen_avx,@function
ft_strlen_avx:                          # @ft_strlen_avx
	.cfi_startproc
# %bb.0:
	test	rdi, rdi
	je	.LBB0_1
# %bb.2:
	mov	rcx, rdi
	mov	rax, rdi
	and	rcx, 31
	je	.LBB0_5
# %bb.3:
	vpxor	xmm0, xmm0, xmm0
	vpcmpeqb	ymm0, ymm0, ymmword ptr [rdi]
	vpmovmskb	eax, ymm0
	test	eax, eax
	je	.LBB0_4
# %bb.9:
	bsf	eax, eax
	vzeroupper
	ret
.LBB0_4:
	mov	rax, rdi
	sub	rax, rcx
	add	rax, 32
.LBB0_5:
	prefetchnta	byte ptr [rax + 64]
	mov	rcx, rax
	sub	rcx, rdi
	add	rcx, -32
	sub	rax, -128
	vpxor	xmm0, xmm0, xmm0
	.p2align	4, 0x90
.LBB0_6:                                # =>This Inner Loop Header: Depth=1
	prefetchnta	byte ptr [rax]
	vpcmpeqb	ymm1, ymm0, ymmword ptr [rax - 128]
	vpmovmskb	edx, ymm1
	add	rcx, 32
	add	rax, 32
	test	edx, edx
	je	.LBB0_6
# %bb.7:
	bsf	eax, edx
	add	rax, rcx
	vzeroupper
	ret
.LBB0_1:
	xor	eax, eax
	ret
.Lfunc_end0:
	.size	ft_strlen_avx, .Lfunc_end0-ft_strlen_avx
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 12.0.1-19ubuntu3"
	.section	".note.GNU-stack","",@progbits
	.addrsig
