	.text
	.intel_syntax noprefix
	.file	"ft_strchr.c"
	.globl	ft_strchr                       # -- Begin function ft_strchr
	.p2align	4, 0x90
	.type	ft_strchr,@function
ft_strchr:                              # @ft_strchr
	.cfi_startproc
# %bb.0:
	test	rdi, rdi
	je	.LBB0_13
# %bb.1:
	mov	rcx, rdi
	and	rcx, 31
	je	.LBB0_7
# %bb.2:
	mov	r8d, 32
	sub	r8, rcx
	add	rcx, -32
	mov	rax, rdi
	.p2align	4, 0x90
.LBB0_3:                                # =>This Inner Loop Header: Depth=1
	movzx	edx, byte ptr [rax]
	cmp	dl, sil
	je	.LBB0_11
# %bb.4:                                #   in Loop: Header=BB0_3 Depth=1
	test	dl, dl
	je	.LBB0_13
# %bb.5:                                #   in Loop: Header=BB0_3 Depth=1
	inc	rax
	inc	rcx
	jne	.LBB0_3
# %bb.6:
	add	rdi, r8
.LBB0_7:
	vmovd	xmm0, esi
	vpbroadcastb	ymm0, xmm0
	vpcmpeqb	ymm1, ymm0, ymmword ptr [rdi]
	vpmovmskb	eax, ymm1
	test	eax, eax
	je	.LBB0_9
# %bb.8:
	mov	rcx, rdi
	jmp	.LBB0_10
	.p2align	4, 0x90
.LBB0_9:                                # =>This Inner Loop Header: Depth=1
	lea	rcx, [rdi + 32]
	prefetcht0	byte ptr [rdi + 32]
	vpcmpeqb	ymm1, ymm0, ymmword ptr [rdi + 32]
	vpmovmskb	eax, ymm1
	mov	rdi, rcx
	test	eax, eax
	je	.LBB0_9
.LBB0_10:
	bsf	eax, eax
	add	rax, rcx
.LBB0_11:
	vzeroupper
	ret
.LBB0_13:
	xor	eax, eax
	ret
.Lfunc_end0:
	.size	ft_strchr, .Lfunc_end0-ft_strchr
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 12.0.1-19ubuntu3"
	.section	".note.GNU-stack","",@progbits
	.addrsig
