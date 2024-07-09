	.text
	.intel_syntax noprefix
	.file	"ft_memcpy.c"
	.globl	ft_memcpy                       # -- Begin function ft_memcpy
	.p2align	4, 0x90
	.type	ft_memcpy,@function
ft_memcpy:                              # @ft_memcpy
	.cfi_startproc
# %bb.0:
	push	r14
	.cfi_def_cfa_offset 16
	push	rbx
	.cfi_def_cfa_offset 24
	.cfi_offset rbx, -24
	.cfi_offset r14, -16
	mov	rax, rdi
	mov	rcx, rdi
	and	rcx, 31
	je	.LBB0_1
# %bb.2:
	mov	r9d, 32
	sub	r9, rcx
	cmp	r9, rdx
	cmova	r9, rdx
	test	r9, r9
	je	.LBB0_3
# %bb.4:
	cmp	r9, 32
	jb	.LBB0_5
# %bb.6:
	lea	rcx, [rsi + r9]
	cmp	rcx, rax
	jbe	.LBB0_8
# %bb.7:
	lea	rcx, [rax + r9]
	cmp	rcx, rsi
	jbe	.LBB0_8
.LBB0_5:
	xor	r8d, r8d
	mov	rdi, rax
.LBB0_16:
	mov	r10, r8
	not	r10
	add	r10, r9
	mov	r11, r9
	and	r11, 7
	je	.LBB0_20
# %bb.17:
	neg	r11
	xor	ecx, ecx
	.p2align	4, 0x90
.LBB0_18:                               # =>This Inner Loop Header: Depth=1
	movzx	ebx, byte ptr [rsi]
	add	rsi, 1
	mov	byte ptr [rdi], bl
	add	rdi, 1
	add	rcx, -1
	cmp	r11, rcx
	jne	.LBB0_18
# %bb.19:
	sub	r8, rcx
.LBB0_20:
	cmp	r10, 7
	jb	.LBB0_23
# %bb.21:
	mov	rcx, r9
	sub	rcx, r8
	.p2align	4, 0x90
.LBB0_22:                               # =>This Inner Loop Header: Depth=1
	movzx	ebx, byte ptr [rsi]
	mov	byte ptr [rdi], bl
	movzx	ebx, byte ptr [rsi + 1]
	mov	byte ptr [rdi + 1], bl
	movzx	ebx, byte ptr [rsi + 2]
	mov	byte ptr [rdi + 2], bl
	movzx	ebx, byte ptr [rsi + 3]
	mov	byte ptr [rdi + 3], bl
	movzx	ebx, byte ptr [rsi + 4]
	mov	byte ptr [rdi + 4], bl
	movzx	ebx, byte ptr [rsi + 5]
	mov	byte ptr [rdi + 5], bl
	movzx	ebx, byte ptr [rsi + 6]
	mov	byte ptr [rdi + 6], bl
	movzx	ebx, byte ptr [rsi + 7]
	add	rsi, 8
	mov	byte ptr [rdi + 7], bl
	add	rdi, 8
	add	rcx, -8
	jne	.LBB0_22
	jmp	.LBB0_23
.LBB0_1:
	mov	rdi, rax
	jmp	.LBB0_24
.LBB0_3:
	mov	rdi, rax
.LBB0_23:
	sub	rdx, r9
.LBB0_24:
	prefetcht0	byte ptr [rsi]
	prefetcht0	byte ptr [rsi + 64]
	prefetcht0	byte ptr [rdi]
	prefetcht0	byte ptr [rdi + 64]
	mov	rcx, rdx
	shr	rcx, 8
	movzx	r8d, dl
	je	.LBB0_25
	.p2align	4, 0x90
.LBB0_50:                               # =>This Inner Loop Header: Depth=1
	lea	r9, [rsi + 256]
	prefetcht0	byte ptr [rsi + 256]
	lea	r11, [rdi + 256]
	prefetcht0	byte ptr [rdi + 256]
	vmovups	ymm0, ymmword ptr [rsi]
	vmovups	ymm1, ymmword ptr [rsi + 32]
	vmovups	ymm2, ymmword ptr [rsi + 64]
	vmovups	ymm3, ymmword ptr [rsi + 96]
	vmovups	ymm4, ymmword ptr [rsi + 128]
	vmovups	ymm5, ymmword ptr [rsi + 160]
	vmovups	ymm6, ymmword ptr [rsi + 192]
	vmovups	ymm7, ymmword ptr [rsi + 224]
	vmovups	ymmword ptr [rdi], ymm0
	vmovups	ymmword ptr [rdi + 32], ymm1
	vmovups	ymmword ptr [rdi + 64], ymm2
	vmovups	ymmword ptr [rdi + 96], ymm3
	vmovups	ymmword ptr [rdi + 128], ymm4
	vmovups	ymmword ptr [rdi + 160], ymm5
	vmovups	ymmword ptr [rdi + 192], ymm6
	vmovups	ymmword ptr [rdi + 224], ymm7
	mov	rdi, r11
	mov	rsi, r9
	add	rcx, -1
	jne	.LBB0_50
# %bb.26:
	test	r8, r8
	jne	.LBB0_27
	jmp	.LBB0_44
.LBB0_25:
	mov	r9, rsi
	mov	r11, rdi
	test	r8, r8
	je	.LBB0_44
.LBB0_27:
	cmp	r8d, 8
	jb	.LBB0_28
# %bb.30:
	lea	rcx, [r9 + r8]
	cmp	r11, rcx
	jae	.LBB0_32
# %bb.31:
	lea	rcx, [r11 + r8]
	cmp	r9, rcx
	jae	.LBB0_32
.LBB0_28:
	xor	r10d, r10d
.LBB0_29:
	mov	rdi, r11
	mov	rsi, r9
.LBB0_37:
	sub	edx, r10d
	mov	r9, r10
	not	r9
	add	r9, r8
	and	rdx, 7
	je	.LBB0_41
# %bb.38:
	neg	rdx
	xor	ecx, ecx
	.p2align	4, 0x90
.LBB0_39:                               # =>This Inner Loop Header: Depth=1
	movzx	ebx, byte ptr [rsi]
	add	rsi, 1
	mov	byte ptr [rdi], bl
	add	rdi, 1
	add	rcx, -1
	cmp	rdx, rcx
	jne	.LBB0_39
# %bb.40:
	sub	r10, rcx
.LBB0_41:
	cmp	r9, 7
	jb	.LBB0_44
# %bb.42:
	sub	r8, r10
	xor	ecx, ecx
	.p2align	4, 0x90
.LBB0_43:                               # =>This Inner Loop Header: Depth=1
	movzx	edx, byte ptr [rsi + rcx]
	mov	byte ptr [rdi + rcx], dl
	movzx	edx, byte ptr [rsi + rcx + 1]
	mov	byte ptr [rdi + rcx + 1], dl
	movzx	edx, byte ptr [rsi + rcx + 2]
	mov	byte ptr [rdi + rcx + 2], dl
	movzx	edx, byte ptr [rsi + rcx + 3]
	mov	byte ptr [rdi + rcx + 3], dl
	movzx	edx, byte ptr [rsi + rcx + 4]
	mov	byte ptr [rdi + rcx + 4], dl
	movzx	edx, byte ptr [rsi + rcx + 5]
	mov	byte ptr [rdi + rcx + 5], dl
	movzx	edx, byte ptr [rsi + rcx + 6]
	mov	byte ptr [rdi + rcx + 6], dl
	movzx	edx, byte ptr [rsi + rcx + 7]
	mov	byte ptr [rdi + rcx + 7], dl
	add	rcx, 8
	cmp	r8, rcx
	jne	.LBB0_43
.LBB0_44:
	pop	rbx
	.cfi_def_cfa_offset 16
	pop	r14
	.cfi_def_cfa_offset 8
	vzeroupper
	ret
.LBB0_32:
	.cfi_def_cfa_offset 24
	cmp	r8d, 128
	jae	.LBB0_45
# %bb.33:
	xor	r10d, r10d
	jmp	.LBB0_34
.LBB0_8:
	mov	r8d, r9d
	and	r8d, 32
	lea	rcx, [r8 - 32]
	mov	rdi, rcx
	shr	rdi, 5
	add	rdi, 1
	mov	r10d, edi
	and	r10d, 7
	cmp	rcx, 224
	jae	.LBB0_10
# %bb.9:
	xor	ecx, ecx
	jmp	.LBB0_12
.LBB0_45:
	mov	ecx, edx
	and	ecx, 127
	mov	r10, r8
	sub	r10, rcx
	xor	esi, esi
	.p2align	4, 0x90
.LBB0_46:                               # =>This Inner Loop Header: Depth=1
	vmovups	ymm0, ymmword ptr [r9 + rsi]
	vmovups	ymm1, ymmword ptr [r9 + rsi + 32]
	vmovups	ymm2, ymmword ptr [r9 + rsi + 64]
	vmovups	ymm3, ymmword ptr [r9 + rsi + 96]
	vmovups	ymmword ptr [r11 + rsi], ymm0
	vmovups	ymmword ptr [r11 + rsi + 32], ymm1
	vmovups	ymmword ptr [r11 + rsi + 64], ymm2
	vmovups	ymmword ptr [r11 + rsi + 96], ymm3
	sub	rsi, -128
	cmp	r10, rsi
	jne	.LBB0_46
# %bb.47:
	test	rcx, rcx
	je	.LBB0_44
# %bb.48:
	cmp	ecx, 8
	jae	.LBB0_34
# %bb.49:
	add	r9, r10
	add	r11, r10
	jmp	.LBB0_29
.LBB0_34:
	mov	rcx, r10
	mov	r14d, edx
	and	r14d, 7
	mov	r10, r8
	sub	r10, r14
	lea	rdi, [r11 + r10]
	lea	rsi, [r9 + r10]
	.p2align	4, 0x90
.LBB0_35:                               # =>This Inner Loop Header: Depth=1
	mov	rbx, qword ptr [r9 + rcx]
	mov	qword ptr [r11 + rcx], rbx
	add	rcx, 8
	cmp	r10, rcx
	jne	.LBB0_35
# %bb.36:
	test	r14, r14
	jne	.LBB0_37
	jmp	.LBB0_44
.LBB0_10:
	and	rdi, -8
	neg	rdi
	xor	ecx, ecx
	.p2align	4, 0x90
.LBB0_11:                               # =>This Inner Loop Header: Depth=1
	vmovups	ymm0, ymmword ptr [rsi + rcx]
	vmovups	ymmword ptr [rax + rcx], ymm0
	vmovups	ymm0, ymmword ptr [rsi + rcx + 32]
	vmovups	ymmword ptr [rax + rcx + 32], ymm0
	vmovups	ymm0, ymmword ptr [rsi + rcx + 64]
	vmovups	ymmword ptr [rax + rcx + 64], ymm0
	vmovups	ymm0, ymmword ptr [rsi + rcx + 96]
	vmovups	ymmword ptr [rax + rcx + 96], ymm0
	vmovups	ymm0, ymmword ptr [rsi + rcx + 128]
	vmovups	ymmword ptr [rax + rcx + 128], ymm0
	vmovups	ymm0, ymmword ptr [rsi + rcx + 160]
	vmovups	ymmword ptr [rax + rcx + 160], ymm0
	vmovups	ymm0, ymmword ptr [rsi + rcx + 192]
	vmovups	ymmword ptr [rax + rcx + 192], ymm0
	vmovups	ymm0, ymmword ptr [rsi + rcx + 224]
	vmovups	ymmword ptr [rax + rcx + 224], ymm0
	add	rcx, 256
	add	rdi, 8
	jne	.LBB0_11
.LBB0_12:
	test	r10, r10
	je	.LBB0_15
# %bb.13:
	lea	rdi, [rsi + rcx]
	add	rcx, rax
	shl	r10, 5
	xor	ebx, ebx
	.p2align	4, 0x90
.LBB0_14:                               # =>This Inner Loop Header: Depth=1
	vmovups	ymm0, ymmword ptr [rdi + rbx]
	vmovups	ymmword ptr [rcx + rbx], ymm0
	add	rbx, 32
	cmp	r10, rbx
	jne	.LBB0_14
.LBB0_15:
	lea	rdi, [rax + r8]
	add	rsi, r8
	cmp	r9, r8
	jne	.LBB0_16
	jmp	.LBB0_23
.Lfunc_end0:
	.size	ft_memcpy, .Lfunc_end0-ft_memcpy
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 12.0.1-19ubuntu3"
	.section	".note.GNU-stack","",@progbits
	.addrsig
