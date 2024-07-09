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
	je	.LBB0_1
# %bb.2:
	prefetchnta	byte ptr [rdi]
	prefetchnta	byte ptr [rdi + 4096]
	mov	rdx, rdi
	mov	rcx, rdi
	and	rdx, 31
	je	.LBB0_12
# %bb.3:
	mov	eax, 32
	sub	rax, rdx
	vpxor	xmm0, xmm0, xmm0
	vpcmpeqb	ymm0, ymm0, ymmword ptr [rdi]
	vpmovmskb	ecx, ymm0
	prefetchnta	byte ptr [rdi + rax]
	prefetchnta	byte ptr [rdi + rax + 4096]
	test	ecx, ecx
	je	.LBB0_5
# %bb.4:
	bsf	eax, ecx
	vzeroupper
	ret
.LBB0_5:
	lea	rcx, [rdi + rax]
	mov	rdx, rcx
	and	rdx, 31
	je	.LBB0_12
# %bb.6:
	cmp	byte ptr [rcx], 0
	je	.LBB0_7
# %bb.9:
	cmp	byte ptr [rcx + 1], 0
	je	.LBB0_10
# %bb.16:
	cmp	byte ptr [rcx + 2], 0
	je	.LBB0_17
# %bb.18:
	cmp	byte ptr [rcx + 3], 0
	je	.LBB0_19
# %bb.20:
	cmp	byte ptr [rcx + 4], 0
	je	.LBB0_21
# %bb.22:
	cmp	byte ptr [rcx + 5], 0
	je	.LBB0_23
# %bb.24:
	cmp	byte ptr [rcx + 6], 0
	je	.LBB0_25
# %bb.26:
	cmp	byte ptr [rcx + 7], 0
	je	.LBB0_27
# %bb.28:
	cmp	byte ptr [rcx + 8], 0
	je	.LBB0_29
# %bb.30:
	cmp	byte ptr [rcx + 9], 0
	je	.LBB0_31
# %bb.32:
	cmp	byte ptr [rcx + 10], 0
	je	.LBB0_33
# %bb.34:
	cmp	byte ptr [rcx + 11], 0
	je	.LBB0_35
# %bb.36:
	cmp	byte ptr [rcx + 12], 0
	je	.LBB0_37
# %bb.38:
	cmp	byte ptr [rcx + 13], 0
	je	.LBB0_39
# %bb.40:
	cmp	byte ptr [rcx + 14], 0
	je	.LBB0_41
# %bb.42:
	cmp	byte ptr [rcx + 15], 0
	je	.LBB0_43
# %bb.44:
	cmp	byte ptr [rcx + 16], 0
	je	.LBB0_45
# %bb.46:
	cmp	byte ptr [rcx + 17], 0
	je	.LBB0_47
# %bb.48:
	cmp	byte ptr [rcx + 18], 0
	je	.LBB0_49
# %bb.50:
	cmp	byte ptr [rcx + 19], 0
	je	.LBB0_51
# %bb.52:
	cmp	byte ptr [rcx + 20], 0
	je	.LBB0_53
# %bb.54:
	cmp	byte ptr [rcx + 21], 0
	je	.LBB0_55
# %bb.56:
	cmp	byte ptr [rcx + 22], 0
	je	.LBB0_57
# %bb.58:
	cmp	byte ptr [rcx + 23], 0
	je	.LBB0_59
# %bb.60:
	cmp	byte ptr [rcx + 24], 0
	je	.LBB0_61
# %bb.62:
	cmp	byte ptr [rcx + 25], 0
	je	.LBB0_63
# %bb.64:
	cmp	byte ptr [rcx + 26], 0
	je	.LBB0_65
# %bb.66:
	cmp	byte ptr [rcx + 27], 0
	je	.LBB0_67
# %bb.68:
	cmp	byte ptr [rcx + 28], 0
	je	.LBB0_69
# %bb.70:
	cmp	byte ptr [rcx + 29], 0
	je	.LBB0_71
# %bb.72:
	cmp	byte ptr [rcx + 30], 0
	je	.LBB0_73
# %bb.74:
	cmp	byte ptr [rcx + 31], 0
	je	.LBB0_75
# %bb.11:
	mov	eax, 32
	sub	rax, rdx
	add	rcx, rax
.LBB0_12:
	mov	rdx, rcx
	sub	rdx, rdi
	add	rdx, -32
	.p2align	4, 0x90
.LBB0_13:                               # =>This Inner Loop Header: Depth=1
	vmovdqu	ymm0, ymmword ptr [rcx]
	add	rcx, 32
	add	rdx, 32
	vptest	ymm0, ymm0
	je	.LBB0_13
# %bb.14:
	vpxor	xmm1, xmm1, xmm1
	vpcmpeqb	ymm0, ymm0, ymm1
	vpmovmskb	eax, ymm0
	bsf	eax, eax
	add	rax, rdx
	vzeroupper
	ret
.LBB0_7:
	xor	ecx, ecx
	add	rax, rcx
	vzeroupper
	ret
.LBB0_10:
	mov	ecx, 1
	add	rax, rcx
	vzeroupper
	ret
.LBB0_17:
	mov	ecx, 2
	add	rax, rcx
	vzeroupper
	ret
.LBB0_19:
	mov	ecx, 3
	add	rax, rcx
	vzeroupper
	ret
.LBB0_21:
	mov	ecx, 4
	add	rax, rcx
	vzeroupper
	ret
.LBB0_23:
	mov	ecx, 5
	add	rax, rcx
	vzeroupper
	ret
.LBB0_25:
	mov	ecx, 6
	add	rax, rcx
	vzeroupper
	ret
.LBB0_27:
	mov	ecx, 7
	add	rax, rcx
	vzeroupper
	ret
.LBB0_29:
	mov	ecx, 8
	add	rax, rcx
	vzeroupper
	ret
.LBB0_31:
	mov	ecx, 9
	add	rax, rcx
	vzeroupper
	ret
.LBB0_1:
	xor	eax, eax
	ret
.LBB0_33:
	mov	ecx, 10
	add	rax, rcx
	vzeroupper
	ret
.LBB0_35:
	mov	ecx, 11
	add	rax, rcx
	vzeroupper
	ret
.LBB0_37:
	mov	ecx, 12
	add	rax, rcx
	vzeroupper
	ret
.LBB0_39:
	mov	ecx, 13
	add	rax, rcx
	vzeroupper
	ret
.LBB0_41:
	mov	ecx, 14
	add	rax, rcx
	vzeroupper
	ret
.LBB0_43:
	mov	ecx, 15
	add	rax, rcx
	vzeroupper
	ret
.LBB0_45:
	mov	ecx, 16
	add	rax, rcx
	vzeroupper
	ret
.LBB0_47:
	mov	ecx, 17
	add	rax, rcx
	vzeroupper
	ret
.LBB0_49:
	mov	ecx, 18
	add	rax, rcx
	vzeroupper
	ret
.LBB0_51:
	mov	ecx, 19
	add	rax, rcx
	vzeroupper
	ret
.LBB0_53:
	mov	ecx, 20
	add	rax, rcx
	vzeroupper
	ret
.LBB0_55:
	mov	ecx, 21
	add	rax, rcx
	vzeroupper
	ret
.LBB0_57:
	mov	ecx, 22
	add	rax, rcx
	vzeroupper
	ret
.LBB0_59:
	mov	ecx, 23
	add	rax, rcx
	vzeroupper
	ret
.LBB0_61:
	mov	ecx, 24
	add	rax, rcx
	vzeroupper
	ret
.LBB0_63:
	mov	ecx, 25
	add	rax, rcx
	vzeroupper
	ret
.LBB0_65:
	mov	ecx, 26
	add	rax, rcx
	vzeroupper
	ret
.LBB0_67:
	mov	ecx, 27
	add	rax, rcx
	vzeroupper
	ret
.LBB0_69:
	mov	ecx, 28
	add	rax, rcx
	vzeroupper
	ret
.LBB0_71:
	mov	ecx, 29
	add	rax, rcx
	vzeroupper
	ret
.LBB0_73:
	mov	ecx, 30
	add	rax, rcx
	vzeroupper
	ret
.LBB0_75:
	mov	ecx, 31
	add	rax, rcx
	vzeroupper
	ret
.Lfunc_end0:
	.size	ft_strlen, .Lfunc_end0-ft_strlen
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 12.0.1-19ubuntu3"
	.section	".note.GNU-stack","",@progbits
	.addrsig
