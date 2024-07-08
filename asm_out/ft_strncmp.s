	.text
	.intel_syntax noprefix
	.file	"ft_strncmp.c"
	.globl	ft_strncmp                      # -- Begin function ft_strncmp
	.p2align	4, 0x90
	.type	ft_strncmp,@function
ft_strncmp:                             # @ft_strncmp
	.cfi_startproc
# %bb.0:
	mov	eax, edi
	and	eax, 31
	je	.LBB0_6
# %bb.1:
	mov	r10d, 32
	sub	r10d, eax
	cmp	r10, rdx
	cmova	r10, rdx
	test	r10, r10
	je	.LBB0_5
# %bb.2:
	xor	ecx, ecx
	.p2align	4, 0x90
.LBB0_3:                                # =>This Inner Loop Header: Depth=1
	movzx	eax, byte ptr [rdi + rcx]
	movzx	r8d, byte ptr [rsi + rcx]
	cmp	al, r8b
	jne	.LBB0_16
# %bb.4:                                #   in Loop: Header=BB0_3 Depth=1
	add	rcx, 1
	cmp	r10, rcx
	jne	.LBB0_3
.LBB0_5:
	shl	r10, 5
	lea	r8, [rdi + r10]
	add	r10, rsi
	mov	r9, rdx
	and	r9, -32
	jne	.LBB0_7
	jmp	.LBB0_11
.LBB0_6:
	mov	r10, rsi
	mov	r8, rdi
	mov	r9, rdx
	and	r9, -32
	je	.LBB0_11
.LBB0_7:
	mov	ecx, 32
	xor	r11d, r11d
	.p2align	4, 0x90
.LBB0_8:                                # =>This Inner Loop Header: Depth=1
	vmovdqu	ymm0, ymmword ptr [r8 + rcx - 32]
	vpcmpeqb	ymm0, ymm0, ymmword ptr [r10 + rcx - 32]
	vpmovmskb	eax, ymm0
	cmp	eax, -1
	jne	.LBB0_18
# %bb.9:                                #   in Loop: Header=BB0_8 Depth=1
	vmovdqu	ymm0, ymmword ptr [r8 + rcx]
	vpcmpeqb	ymm0, ymm0, ymmword ptr [r10 + rcx]
	vpmovmskb	eax, ymm0
	cmp	eax, -1
	jne	.LBB0_17
# %bb.10:                               #   in Loop: Header=BB0_8 Depth=1
	add	r11, 2
	add	rcx, 64
	cmp	r9, r11
	jne	.LBB0_8
.LBB0_11:
	and	edx, 31
	test	rdx, rdx
	je	.LBB0_19
# %bb.12:
	shl	r9, 5
	add	r8, r9
	add	r10, r9
	xor	ecx, ecx
	.p2align	4, 0x90
.LBB0_13:                               # =>This Inner Loop Header: Depth=1
	movzx	eax, byte ptr [r8 + rcx]
	movzx	esi, byte ptr [r10 + rcx]
	cmp	al, sil
	jne	.LBB0_20
# %bb.14:                               #   in Loop: Header=BB0_13 Depth=1
	add	rcx, 1
	cmp	rdx, rcx
	jne	.LBB0_13
.LBB0_19:
	xor	eax, eax
	vzeroupper
	ret
.LBB0_16:
	sub	eax, r8d
	ret
.LBB0_17:
	add	r11, 1
.LBB0_18:
	shl	r11, 5
	not	eax
	bsf	ecx, eax
	or	rcx, r11
	movzx	eax, byte ptr [rdi + rcx]
	movzx	ecx, byte ptr [rsi + rcx]
	sub	eax, ecx
	vzeroupper
	ret
.LBB0_20:
	sub	eax, esi
	vzeroupper
	ret
.Lfunc_end0:
	.size	ft_strncmp, .Lfunc_end0-ft_strncmp
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 12.0.1-19ubuntu3"
	.section	".note.GNU-stack","",@progbits
	.addrsig
