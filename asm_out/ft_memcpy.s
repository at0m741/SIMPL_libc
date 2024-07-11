	.text
	.intel_syntax noprefix
	.file	"ft_memcpy.c"
	.globl	ft_memcpy                       # -- Begin function ft_memcpy
	.p2align	4, 0x90
	.type	ft_memcpy,@function
ft_memcpy:                              # @ft_memcpy
	.cfi_startproc
# %bb.0:
	push	rbx
	.cfi_def_cfa_offset 16
	.cfi_offset rbx, -16
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
	mov	r10, rax
.LBB0_16:
	mov	r11, r8
	not	r11
	add	r11, r9
	mov	rdi, r9
	and	rdi, 7
	je	.LBB0_20
# %bb.17:
	neg	rdi
	xor	ecx, ecx
	.p2align	4, 0x90
.LBB0_18:                               # =>This Inner Loop Header: Depth=1
	movzx	ebx, byte ptr [rsi]
	inc	rsi
	mov	byte ptr [r10], bl
	inc	r10
	dec	rcx
	cmp	rdi, rcx
	jne	.LBB0_18
# %bb.19:
	sub	r8, rcx
.LBB0_20:
	cmp	r11, 7
	jb	.LBB0_23
# %bb.21:
	mov	rcx, r9
	sub	rcx, r8
	.p2align	4, 0x90
.LBB0_22:                               # =>This Inner Loop Header: Depth=1
	movzx	ebx, byte ptr [rsi]
	mov	byte ptr [r10], bl
	movzx	ebx, byte ptr [rsi + 1]
	mov	byte ptr [r10 + 1], bl
	movzx	ebx, byte ptr [rsi + 2]
	mov	byte ptr [r10 + 2], bl
	movzx	ebx, byte ptr [rsi + 3]
	mov	byte ptr [r10 + 3], bl
	movzx	ebx, byte ptr [rsi + 4]
	mov	byte ptr [r10 + 4], bl
	movzx	ebx, byte ptr [rsi + 5]
	mov	byte ptr [r10 + 5], bl
	movzx	ebx, byte ptr [rsi + 6]
	mov	byte ptr [r10 + 6], bl
	movzx	ebx, byte ptr [rsi + 7]
	add	rsi, 8
	mov	byte ptr [r10 + 7], bl
	add	r10, 8
	add	rcx, -8
	jne	.LBB0_22
	jmp	.LBB0_23
.LBB0_1:
	mov	r10, rax
	jmp	.LBB0_24
.LBB0_3:
	mov	r10, rax
.LBB0_23:
	sub	rdx, r9
.LBB0_24:
	prefetcht0	byte ptr [rsi]
	prefetcht0	byte ptr [rsi + 64]
	prefetcht0	byte ptr [r10]
	prefetcht0	byte ptr [r10 + 64]
	movzx	r8d, dl
	cmp	rdx, 256
	jb	.LBB0_29
# %bb.25:
	mov	rcx, rdx
	shr	rcx, 8
	cmp	rcx, 1
	jne	.LBB0_53
# %bb.26:
	mov	rdi, r10
	mov	r9, rsi
	jmp	.LBB0_27
.LBB0_53:
	and	rcx, -2
	.p2align	4, 0x90
.LBB0_54:                               # =>This Inner Loop Header: Depth=1
	prefetcht0	byte ptr [rsi + 256]
	prefetcht0	byte ptr [r10 + 256]
	vmovups	ymm0, ymmword ptr [rsi]
	vmovups	ymm1, ymmword ptr [rsi + 32]
	vmovups	ymm2, ymmword ptr [rsi + 64]
	vmovups	ymm3, ymmword ptr [rsi + 96]
	vmovups	ymm4, ymmword ptr [rsi + 128]
	vmovups	ymm5, ymmword ptr [rsi + 160]
	vmovups	ymm6, ymmword ptr [rsi + 192]
	vmovups	ymm7, ymmword ptr [rsi + 224]
	vmovups	ymmword ptr [r10], ymm0
	vmovups	ymmword ptr [r10 + 32], ymm1
	vmovups	ymmword ptr [r10 + 64], ymm2
	vmovups	ymmword ptr [r10 + 96], ymm3
	vmovups	ymmword ptr [r10 + 128], ymm4
	vmovups	ymmword ptr [r10 + 160], ymm5
	vmovups	ymmword ptr [r10 + 192], ymm6
	vmovups	ymmword ptr [r10 + 224], ymm7
	lea	r9, [rsi + 512]
	prefetcht0	byte ptr [rsi + 512]
	prefetcht0	byte ptr [r10 + 512]
	vmovups	ymm0, ymmword ptr [rsi + 256]
	vmovups	ymm1, ymmword ptr [rsi + 288]
	vmovups	ymm2, ymmword ptr [rsi + 320]
	vmovups	ymm3, ymmword ptr [rsi + 352]
	vmovups	ymm4, ymmword ptr [rsi + 384]
	vmovups	ymm5, ymmword ptr [rsi + 416]
	vmovups	ymm6, ymmword ptr [rsi + 448]
	vmovups	ymm7, ymmword ptr [rsi + 480]
	vmovups	ymmword ptr [r10 + 256], ymm0
	vmovups	ymmword ptr [r10 + 288], ymm1
	vmovups	ymmword ptr [r10 + 320], ymm2
	vmovups	ymmword ptr [r10 + 352], ymm3
	vmovups	ymmword ptr [r10 + 384], ymm4
	vmovups	ymmword ptr [r10 + 416], ymm5
	lea	rdi, [r10 + 512]
	vmovups	ymmword ptr [r10 + 448], ymm6
	vmovups	ymmword ptr [r10 + 480], ymm7
	mov	r10, rdi
	mov	rsi, r9
	add	rcx, -2
	jne	.LBB0_54
.LBB0_27:
	mov	rsi, r9
	mov	r10, rdi
	test	edx, 256
	je	.LBB0_29
# %bb.28:
	lea	rsi, [r9 + 256]
	prefetcht0	byte ptr [r9 + 256]
	lea	r10, [rdi + 256]
	prefetcht0	byte ptr [rdi + 256]
	vmovups	ymm0, ymmword ptr [r9]
	vmovups	ymm1, ymmword ptr [r9 + 32]
	vmovups	ymm2, ymmword ptr [r9 + 64]
	vmovups	ymm3, ymmword ptr [r9 + 96]
	vmovups	ymm4, ymmword ptr [r9 + 128]
	vmovups	ymm5, ymmword ptr [r9 + 160]
	vmovups	ymm6, ymmword ptr [r9 + 192]
	vmovups	ymm7, ymmword ptr [r9 + 224]
	vmovups	ymmword ptr [rdi], ymm0
	vmovups	ymmword ptr [rdi + 32], ymm1
	vmovups	ymmword ptr [rdi + 64], ymm2
	vmovups	ymmword ptr [rdi + 96], ymm3
	vmovups	ymmword ptr [rdi + 128], ymm4
	vmovups	ymmword ptr [rdi + 160], ymm5
	vmovups	ymmword ptr [rdi + 192], ymm6
	vmovups	ymmword ptr [rdi + 224], ymm7
.LBB0_29:
	test	r8, r8
	je	.LBB0_47
# %bb.30:
	cmp	r8d, 16
	jb	.LBB0_31
# %bb.33:
	lea	rcx, [rsi + r8]
	cmp	r10, rcx
	jae	.LBB0_35
# %bb.34:
	lea	rcx, [r10 + r8]
	cmp	rsi, rcx
	jae	.LBB0_35
.LBB0_31:
	xor	r9d, r9d
.LBB0_32:
	mov	rcx, r10
	mov	rdi, rsi
.LBB0_40:
	sub	edx, r9d
	mov	r10, r9
	not	r10
	add	r10, r8
	and	rdx, 7
	je	.LBB0_44
# %bb.41:
	neg	rdx
	xor	esi, esi
	.p2align	4, 0x90
.LBB0_42:                               # =>This Inner Loop Header: Depth=1
	movzx	ebx, byte ptr [rdi]
	inc	rdi
	mov	byte ptr [rcx], bl
	inc	rcx
	dec	rsi
	cmp	rdx, rsi
	jne	.LBB0_42
# %bb.43:
	sub	r9, rsi
.LBB0_44:
	cmp	r10, 7
	jb	.LBB0_47
# %bb.45:
	sub	r8, r9
	xor	edx, edx
	.p2align	4, 0x90
.LBB0_46:                               # =>This Inner Loop Header: Depth=1
	movzx	ebx, byte ptr [rdi + rdx]
	mov	byte ptr [rcx + rdx], bl
	movzx	ebx, byte ptr [rdi + rdx + 1]
	mov	byte ptr [rcx + rdx + 1], bl
	movzx	ebx, byte ptr [rdi + rdx + 2]
	mov	byte ptr [rcx + rdx + 2], bl
	movzx	ebx, byte ptr [rdi + rdx + 3]
	mov	byte ptr [rcx + rdx + 3], bl
	movzx	ebx, byte ptr [rdi + rdx + 4]
	mov	byte ptr [rcx + rdx + 4], bl
	movzx	ebx, byte ptr [rdi + rdx + 5]
	mov	byte ptr [rcx + rdx + 5], bl
	movzx	ebx, byte ptr [rdi + rdx + 6]
	mov	byte ptr [rcx + rdx + 6], bl
	movzx	ebx, byte ptr [rdi + rdx + 7]
	mov	byte ptr [rcx + rdx + 7], bl
	add	rdx, 8
	cmp	r8, rdx
	jne	.LBB0_46
.LBB0_47:
	pop	rbx
	.cfi_def_cfa_offset 8
	vzeroupper
	ret
.LBB0_35:
	.cfi_def_cfa_offset 16
	cmp	r8d, 128
	jae	.LBB0_48
# %bb.36:
	xor	r9d, r9d
	jmp	.LBB0_37
.LBB0_8:
	mov	r8d, r9d
	and	r8d, 32
	lea	rcx, [r8 - 32]
	mov	rdi, rcx
	shr	rdi, 5
	inc	rdi
	mov	r10d, edi
	and	r10d, 7
	cmp	rcx, 224
	jae	.LBB0_10
# %bb.9:
	xor	ecx, ecx
	jmp	.LBB0_12
.LBB0_48:
	mov	ecx, edx
	and	ecx, 127
	mov	r9, r8
	sub	r9, rcx
	xor	edi, edi
	.p2align	4, 0x90
.LBB0_49:                               # =>This Inner Loop Header: Depth=1
	vmovups	ymm0, ymmword ptr [rsi + rdi]
	vmovups	ymm1, ymmword ptr [rsi + rdi + 32]
	vmovups	ymm2, ymmword ptr [rsi + rdi + 64]
	vmovups	ymm3, ymmword ptr [rsi + rdi + 96]
	vmovups	ymmword ptr [r10 + rdi], ymm0
	vmovups	ymmword ptr [r10 + rdi + 32], ymm1
	vmovups	ymmword ptr [r10 + rdi + 64], ymm2
	vmovups	ymmword ptr [r10 + rdi + 96], ymm3
	sub	rdi, -128
	cmp	r9, rdi
	jne	.LBB0_49
# %bb.50:
	test	rcx, rcx
	je	.LBB0_47
# %bb.51:
	cmp	ecx, 16
	jae	.LBB0_37
# %bb.52:
	add	rsi, r9
	add	r10, r9
	jmp	.LBB0_32
.LBB0_37:
	mov	r11, r9
	mov	ebx, edx
	and	ebx, 15
	mov	r9, r8
	sub	r9, rbx
	lea	rcx, [r10 + r9]
	lea	rdi, [rsi + r9]
	.p2align	4, 0x90
.LBB0_38:                               # =>This Inner Loop Header: Depth=1
	vmovups	xmm0, xmmword ptr [rsi + r11]
	vmovups	xmmword ptr [r10 + r11], xmm0
	add	r11, 16
	cmp	r9, r11
	jne	.LBB0_38
# %bb.39:
	test	rbx, rbx
	jne	.LBB0_40
	jmp	.LBB0_47
.LBB0_10:
	and	rdi, -8
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
	add	rdi, -8
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
	lea	r10, [rax + r8]
	add	rsi, r8
	cmp	r9, r8
	jne	.LBB0_16
	jmp	.LBB0_23
.Lfunc_end0:
	.size	ft_memcpy, .Lfunc_end0-ft_memcpy
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 14.0.0-1ubuntu1.1"
	.section	".note.GNU-stack","",@progbits
	.addrsig
