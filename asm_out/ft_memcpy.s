	.text
	.intel_syntax noprefix
	.file	"ft_memcpy.c"
	.globl	ft_memcpy                       # -- Begin function ft_memcpy
	.p2align	4, 0x90
	.type	ft_memcpy,@function
ft_memcpy:                              # @ft_memcpy
	.cfi_startproc
# %bb.0:
	mov	rax, rdi
	mov	rcx, rdi
	and	rcx, 31
	je	.LBB0_1
# %bb.2:
	mov	r8d, 32
	sub	r8, rcx
	cmp	r8, rdx
	cmova	r8, rdx
	test	r8, r8
	je	.LBB0_3
# %bb.4:
	lea	rcx, [r8 - 1]
	mov	r9d, r8d
	and	r9d, 7
	cmp	rcx, 7
	jae	.LBB0_23
# %bb.5:
                                        # implicit-def: $r10
	mov	rdi, rax
	test	r9, r9
	jne	.LBB0_7
	jmp	.LBB0_8
.LBB0_1:
	xor	r8d, r8d
	mov	rdi, rax
	cmp	rdx, 256
	jae	.LBB0_10
	jmp	.LBB0_15
.LBB0_3:
	mov	r10, rsi
	mov	rdi, rax
	jmp	.LBB0_8
.LBB0_23:
	mov	r10d, r8d
	and	r10d, 56
	mov	rdi, rax
	.p2align	4, 0x90
.LBB0_24:                               # =>This Inner Loop Header: Depth=1
	movzx	ecx, byte ptr [rsi]
	mov	byte ptr [rdi], cl
	prefetcht0	byte ptr [rsi + 1]
	movzx	ecx, byte ptr [rsi + 1]
	mov	byte ptr [rdi + 1], cl
	prefetcht0	byte ptr [rsi + 2]
	movzx	ecx, byte ptr [rsi + 2]
	mov	byte ptr [rdi + 2], cl
	prefetcht0	byte ptr [rsi + 3]
	movzx	ecx, byte ptr [rsi + 3]
	mov	byte ptr [rdi + 3], cl
	prefetcht0	byte ptr [rsi + 4]
	movzx	ecx, byte ptr [rsi + 4]
	mov	byte ptr [rdi + 4], cl
	prefetcht0	byte ptr [rsi + 5]
	movzx	ecx, byte ptr [rsi + 5]
	mov	byte ptr [rdi + 5], cl
	prefetcht0	byte ptr [rsi + 6]
	movzx	ecx, byte ptr [rsi + 6]
	mov	byte ptr [rdi + 6], cl
	prefetcht0	byte ptr [rsi + 7]
	movzx	ecx, byte ptr [rsi + 7]
	mov	byte ptr [rdi + 7], cl
	prefetcht0	byte ptr [rsi + 8]
	add	rsi, 8
	add	rdi, 8
	add	r10, -8
	jne	.LBB0_24
# %bb.25:
	mov	r10, rsi
	test	r9, r9
	je	.LBB0_8
	.p2align	4, 0x90
.LBB0_7:                                # =>This Inner Loop Header: Depth=1
	lea	r10, [rsi + 1]
	movzx	ecx, byte ptr [rsi]
	mov	byte ptr [rdi], cl
	inc	rdi
	prefetcht0	byte ptr [rsi + 1]
	mov	rsi, r10
	dec	r9
	jne	.LBB0_7
.LBB0_8:
	sub	rdx, r8
	mov	rsi, r10
	cmp	rdx, 256
	jb	.LBB0_15
.LBB0_10:
	shr	rdx, 8
	lea	r9, [rdx - 1]
	mov	ecx, edx
	and	ecx, 7
	cmp	r9, 7
	jb	.LBB0_13
# %bb.11:
	and	rdx, -8
	.p2align	4, 0x90
.LBB0_12:                               # =>This Inner Loop Header: Depth=1
	vmovups	ymm0, ymmword ptr [rsi]
	vmovups	ymmword ptr [rdi], ymm0
	prefetcht0	byte ptr [rsi + 512]
	prefetcht0	byte ptr [rdi + 512]
	vmovups	ymm0, ymmword ptr [rsi + 256]
	vmovups	ymmword ptr [rdi + 256], ymm0
	prefetcht0	byte ptr [rsi + 768]
	prefetcht0	byte ptr [rdi + 768]
	vmovups	ymm0, ymmword ptr [rsi + 512]
	vmovups	ymmword ptr [rdi + 512], ymm0
	prefetcht0	byte ptr [rsi + 1024]
	prefetcht0	byte ptr [rdi + 1024]
	vmovups	ymm0, ymmword ptr [rsi + 768]
	vmovups	ymmword ptr [rdi + 768], ymm0
	prefetcht0	byte ptr [rsi + 1280]
	prefetcht0	byte ptr [rdi + 1280]
	vmovups	ymm0, ymmword ptr [rsi + 1024]
	vmovups	ymmword ptr [rdi + 1024], ymm0
	prefetcht0	byte ptr [rsi + 1536]
	prefetcht0	byte ptr [rdi + 1536]
	vmovups	ymm0, ymmword ptr [rsi + 1280]
	vmovups	ymmword ptr [rdi + 1280], ymm0
	prefetcht0	byte ptr [rsi + 1792]
	prefetcht0	byte ptr [rdi + 1792]
	vmovups	ymm0, ymmword ptr [rsi + 1536]
	vmovups	ymmword ptr [rdi + 1536], ymm0
	prefetcht0	byte ptr [rsi + 2048]
	prefetcht0	byte ptr [rdi + 2048]
	vmovups	ymm0, ymmword ptr [rsi + 1792]
	vmovups	ymmword ptr [rdi + 1792], ymm0
	prefetcht0	byte ptr [rsi + 2304]
	add	rsi, 2048
	prefetcht0	byte ptr [rdi + 2304]
	add	rdi, 2048
	add	rdx, -8
	jne	.LBB0_12
.LBB0_13:
	test	rcx, rcx
	je	.LBB0_15
	.p2align	4, 0x90
.LBB0_14:                               # =>This Inner Loop Header: Depth=1
	vmovups	ymm0, ymmword ptr [rsi]
	vmovups	ymmword ptr [rdi], ymm0
	prefetcht0	byte ptr [rsi + 512]
	add	rsi, 256
	prefetcht0	byte ptr [rdi + 512]
	add	rdi, 256
	dec	rcx
	jne	.LBB0_14
.LBB0_15:
	test	r8, r8
	je	.LBB0_22
# %bb.16:
	lea	rdx, [r8 - 1]
	mov	r9d, r8d
	and	r9d, 7
	cmp	rdx, 7
	jb	.LBB0_19
# %bb.17:
	and	r8, -8
	.p2align	4, 0x90
.LBB0_18:                               # =>This Inner Loop Header: Depth=1
	movzx	ecx, byte ptr [rsi]
	mov	byte ptr [rdi], cl
	prefetcht0	byte ptr [rsi + 1]
	movzx	ecx, byte ptr [rsi + 1]
	mov	byte ptr [rdi + 1], cl
	prefetcht0	byte ptr [rsi + 2]
	movzx	ecx, byte ptr [rsi + 2]
	mov	byte ptr [rdi + 2], cl
	prefetcht0	byte ptr [rsi + 3]
	movzx	ecx, byte ptr [rsi + 3]
	mov	byte ptr [rdi + 3], cl
	prefetcht0	byte ptr [rsi + 4]
	movzx	ecx, byte ptr [rsi + 4]
	mov	byte ptr [rdi + 4], cl
	prefetcht0	byte ptr [rsi + 5]
	movzx	ecx, byte ptr [rsi + 5]
	mov	byte ptr [rdi + 5], cl
	prefetcht0	byte ptr [rsi + 6]
	movzx	ecx, byte ptr [rsi + 6]
	mov	byte ptr [rdi + 6], cl
	prefetcht0	byte ptr [rsi + 7]
	movzx	ecx, byte ptr [rsi + 7]
	mov	byte ptr [rdi + 7], cl
	prefetcht0	byte ptr [rsi + 8]
	add	rsi, 8
	add	rdi, 8
	add	r8, -8
	jne	.LBB0_18
.LBB0_19:
	test	r9, r9
	je	.LBB0_22
# %bb.20:
	inc	rsi
	xor	edx, edx
	.p2align	4, 0x90
.LBB0_21:                               # =>This Inner Loop Header: Depth=1
	movzx	ecx, byte ptr [rsi + rdx - 1]
	mov	byte ptr [rdi + rdx], cl
	prefetcht0	byte ptr [rsi + rdx]
	inc	rdx
	cmp	r9, rdx
	jne	.LBB0_21
.LBB0_22:
	vzeroupper
	ret
.Lfunc_end0:
	.size	ft_memcpy, .Lfunc_end0-ft_memcpy
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 14.0.0-1ubuntu1.1"
	.section	".note.GNU-stack","",@progbits
	.addrsig
