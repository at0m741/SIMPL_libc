	.text
	.intel_syntax noprefix
	.file	"ft_strncmp.c"
	.globl	ft_strncmp                      # -- Begin function ft_strncmp
	.p2align	4, 0x90
	.type	ft_strncmp,@function
ft_strncmp:                             # @ft_strncmp
	.cfi_startproc
# %bb.0:
	xor	eax, eax
	cmp	rdi, rsi
	je	.LBB0_18
# %bb.1:
	test	rdx, rdx
	je	.LBB0_18
# %bb.2:
	mov	ecx, esi
	or	ecx, edi
	test	cl, 31
	je	.LBB0_12
# %bb.3:
	mov	r8d, edi
	and	r8d, 31
	mov	ecx, esi
	and	ecx, 31
	cmp	r8, rcx
	cmova	rcx, r8
	mov	r8d, 32
	sub	r8, rcx
	cmp	r8, rdx
	cmova	r8, rdx
	mov	r9b, byte ptr [rdi]
	mov	r10b, byte ptr [rsi]
	cmp	r9b, r10b
	jne	.LBB0_4
# %bb.5:
	lea	r11, [r8 - 1]
	xor	ecx, ecx
	.p2align	4, 0x90
.LBB0_6:                                # =>This Inner Loop Header: Depth=1
	cmp	r11, rcx
	je	.LBB0_11
# %bb.7:                                #   in Loop: Header=BB0_6 Depth=1
	movzx	r9d, byte ptr [rdi + rcx + 1]
	movzx	r10d, byte ptr [rsi + rcx + 1]
	inc	rcx
	cmp	r9b, r10b
	je	.LBB0_6
# %bb.8:
	cmp	rcx, r8
	setb	cl
	test	cl, cl
	je	.LBB0_11
.LBB0_10:
	movzx	eax, r9b
	movzx	ecx, r10b
	sub	eax, ecx
	ret
.LBB0_4:
	mov	cl, 1
	test	cl, cl
	jne	.LBB0_10
.LBB0_11:
	add	rdi, r8
	add	rsi, r8
	sub	rdx, r8
.LBB0_12:
	shr	rdx, 5
	je	.LBB0_18
# %bb.13:
	xor	ecx, ecx
	.p2align	4, 0x90
.LBB0_14:                               # =>This Inner Loop Header: Depth=1
	vmovdqu	ymm0, ymmword ptr [rdi + rcx]
	vpcmpeqb	ymm0, ymm0, ymmword ptr [rsi + rcx]
	vpmovmskb	eax, ymm0
	cmp	eax, -1
	jne	.LBB0_15
# %bb.16:                               #   in Loop: Header=BB0_14 Depth=1
	add	rcx, 32
	dec	rdx
	jne	.LBB0_14
# %bb.17:
	xor	eax, eax
.LBB0_18:
	vzeroupper
	ret
.LBB0_15:
	not	eax
	bsf	eax, eax
	or	rcx, rax
	movzx	eax, byte ptr [rdi + rcx]
	movzx	ecx, byte ptr [rsi + rcx]
	sub	eax, ecx
	vzeroupper
	ret
.Lfunc_end0:
	.size	ft_strncmp, .Lfunc_end0-ft_strncmp
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 12.0.1-19ubuntu3"
	.section	".note.GNU-stack","",@progbits
	.addrsig
