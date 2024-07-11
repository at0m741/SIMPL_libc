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
	je	.LBB0_14
# %bb.1:
	test	rdx, rdx
	je	.LBB0_14
# %bb.2:
	mov	ecx, esi
	or	ecx, edi
	test	cl, 31
	je	.LBB0_8
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
	xor	ecx, ecx
	.p2align	4, 0x90
.LBB0_5:                                # =>This Inner Loop Header: Depth=1
	movzx	r9d, byte ptr [rdi + rcx]
	movzx	r10d, byte ptr [rsi + rcx]
	cmp	r9b, r10b
	jne	.LBB0_6
# %bb.4:                                #   in Loop: Header=BB0_5 Depth=1
	inc	rcx
	cmp	r8, rcx
	jne	.LBB0_5
# %bb.7:
	add	rdi, r8
	add	rsi, r8
	sub	rdx, r8
.LBB0_8:
	cmp	rdx, 32
	jb	.LBB0_14
# %bb.9:
	shr	rdx, 5
	xor	ecx, ecx
	.p2align	4, 0x90
.LBB0_10:                               # =>This Inner Loop Header: Depth=1
	vmovdqu	ymm0, ymmword ptr [rdi + rcx]
	vmovdqu	ymm1, ymmword ptr [rsi + rcx]
	vpsubb	ymm2, ymm0, ymm1
	vptest	ymm2, ymm2
	jne	.LBB0_11
# %bb.12:                               #   in Loop: Header=BB0_10 Depth=1
	add	rcx, 32
	dec	rdx
	jne	.LBB0_10
# %bb.13:
	xor	eax, eax
.LBB0_14:
	vzeroupper
	ret
.LBB0_11:
	vpcmpeqb	ymm0, ymm0, ymm1
	vpmovmskb	eax, ymm0
	not	eax
	bsf	eax, eax
	or	rcx, rax
	movzx	eax, byte ptr [rdi + rcx]
	movzx	ecx, byte ptr [rsi + rcx]
	sub	eax, ecx
	vzeroupper
	ret
.LBB0_6:
	sub	r9d, r10d
	mov	eax, r9d
	ret
.Lfunc_end0:
	.size	ft_strncmp, .Lfunc_end0-ft_strncmp
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 14.0.0-1ubuntu1.1"
	.section	".note.GNU-stack","",@progbits
	.addrsig
