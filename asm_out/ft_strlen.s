	.text
	.intel_syntax noprefix
	.file	"ft_strlen.c"
	.globl	ft_strlen                       # -- Begin function ft_strlen
	.p2align	4, 0x90
	.type	ft_strlen,@function
ft_strlen:                              # @ft_strlen
	.cfi_startproc
# %bb.0:
	mov	rax, rdi
	mov	rcx, rdi
	and	rax, 31
	je	.LBB0_5
# %bb.1:
	mov	ecx, 32
	sub	rcx, rax
	xor	eax, eax
	.p2align	4, 0x90
.LBB0_2:                                # =>This Inner Loop Header: Depth=1
	cmp	byte ptr [rdi + rax], 0
	je	.LBB0_8
# %bb.3:                                #   in Loop: Header=BB0_2 Depth=1
	add	rax, 1
	cmp	rcx, rax
	jne	.LBB0_2
# %bb.4:
	add	rcx, rdi
.LBB0_5:
	mov	rdx, rcx
	sub	rdx, rdi
	add	rdx, -32
	add	rcx, 32
	.p2align	4, 0x90
.LBB0_6:                                # =>This Inner Loop Header: Depth=1
	vmovdqu	ymm0, ymmword ptr [rcx - 32]
	prefetcht0	byte ptr [rcx]
	add	rdx, 32
	add	rcx, 32
	vptest	ymm0, ymm0
	je	.LBB0_6
# %bb.7:
	vpxor	xmm1, xmm1, xmm1
	vpcmpeqb	ymm0, ymm0, ymm1
	vpmovmskb	eax, ymm0
	bsf	eax, eax
	add	rax, rdx
.LBB0_8:
	vzeroupper
	ret
.Lfunc_end0:
	.size	ft_strlen, .Lfunc_end0-ft_strlen
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 12.0.1-19ubuntu3"
	.section	".note.GNU-stack","",@progbits
	.addrsig
