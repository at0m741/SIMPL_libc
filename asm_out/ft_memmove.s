	.text
	.intel_syntax noprefix
	.file	"ft_memmove.c"
	.globl	ft_memmove                      # -- Begin function ft_memmove
	.p2align	4, 0x90
	.type	ft_memmove,@function
ft_memmove:                             # @ft_memmove
	.cfi_startproc
# %bb.0:
	push	r14
	.cfi_def_cfa_offset 16
	push	rbx
	.cfi_def_cfa_offset 24
	.cfi_offset rbx, -24
	.cfi_offset r14, -16
	xor	eax, eax
	test	rdi, rdi
	je	.LBB0_45
# %bb.1:
	test	rsi, rsi
	je	.LBB0_45
# %bb.2:
	cmp	rdi, rsi
	jb	.LBB0_22
# %bb.3:
	lea	r10, [rsi + rdx]
	cmp	r10, rdi
	jbe	.LBB0_22
# %bb.4:
	lea	r9, [rdi + rdx]
	prefetcht0	byte ptr [r10 - 64]
	prefetcht0	byte ptr [rdi + rdx - 64]
	mov	eax, r10d
	or	eax, r9d
	test	al, 31
	jne	.LBB0_12
# %bb.5:
	cmp	rdx, 32
	jb	.LBB0_12
# %bb.6:
	lea	rbx, [rdx - 32]
	mov	eax, ebx
	shr	eax, 5
	inc	eax
	and	rax, 7
	je	.LBB0_10
# %bb.7:
	shl	rax, 5
	xor	esi, esi
	.p2align	4, 0x90
.LBB0_8:                                # =>This Inner Loop Header: Depth=1
	vmovaps	ymm0, ymmword ptr [r10 + rsi - 32]
	vmovaps	ymmword ptr [r9 + rsi - 32], ymm0
	add	rsi, -32
	mov	rcx, rax
	add	rcx, rsi
	jne	.LBB0_8
# %bb.9:
	add	rdx, rsi
	add	r10, rsi
	add	r9, rsi
.LBB0_10:
	cmp	rbx, 224
	jb	.LBB0_12
	.p2align	4, 0x90
.LBB0_11:                               # =>This Inner Loop Header: Depth=1
	vmovaps	ymm0, ymmword ptr [r10 - 32]
	vmovaps	ymmword ptr [r9 - 32], ymm0
	vmovaps	ymm0, ymmword ptr [r10 - 64]
	vmovaps	ymmword ptr [r9 - 64], ymm0
	vmovaps	ymm0, ymmword ptr [r10 - 96]
	vmovaps	ymmword ptr [r9 - 96], ymm0
	vmovaps	ymm0, ymmword ptr [r10 - 128]
	vmovaps	ymmword ptr [r9 - 128], ymm0
	vmovaps	ymm0, ymmword ptr [r10 - 160]
	vmovaps	ymmword ptr [r9 - 160], ymm0
	vmovaps	ymm0, ymmword ptr [r10 - 192]
	vmovaps	ymmword ptr [r9 - 192], ymm0
	vmovaps	ymm0, ymmword ptr [r10 - 224]
	vmovaps	ymmword ptr [r9 - 224], ymm0
	vmovaps	ymm0, ymmword ptr [r10 - 256]
	add	r10, -256
	vmovaps	ymmword ptr [r9 - 256], ymm0
	add	r9, -256
	add	rdx, -256
	cmp	rdx, 31
	ja	.LBB0_11
.LBB0_12:
	test	rdx, rdx
	je	.LBB0_44
# %bb.13:
	cmp	rdx, 8
	jb	.LBB0_16
# %bb.14:
	mov	rax, r9
	sub	rax, rdx
	cmp	rax, r10
	jae	.LBB0_46
# %bb.15:
	mov	rax, r10
	sub	rax, rdx
	cmp	rax, r9
	jae	.LBB0_46
.LBB0_16:
	mov	r11, rdx
	mov	rax, r10
	mov	rcx, r9
.LBB0_17:
	lea	rdx, [r11 - 1]
	mov	rsi, r11
	and	rsi, 7
	je	.LBB0_19
	.p2align	4, 0x90
.LBB0_18:                               # =>This Inner Loop Header: Depth=1
	dec	r11
	movzx	ebx, byte ptr [rax - 1]
	dec	rax
	mov	byte ptr [rcx - 1], bl
	dec	rcx
	dec	rsi
	jne	.LBB0_18
.LBB0_19:
	cmp	rdx, 7
	jb	.LBB0_44
# %bb.20:
	neg	r11
	xor	edx, edx
	.p2align	4, 0x90
.LBB0_21:                               # =>This Inner Loop Header: Depth=1
	movzx	ebx, byte ptr [rax + rdx - 1]
	mov	byte ptr [rcx + rdx - 1], bl
	movzx	ebx, byte ptr [rax + rdx - 2]
	mov	byte ptr [rcx + rdx - 2], bl
	movzx	ebx, byte ptr [rax + rdx - 3]
	mov	byte ptr [rcx + rdx - 3], bl
	movzx	ebx, byte ptr [rax + rdx - 4]
	mov	byte ptr [rcx + rdx - 4], bl
	movzx	ebx, byte ptr [rax + rdx - 5]
	mov	byte ptr [rcx + rdx - 5], bl
	movzx	ebx, byte ptr [rax + rdx - 6]
	mov	byte ptr [rcx + rdx - 6], bl
	movzx	ebx, byte ptr [rax + rdx - 7]
	mov	byte ptr [rcx + rdx - 7], bl
	movzx	ebx, byte ptr [rax + rdx - 8]
	mov	byte ptr [rcx + rdx - 8], bl
	add	rdx, -8
	cmp	r11, rdx
	jne	.LBB0_21
	jmp	.LBB0_44
.LBB0_22:
	mov	eax, esi
	or	eax, edi
	test	al, 31
	jne	.LBB0_29
# %bb.23:
	cmp	rdx, 32
	jb	.LBB0_29
# %bb.24:
	lea	rax, [rdx - 32]
	mov	ecx, eax
	shr	ecx, 5
	inc	ecx
	and	rcx, 7
	je	.LBB0_30
# %bb.25:
	shl	rcx, 5
	xor	r10d, r10d
	.p2align	4, 0x90
.LBB0_26:                               # =>This Inner Loop Header: Depth=1
	vmovaps	ymm0, ymmword ptr [rsi + r10]
	vmovaps	ymmword ptr [rdi + r10], ymm0
	prefetcht0	byte ptr [rsi + r10 + 96]
	prefetcht0	byte ptr [rdi + r10 + 96]
	add	r10, 32
	cmp	rcx, r10
	jne	.LBB0_26
# %bb.27:
	sub	rdx, r10
	add	rsi, r10
	add	r10, rdi
	cmp	rax, 224
	jae	.LBB0_31
	jmp	.LBB0_32
.LBB0_29:
	mov	r10, rdi
	jmp	.LBB0_32
.LBB0_30:
	mov	r10, rdi
	cmp	rax, 224
	jb	.LBB0_32
	.p2align	4, 0x90
.LBB0_31:                               # =>This Inner Loop Header: Depth=1
	vmovaps	ymm0, ymmword ptr [rsi]
	vmovaps	ymmword ptr [r10], ymm0
	prefetcht0	byte ptr [rsi + 96]
	prefetcht0	byte ptr [r10 + 96]
	vmovaps	ymm0, ymmword ptr [rsi + 32]
	vmovaps	ymmword ptr [r10 + 32], ymm0
	prefetcht0	byte ptr [rsi + 128]
	prefetcht0	byte ptr [r10 + 128]
	vmovaps	ymm0, ymmword ptr [rsi + 64]
	vmovaps	ymmword ptr [r10 + 64], ymm0
	prefetcht0	byte ptr [rsi + 160]
	prefetcht0	byte ptr [r10 + 160]
	vmovaps	ymm0, ymmword ptr [rsi + 96]
	vmovaps	ymmword ptr [r10 + 96], ymm0
	prefetcht0	byte ptr [rsi + 192]
	prefetcht0	byte ptr [r10 + 192]
	vmovaps	ymm0, ymmword ptr [rsi + 128]
	vmovaps	ymmword ptr [r10 + 128], ymm0
	prefetcht0	byte ptr [rsi + 224]
	prefetcht0	byte ptr [r10 + 224]
	vmovaps	ymm0, ymmword ptr [rsi + 160]
	vmovaps	ymmword ptr [r10 + 160], ymm0
	prefetcht0	byte ptr [rsi + 256]
	prefetcht0	byte ptr [r10 + 256]
	vmovaps	ymm0, ymmword ptr [rsi + 192]
	vmovaps	ymmword ptr [r10 + 192], ymm0
	prefetcht0	byte ptr [rsi + 288]
	prefetcht0	byte ptr [r10 + 288]
	vmovaps	ymm0, ymmword ptr [rsi + 224]
	vmovaps	ymmword ptr [r10 + 224], ymm0
	prefetcht0	byte ptr [rsi + 320]
	add	rsi, 256
	prefetcht0	byte ptr [r10 + 320]
	add	r10, 256
	add	rdx, -256
	cmp	rdx, 31
	ja	.LBB0_31
.LBB0_32:
	test	rdx, rdx
	je	.LBB0_44
# %bb.33:
	cmp	rdx, 8
	jb	.LBB0_36
# %bb.34:
	lea	rax, [rsi + rdx]
	cmp	r10, rax
	jae	.LBB0_48
# %bb.35:
	lea	rax, [r10 + rdx]
	cmp	rsi, rax
	jae	.LBB0_48
.LBB0_36:
	mov	r8, rdx
	mov	rcx, rsi
	mov	rax, r10
.LBB0_37:
	lea	r9, [r8 - 1]
	mov	rbx, r8
	and	rbx, 7
	je	.LBB0_41
# %bb.38:
	xor	esi, esi
	.p2align	4, 0x90
.LBB0_39:                               # =>This Inner Loop Header: Depth=1
	movzx	edx, byte ptr [rcx + rsi]
	mov	byte ptr [rax + rsi], dl
	inc	rsi
	cmp	rbx, rsi
	jne	.LBB0_39
# %bb.40:
	sub	r8, rsi
	add	rcx, rsi
	add	rax, rsi
.LBB0_41:
	cmp	r9, 7
	jb	.LBB0_44
# %bb.42:
	xor	edx, edx
	.p2align	4, 0x90
.LBB0_43:                               # =>This Inner Loop Header: Depth=1
	movzx	ebx, byte ptr [rcx + rdx]
	mov	byte ptr [rax + rdx], bl
	movzx	ebx, byte ptr [rcx + rdx + 1]
	mov	byte ptr [rax + rdx + 1], bl
	movzx	ebx, byte ptr [rcx + rdx + 2]
	mov	byte ptr [rax + rdx + 2], bl
	movzx	ebx, byte ptr [rcx + rdx + 3]
	mov	byte ptr [rax + rdx + 3], bl
	movzx	ebx, byte ptr [rcx + rdx + 4]
	mov	byte ptr [rax + rdx + 4], bl
	movzx	ebx, byte ptr [rcx + rdx + 5]
	mov	byte ptr [rax + rdx + 5], bl
	movzx	ebx, byte ptr [rcx + rdx + 6]
	mov	byte ptr [rax + rdx + 6], bl
	movzx	ebx, byte ptr [rcx + rdx + 7]
	mov	byte ptr [rax + rdx + 7], bl
	add	rdx, 8
	cmp	r8, rdx
	jne	.LBB0_43
.LBB0_44:
	mov	rax, rdi
.LBB0_45:
	pop	rbx
	.cfi_def_cfa_offset 16
	pop	r14
	.cfi_def_cfa_offset 8
	vzeroupper
	ret
.LBB0_46:
	.cfi_def_cfa_offset 24
	cmp	rdx, 128
	jae	.LBB0_50
# %bb.47:
	xor	r8d, r8d
	jmp	.LBB0_62
.LBB0_48:
	cmp	rdx, 128
	jae	.LBB0_52
# %bb.49:
	xor	r9d, r9d
	jmp	.LBB0_72
.LBB0_50:
	mov	r8, rdx
	and	r8, -128
	lea	rax, [r8 - 128]
	mov	rsi, rax
	shr	rsi, 7
	inc	rsi
	mov	r11d, esi
	and	r11d, 3
	cmp	rax, 384
	jae	.LBB0_54
# %bb.51:
	xor	ecx, ecx
	jmp	.LBB0_57
.LBB0_52:
	mov	r9, rdx
	and	r9, -128
	lea	rax, [r9 - 128]
	mov	rcx, rax
	shr	rcx, 7
	inc	rcx
	mov	r8d, ecx
	and	r8d, 3
	cmp	rax, 384
	jae	.LBB0_65
# %bb.53:
	xor	eax, eax
	jmp	.LBB0_67
.LBB0_54:
	and	rsi, -4
	neg	rsi
	xor	ecx, ecx
	.p2align	4, 0x90
.LBB0_55:                               # =>This Inner Loop Header: Depth=1
	vmovups	ymm0, ymmword ptr [r10 + rcx - 128]
	vmovups	ymm1, ymmword ptr [r10 + rcx - 96]
	vmovups	ymm2, ymmword ptr [r10 + rcx - 64]
	vmovups	ymm3, ymmword ptr [r10 + rcx - 32]
	vmovups	ymmword ptr [r9 + rcx - 32], ymm3
	vmovups	ymmword ptr [r9 + rcx - 64], ymm2
	vmovups	ymmword ptr [r9 + rcx - 96], ymm1
	vmovups	ymmword ptr [r9 + rcx - 128], ymm0
	vmovups	ymm0, ymmword ptr [r10 + rcx - 256]
	vmovups	ymm1, ymmword ptr [r10 + rcx - 224]
	vmovups	ymm2, ymmword ptr [r10 + rcx - 192]
	vmovups	ymm3, ymmword ptr [r10 + rcx - 160]
	vmovups	ymmword ptr [r9 + rcx - 160], ymm3
	vmovups	ymmword ptr [r9 + rcx - 192], ymm2
	vmovups	ymmword ptr [r9 + rcx - 224], ymm1
	vmovups	ymmword ptr [r9 + rcx - 256], ymm0
	vmovups	ymm0, ymmword ptr [r10 + rcx - 384]
	vmovups	ymm1, ymmword ptr [r10 + rcx - 352]
	vmovups	ymm2, ymmword ptr [r10 + rcx - 320]
	vmovups	ymm3, ymmword ptr [r10 + rcx - 288]
	vmovups	ymmword ptr [r9 + rcx - 288], ymm3
	vmovups	ymmword ptr [r9 + rcx - 320], ymm2
	vmovups	ymmword ptr [r9 + rcx - 352], ymm1
	vmovups	ymmword ptr [r9 + rcx - 384], ymm0
	vmovups	ymm0, ymmword ptr [r10 + rcx - 512]
	vmovups	ymm1, ymmword ptr [r10 + rcx - 480]
	vmovups	ymm2, ymmword ptr [r10 + rcx - 448]
	vmovups	ymm3, ymmword ptr [r10 + rcx - 416]
	vmovups	ymmword ptr [r9 + rcx - 416], ymm3
	vmovups	ymmword ptr [r9 + rcx - 448], ymm2
	vmovups	ymmword ptr [r9 + rcx - 480], ymm1
	vmovups	ymmword ptr [r9 + rcx - 512], ymm0
	add	rcx, -512
	add	rsi, 4
	jne	.LBB0_55
# %bb.56:
	neg	rcx
.LBB0_57:
	test	r11, r11
	je	.LBB0_60
# %bb.58:
	mov	rsi, -32
	sub	rsi, rcx
	lea	rcx, [r9 + rsi]
	add	rsi, r10
	shl	r11, 7
	xor	eax, eax
	.p2align	4, 0x90
.LBB0_59:                               # =>This Inner Loop Header: Depth=1
	vmovups	ymm0, ymmword ptr [rsi + rax - 96]
	vmovups	ymm1, ymmword ptr [rsi + rax - 64]
	vmovups	ymm2, ymmword ptr [rsi + rax - 32]
	vmovups	ymm3, ymmword ptr [rsi + rax]
	vmovups	ymmword ptr [rcx + rax], ymm3
	vmovups	ymmword ptr [rcx + rax - 32], ymm2
	vmovups	ymmword ptr [rcx + rax - 64], ymm1
	vmovups	ymmword ptr [rcx + rax - 96], ymm0
	add	rax, -128
	mov	rbx, r11
	add	rbx, rax
	jne	.LBB0_59
.LBB0_60:
	cmp	rdx, r8
	je	.LBB0_44
# %bb.61:
	test	dl, 120
	je	.LBB0_75
.LBB0_62:
	mov	r14, rdx
	and	r14, -8
	mov	r11d, edx
	and	r11d, 7
	mov	rbx, r14
	neg	rbx
	mov	rax, r10
	sub	rax, r14
	mov	rcx, r9
	sub	rcx, r14
	neg	r8
	.p2align	4, 0x90
.LBB0_63:                               # =>This Inner Loop Header: Depth=1
	mov	rsi, qword ptr [r10 + r8 - 8]
	mov	qword ptr [r9 + r8 - 8], rsi
	add	r8, -8
	cmp	rbx, r8
	jne	.LBB0_63
# %bb.64:
	cmp	rdx, r14
	jne	.LBB0_17
	jmp	.LBB0_44
.LBB0_65:
	and	rcx, -4
	neg	rcx
	xor	eax, eax
	.p2align	4, 0x90
.LBB0_66:                               # =>This Inner Loop Header: Depth=1
	vmovups	ymm0, ymmword ptr [rsi + rax]
	vmovups	ymm1, ymmword ptr [rsi + rax + 32]
	vmovups	ymm2, ymmword ptr [rsi + rax + 64]
	vmovups	ymm3, ymmword ptr [rsi + rax + 96]
	vmovups	ymmword ptr [r10 + rax], ymm0
	vmovups	ymmword ptr [r10 + rax + 32], ymm1
	vmovups	ymmword ptr [r10 + rax + 64], ymm2
	vmovups	ymmword ptr [r10 + rax + 96], ymm3
	vmovups	ymm0, ymmword ptr [rsi + rax + 128]
	vmovups	ymm1, ymmword ptr [rsi + rax + 160]
	vmovups	ymm2, ymmword ptr [rsi + rax + 192]
	vmovups	ymm3, ymmword ptr [rsi + rax + 224]
	vmovups	ymmword ptr [r10 + rax + 128], ymm0
	vmovups	ymmword ptr [r10 + rax + 160], ymm1
	vmovups	ymmword ptr [r10 + rax + 192], ymm2
	vmovups	ymmword ptr [r10 + rax + 224], ymm3
	vmovups	ymm0, ymmword ptr [rsi + rax + 256]
	vmovups	ymm1, ymmword ptr [rsi + rax + 288]
	vmovups	ymm2, ymmword ptr [rsi + rax + 320]
	vmovups	ymm3, ymmword ptr [rsi + rax + 352]
	vmovups	ymmword ptr [r10 + rax + 256], ymm0
	vmovups	ymmword ptr [r10 + rax + 288], ymm1
	vmovups	ymmword ptr [r10 + rax + 320], ymm2
	vmovups	ymmword ptr [r10 + rax + 352], ymm3
	vmovups	ymm0, ymmword ptr [rsi + rax + 384]
	vmovups	ymm1, ymmword ptr [rsi + rax + 416]
	vmovups	ymm2, ymmword ptr [rsi + rax + 448]
	vmovups	ymm3, ymmword ptr [rsi + rax + 480]
	vmovups	ymmword ptr [r10 + rax + 384], ymm0
	vmovups	ymmword ptr [r10 + rax + 416], ymm1
	vmovups	ymmword ptr [r10 + rax + 448], ymm2
	vmovups	ymmword ptr [r10 + rax + 480], ymm3
	add	rax, 512
	add	rcx, 4
	jne	.LBB0_66
.LBB0_67:
	test	r8, r8
	je	.LBB0_70
# %bb.68:
	lea	rcx, [r10 + rax]
	add	rcx, 96
	add	rax, rsi
	add	rax, 96
	shl	r8, 7
	xor	ebx, ebx
	.p2align	4, 0x90
.LBB0_69:                               # =>This Inner Loop Header: Depth=1
	vmovups	ymm0, ymmword ptr [rax + rbx - 96]
	vmovups	ymm1, ymmword ptr [rax + rbx - 64]
	vmovups	ymm2, ymmword ptr [rax + rbx - 32]
	vmovups	ymm3, ymmword ptr [rax + rbx]
	vmovups	ymmword ptr [rcx + rbx - 96], ymm0
	vmovups	ymmword ptr [rcx + rbx - 64], ymm1
	vmovups	ymmword ptr [rcx + rbx - 32], ymm2
	vmovups	ymmword ptr [rcx + rbx], ymm3
	sub	rbx, -128
	cmp	r8, rbx
	jne	.LBB0_69
.LBB0_70:
	cmp	rdx, r9
	je	.LBB0_44
# %bb.71:
	test	dl, 120
	je	.LBB0_76
.LBB0_72:
	mov	r11, rdx
	and	r11, -8
	mov	r8d, edx
	and	r8d, 7
	lea	rcx, [rsi + r11]
	lea	rax, [r10 + r11]
	.p2align	4, 0x90
.LBB0_73:                               # =>This Inner Loop Header: Depth=1
	mov	rbx, qword ptr [rsi + r9]
	mov	qword ptr [r10 + r9], rbx
	add	r9, 8
	cmp	r11, r9
	jne	.LBB0_73
# %bb.74:
	cmp	rdx, r11
	jne	.LBB0_37
	jmp	.LBB0_44
.LBB0_75:
	sub	r9, r8
	sub	r10, r8
	and	edx, 127
	jmp	.LBB0_16
.LBB0_76:
	add	r10, r9
	add	rsi, r9
	and	edx, 127
	jmp	.LBB0_36
.Lfunc_end0:
	.size	ft_memmove, .Lfunc_end0-ft_memmove
	.cfi_endproc
                                        # -- End function
	.globl	ft_memmove_ERMS                 # -- Begin function ft_memmove_ERMS
	.p2align	4, 0x90
	.type	ft_memmove_ERMS,@function
ft_memmove_ERMS:                        # @ft_memmove_ERMS
	.cfi_startproc
# %bb.0:
	xor	eax, eax
	test	rdi, rdi
	je	.LBB1_17
# %bb.1:
	test	rsi, rsi
	je	.LBB1_17
# %bb.2:
	mov	r8, rdi
	cmp	rdx, 64
	je	.LBB1_15
# %bb.3:
	cmp	rdx, 32
	jne	.LBB1_5
# %bb.4:
	prefetcht0	byte ptr [rsi + 32]
	vmovups	ymm0, ymmword ptr [rsi]
	vmovups	ymmword ptr [r8], ymm0
	jmp	.LBB1_16
.LBB1_15:
	prefetcht0	byte ptr [rsi + 64]
	vmovups	ymm0, ymmword ptr [rsi]
	vmovups	ymm1, ymmword ptr [rsi + 32]
	vmovups	ymmword ptr [r8], ymm0
	vmovups	ymmword ptr [r8 + 32], ymm1
	jmp	.LBB1_16
.LBB1_5:
	cmp	r8, rsi
	jae	.LBB1_10
# %bb.6:
	test	rdx, rdx
	je	.LBB1_9
# %bb.7:
	xor	eax, eax
	.p2align	4, 0x90
.LBB1_8:                                # =>This Inner Loop Header: Depth=1
	prefetcht0	byte ptr [rsi + rax]
	add	rax, 64
	cmp	rax, rdx
	jb	.LBB1_8
.LBB1_9:
	mov	rdi, r8
	mov	rcx, rdx
	#APP
	rep		movsb	byte ptr es:[rdi], byte ptr [rsi]
	#NO_APP
	jmp	.LBB1_16
.LBB1_10:
	jbe	.LBB1_16
# %bb.11:
	lea	rdi, [r8 + rdx]
	dec	rdi
	add	rsi, rdx
	dec	rsi
	test	rdx, rdx
	je	.LBB1_14
# %bb.12:
	xor	eax, eax
	mov	rcx, rsi
	.p2align	4, 0x90
.LBB1_13:                               # =>This Inner Loop Header: Depth=1
	prefetcht0	byte ptr [rcx]
	add	rax, 64
	add	rcx, -64
	cmp	rax, rdx
	jb	.LBB1_13
.LBB1_14:
	mov	rcx, rdx
	#APP
	std
	rep		movsb	byte ptr es:[rdi], byte ptr [rsi]
	cld
	#NO_APP
.LBB1_16:
	mov	rax, r8
.LBB1_17:
	vzeroupper
	ret
.Lfunc_end1:
	.size	ft_memmove_ERMS, .Lfunc_end1-ft_memmove_ERMS
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 12.0.1-19ubuntu3"
	.section	".note.GNU-stack","",@progbits
	.addrsig
