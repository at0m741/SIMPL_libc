	.text
	.intel_syntax noprefix
	.file	"ft_strncpy.c"
	.section	.rodata.cst32,"aM",@progbits,32
	.p2align	5                               # -- Begin function ft_strncpy
.LCPI0_0:
	.byte	31                              # 0x1f
	.byte	30                              # 0x1e
	.byte	29                              # 0x1d
	.byte	28                              # 0x1c
	.byte	27                              # 0x1b
	.byte	26                              # 0x1a
	.byte	25                              # 0x19
	.byte	24                              # 0x18
	.byte	23                              # 0x17
	.byte	22                              # 0x16
	.byte	21                              # 0x15
	.byte	20                              # 0x14
	.byte	19                              # 0x13
	.byte	18                              # 0x12
	.byte	17                              # 0x11
	.byte	16                              # 0x10
	.byte	15                              # 0xf
	.byte	14                              # 0xe
	.byte	13                              # 0xd
	.byte	12                              # 0xc
	.byte	11                              # 0xb
	.byte	10                              # 0xa
	.byte	9                               # 0x9
	.byte	8                               # 0x8
	.byte	7                               # 0x7
	.byte	6                               # 0x6
	.byte	5                               # 0x5
	.byte	4                               # 0x4
	.byte	3                               # 0x3
	.byte	2                               # 0x2
	.byte	1                               # 0x1
	.byte	0                               # 0x0
	.text
	.globl	ft_strncpy
	.p2align	4, 0x90
	.type	ft_strncpy,@function
ft_strncpy:                             # @ft_strncpy
	.cfi_startproc
# %bb.0:
	push	r15
	.cfi_def_cfa_offset 16
	push	r14
	.cfi_def_cfa_offset 24
	push	rbx
	.cfi_def_cfa_offset 32
	.cfi_offset rbx, -32
	.cfi_offset r14, -24
	.cfi_offset r15, -16
	mov	rax, rdi
	mov	r9, rdx
	shr	r9, 5
	mov	r8d, edx
	and	r8d, 31
	mov	rcx, rsi
	and	rcx, 31
	je	.LBB0_1
# %bb.2:
	mov	r10d, 32
	sub	r10, rcx
	cmp	r10, rdx
	cmova	r10, rdx
	test	r10, r10
	je	.LBB0_1
# %bb.3:
	lea	rcx, [r10 - 1]
	mov	r14d, r10d
	and	r14d, 7
	cmp	rcx, 7
	jae	.LBB0_5
# %bb.4:
                                        # implicit-def: $r11
                                        # implicit-def: $rcx
	mov	rdi, rax
	test	r14, r14
	jne	.LBB0_9
	jmp	.LBB0_11
.LBB0_1:
	mov	r11, rsi
	mov	rcx, rax
	jmp	.LBB0_11
.LBB0_5:
	mov	r11d, r10d
	and	r11d, 56
	lea	r15, [rax + r10]
	add	r15, 8
	lea	rbx, [rsi + r10]
	add	rbx, 8
	xor	edi, edi
	.p2align	4, 0x90
.LBB0_6:                                # =>This Inner Loop Header: Depth=1
	movzx	ecx, byte ptr [rsi + rdi]
	mov	byte ptr [rax + rdi], cl
	prefetchnta	byte ptr [rbx + rdi - 7]
	prefetchnta	byte ptr [r15 + rdi - 7]
	movzx	ecx, byte ptr [rsi + rdi + 1]
	mov	byte ptr [rax + rdi + 1], cl
	prefetchnta	byte ptr [rbx + rdi - 6]
	prefetchnta	byte ptr [r15 + rdi - 6]
	movzx	ecx, byte ptr [rsi + rdi + 2]
	mov	byte ptr [rax + rdi + 2], cl
	prefetchnta	byte ptr [rbx + rdi - 5]
	prefetchnta	byte ptr [r15 + rdi - 5]
	movzx	ecx, byte ptr [rsi + rdi + 3]
	mov	byte ptr [rax + rdi + 3], cl
	prefetchnta	byte ptr [rbx + rdi - 4]
	prefetchnta	byte ptr [r15 + rdi - 4]
	movzx	ecx, byte ptr [rsi + rdi + 4]
	mov	byte ptr [rax + rdi + 4], cl
	prefetchnta	byte ptr [rbx + rdi - 3]
	prefetchnta	byte ptr [r15 + rdi - 3]
	movzx	ecx, byte ptr [rsi + rdi + 5]
	mov	byte ptr [rax + rdi + 5], cl
	prefetchnta	byte ptr [rbx + rdi - 2]
	prefetchnta	byte ptr [r15 + rdi - 2]
	movzx	ecx, byte ptr [rsi + rdi + 6]
	mov	byte ptr [rax + rdi + 6], cl
	prefetchnta	byte ptr [rbx + rdi - 1]
	prefetchnta	byte ptr [r15 + rdi - 1]
	movzx	ecx, byte ptr [rsi + rdi + 7]
	mov	byte ptr [rax + rdi + 7], cl
	prefetchnta	byte ptr [rbx + rdi]
	prefetchnta	byte ptr [r15 + rdi]
	add	rdi, 8
	cmp	r11, rdi
	jne	.LBB0_6
# %bb.7:
	lea	rcx, [rax + rdi]
	add	rsi, rdi
	mov	r11, rsi
	mov	rdi, rcx
	test	r14, r14
	je	.LBB0_11
.LBB0_9:
	inc	r10
	.p2align	4, 0x90
.LBB0_10:                               # =>This Inner Loop Header: Depth=1
	lea	r11, [rsi + 1]
	movzx	ebx, byte ptr [rsi]
	lea	rcx, [rdi + 1]
	mov	byte ptr [rdi], bl
	prefetchnta	byte ptr [rsi + r10]
	prefetchnta	byte ptr [rdi + r10]
	mov	rdi, rcx
	mov	rsi, r11
	dec	r14
	jne	.LBB0_10
.LBB0_11:
	movabs	rsi, 576460752303423456
	and	rdx, rsi
	shl	rdx, 5
	prefetchnta	byte ptr [r11 + rdx]
	test	r9, r9
	je	.LBB0_18
# %bb.12:
	lea	rsi, [r9 - 1]
	mov	edx, r9d
	and	edx, 7
	cmp	rsi, 7
	jae	.LBB0_21
# %bb.13:
	xor	esi, esi
	jmp	.LBB0_14
.LBB0_21:
	mov	rdi, r9
	and	rdi, -8
	lea	rbx, [r11 + 224]
	xor	esi, esi
	.p2align	4, 0x90
.LBB0_22:                               # =>This Inner Loop Header: Depth=1
	vmovups	ymm0, ymmword ptr [rbx - 224]
	vmovups	ymmword ptr [rcx], ymm0
	vmovups	ymm0, ymmword ptr [rbx - 192]
	vmovups	ymmword ptr [rcx + 32], ymm0
	vmovups	ymm0, ymmword ptr [rbx - 160]
	vmovups	ymmword ptr [rcx + 64], ymm0
	vmovups	ymm0, ymmword ptr [rbx - 128]
	vmovups	ymmword ptr [rcx + 96], ymm0
	vmovups	ymm0, ymmword ptr [rbx - 96]
	vmovups	ymmword ptr [rcx + 128], ymm0
	vmovups	ymm0, ymmword ptr [rbx - 64]
	vmovups	ymmword ptr [rcx + 160], ymm0
	vmovups	ymm0, ymmword ptr [rbx - 32]
	vmovups	ymmword ptr [rcx + 192], ymm0
	vmovdqu	ymm0, ymmword ptr [rbx]
	vmovdqu	ymmword ptr [rcx + 224], ymm0
	add	rcx, 256
	add	rsi, 8
	add	rbx, 256
	cmp	rdi, rsi
	jne	.LBB0_22
.LBB0_14:
	test	rdx, rdx
	je	.LBB0_18
# %bb.15:
	shl	rsi, 5
	add	rsi, r11
	shl	rdx, 5
	xor	edi, edi
	.p2align	4, 0x90
.LBB0_16:                               # =>This Inner Loop Header: Depth=1
	vmovdqu	ymm0, ymmword ptr [rsi + rdi]
	vmovdqu	ymmword ptr [rcx + rdi], ymm0
	add	rdi, 32
	cmp	rdx, rdi
	jne	.LBB0_16
# %bb.17:
	add	rcx, rdi
.LBB0_18:
	test	r8, r8
	je	.LBB0_20
# %bb.19:
	vmovd	xmm0, r8d
	vpbroadcastb	ymm0, xmm0
	vpminub	ymm1, ymm0, ymmword ptr [rip + .LCPI0_0]
	shl	r9, 5
	vpcmpeqb	ymm0, ymm0, ymm1
	vpand	ymm0, ymm0, ymmword ptr [r11 + r9]
	vmovdqu	ymmword ptr [rcx], ymm0
.LBB0_20:
	pop	rbx
	.cfi_def_cfa_offset 24
	pop	r14
	.cfi_def_cfa_offset 16
	pop	r15
	.cfi_def_cfa_offset 8
	vzeroupper
	ret
.Lfunc_end0:
	.size	ft_strncpy, .Lfunc_end0-ft_strncpy
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 12.0.1-19ubuntu3"
	.section	".note.GNU-stack","",@progbits
	.addrsig
