	.text
	.intel_syntax noprefix
	.file	"ft_strlen.c"
	.globl	ft_strlen                       # -- Begin function ft_strlen
	.p2align	4, 0x90
	.type	ft_strlen,@function
ft_strlen:                              # @ft_strlen
	.cfi_startproc
# %bb.0:
	test	rdi, rdi
	je	.LBB0_41
# %bb.1:
	prefetcht0	byte ptr [rdi]
	prefetcht0	byte ptr [rdi + 32]
	vmovdqu	xmm0, xmmword ptr [rdi]
	vpxor	xmm1, xmm1, xmm1
	vpcmpeqb	xmm1, xmm0, xmm1
	vpmovmskb	eax, xmm1
	test	ax, ax
	je	.LBB0_18
# %bb.2:
	vmovd	eax, xmm0
	test	al, al
	je	.LBB0_41
# %bb.3:
	cmp	byte ptr [rdi + 1], 0
	je	.LBB0_28
# %bb.4:
	cmp	byte ptr [rdi + 2], 0
	je	.LBB0_29
# %bb.5:
	cmp	byte ptr [rdi + 3], 0
	je	.LBB0_30
# %bb.6:
	cmp	byte ptr [rdi + 4], 0
	je	.LBB0_31
# %bb.7:
	cmp	byte ptr [rdi + 5], 0
	je	.LBB0_32
# %bb.8:
	cmp	byte ptr [rdi + 6], 0
	je	.LBB0_33
# %bb.9:
	cmp	byte ptr [rdi + 7], 0
	je	.LBB0_34
# %bb.10:
	cmp	byte ptr [rdi + 8], 0
	je	.LBB0_35
# %bb.11:
	cmp	byte ptr [rdi + 9], 0
	je	.LBB0_36
# %bb.12:
	cmp	byte ptr [rdi + 10], 0
	je	.LBB0_37
# %bb.13:
	cmp	byte ptr [rdi + 11], 0
	je	.LBB0_38
# %bb.14:
	cmp	byte ptr [rdi + 12], 0
	je	.LBB0_39
# %bb.15:
	cmp	byte ptr [rdi + 13], 0
	je	.LBB0_40
# %bb.16:
	cmp	byte ptr [rdi + 14], 0
	je	.LBB0_42
# %bb.17:
	cmp	byte ptr [rdi + 15], 0
	je	.LBB0_43
.LBB0_18:
	lea	r8, [rdi + 16]
	mov	rsi, r8
	mov	rcx, r8
	and	rsi, 31
	je	.LBB0_23
# %bb.19:
	mov	ecx, 32
	sub	rcx, rsi
	add	rsi, -32
	mov	eax, 16
	.p2align	4, 0x90
.LBB0_20:                               # =>This Inner Loop Header: Depth=1
	cmp	byte ptr [rdi + rax], 0
	je	.LBB0_26
# %bb.21:                               #   in Loop: Header=BB0_20 Depth=1
	lea	rdx, [rsi + rax]
	add	rdx, 1
	add	rax, 1
	cmp	rdx, 16
	jne	.LBB0_20
# %bb.22:
	add	rcx, r8
.LBB0_23:
	mov	rsi, rcx
	sub	rsi, r8
	add	rsi, -16
	.p2align	4, 0x90
.LBB0_24:                               # =>This Inner Loop Header: Depth=1
	vmovdqu	ymm0, ymmword ptr [rcx]
	add	rcx, 32
	add	rsi, 32
	vptest	ymm0, ymm0
	je	.LBB0_24
# %bb.25:
	vpxor	xmm1, xmm1, xmm1
	vpcmpeqb	ymm0, ymm0, ymm1
	vpmovmskb	eax, ymm0
	bsf	eax, eax
	add	rax, rsi
.LBB0_26:
	vzeroupper
	ret
.LBB0_41:
	xor	eax, eax
	ret
.LBB0_28:
	mov	eax, 1
	ret
.LBB0_29:
	mov	eax, 2
	ret
.LBB0_30:
	mov	eax, 3
	ret
.LBB0_31:
	mov	eax, 4
	ret
.LBB0_32:
	mov	eax, 5
	ret
.LBB0_33:
	mov	eax, 6
	ret
.LBB0_34:
	mov	eax, 7
	ret
.LBB0_35:
	mov	eax, 8
	ret
.LBB0_36:
	mov	eax, 9
	ret
.LBB0_37:
	mov	eax, 10
	ret
.LBB0_38:
	mov	eax, 11
	ret
.LBB0_39:
	mov	eax, 12
	ret
.LBB0_40:
	mov	eax, 13
	ret
.LBB0_42:
	mov	eax, 14
	ret
.LBB0_43:
	mov	eax, 15
	ret
.Lfunc_end0:
	.size	ft_strlen, .Lfunc_end0-ft_strlen
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 12.0.1-19ubuntu3"
	.section	".note.GNU-stack","",@progbits
	.addrsig
