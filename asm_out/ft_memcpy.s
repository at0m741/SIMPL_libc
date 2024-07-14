	.text
	.intel_syntax noprefix
	.file	"ft_memcpy.c"
	.globl	ft_memcpy                       # -- Begin function ft_memcpy
	.p2align	4, 0x90
	.type	ft_memcpy,@function
ft_memcpy:                              # @ft_memcpy
	.cfi_startproc
# %bb.0:
	xor	eax, eax
	test	rdi, rdi
	je	.LBB0_25
# %bb.1:
	test	rsi, rsi
	je	.LBB0_25
# %bb.2:
	mov	rax, rdi
	and	rax, 31
	je	.LBB0_3
# %bb.4:
	mov	r8d, 32
	sub	r8, rax
	cmp	r8, rdx
	cmova	r8, rdx
	test	r8, r8
	je	.LBB0_5
# %bb.6:
	lea	rax, [r8 - 1]
	mov	r9d, r8d
	and	r9d, 7
	cmp	rax, 7
	jae	.LBB0_26
# %bb.7:
                                        # implicit-def: $r10
	mov	rcx, rdi
	test	r9, r9
	jne	.LBB0_9
	jmp	.LBB0_10
.LBB0_3:
	xor	r8d, r8d
	mov	rcx, rdi
	shr	rdx, 8
	jne	.LBB0_12
	jmp	.LBB0_17
.LBB0_5:
	mov	r10, rsi
	mov	rcx, rdi
	jmp	.LBB0_10
.LBB0_26:
	mov	r10, r8
	and	r10, -8
	neg	r10
	mov	rcx, rdi
	.p2align	4, 0x90
.LBB0_27:                               # =>This Inner Loop Header: Depth=1
	movzx	eax, byte ptr [rsi]
	mov	byte ptr [rcx], al
	prefetcht0	byte ptr [rsi + 1]
	movzx	eax, byte ptr [rsi + 1]
	mov	byte ptr [rcx + 1], al
	prefetcht0	byte ptr [rsi + 2]
	movzx	eax, byte ptr [rsi + 2]
	mov	byte ptr [rcx + 2], al
	prefetcht0	byte ptr [rsi + 3]
	movzx	eax, byte ptr [rsi + 3]
	mov	byte ptr [rcx + 3], al
	prefetcht0	byte ptr [rsi + 4]
	movzx	eax, byte ptr [rsi + 4]
	mov	byte ptr [rcx + 4], al
	prefetcht0	byte ptr [rsi + 5]
	movzx	eax, byte ptr [rsi + 5]
	mov	byte ptr [rcx + 5], al
	prefetcht0	byte ptr [rsi + 6]
	movzx	eax, byte ptr [rsi + 6]
	mov	byte ptr [rcx + 6], al
	prefetcht0	byte ptr [rsi + 7]
	movzx	eax, byte ptr [rsi + 7]
	mov	byte ptr [rcx + 7], al
	prefetcht0	byte ptr [rsi + 8]
	add	rsi, 8
	add	rcx, 8
	add	r10, 8
	jne	.LBB0_27
# %bb.28:
	mov	r10, rsi
	test	r9, r9
	je	.LBB0_10
	.p2align	4, 0x90
.LBB0_9:                                # =>This Inner Loop Header: Depth=1
	lea	r10, [rsi + 1]
	movzx	eax, byte ptr [rsi]
	mov	byte ptr [rcx], al
	inc	rcx
	prefetcht0	byte ptr [rsi + 1]
	mov	rsi, r10
	dec	r9
	jne	.LBB0_9
.LBB0_10:
	sub	rdx, r8
	mov	rsi, r10
	shr	rdx, 8
	je	.LBB0_17
.LBB0_12:
	lea	r9, [rdx - 1]
	mov	eax, edx
	and	eax, 7
	cmp	r9, 7
	jb	.LBB0_15
# %bb.13:
	and	rdx, -8
	neg	rdx
	.p2align	4, 0x90
.LBB0_14:                               # =>This Inner Loop Header: Depth=1
	vmovups	ymm0, ymmword ptr [rsi]
	vmovups	ymmword ptr [rcx], ymm0
	prefetcht0	byte ptr [rsi + 512]
	prefetcht0	byte ptr [rcx + 512]
	vmovups	ymm0, ymmword ptr [rsi + 256]
	vmovups	ymmword ptr [rcx + 256], ymm0
	prefetcht0	byte ptr [rsi + 768]
	prefetcht0	byte ptr [rcx + 768]
	vmovups	ymm0, ymmword ptr [rsi + 512]
	vmovups	ymmword ptr [rcx + 512], ymm0
	prefetcht0	byte ptr [rsi + 1024]
	prefetcht0	byte ptr [rcx + 1024]
	vmovups	ymm0, ymmword ptr [rsi + 768]
	vmovups	ymmword ptr [rcx + 768], ymm0
	prefetcht0	byte ptr [rsi + 1280]
	prefetcht0	byte ptr [rcx + 1280]
	vmovups	ymm0, ymmword ptr [rsi + 1024]
	vmovups	ymmword ptr [rcx + 1024], ymm0
	prefetcht0	byte ptr [rsi + 1536]
	prefetcht0	byte ptr [rcx + 1536]
	vmovups	ymm0, ymmword ptr [rsi + 1280]
	vmovups	ymmword ptr [rcx + 1280], ymm0
	prefetcht0	byte ptr [rsi + 1792]
	prefetcht0	byte ptr [rcx + 1792]
	vmovups	ymm0, ymmword ptr [rsi + 1536]
	vmovups	ymmword ptr [rcx + 1536], ymm0
	prefetcht0	byte ptr [rsi + 2048]
	prefetcht0	byte ptr [rcx + 2048]
	vmovups	ymm0, ymmword ptr [rsi + 1792]
	vmovups	ymmword ptr [rcx + 1792], ymm0
	prefetcht0	byte ptr [rsi + 2304]
	add	rsi, 2048
	prefetcht0	byte ptr [rcx + 2304]
	add	rcx, 2048
	add	rdx, 8
	jne	.LBB0_14
.LBB0_15:
	test	rax, rax
	je	.LBB0_17
	.p2align	4, 0x90
.LBB0_16:                               # =>This Inner Loop Header: Depth=1
	vmovups	ymm0, ymmword ptr [rsi]
	vmovups	ymmword ptr [rcx], ymm0
	prefetcht0	byte ptr [rsi + 512]
	add	rsi, 256
	prefetcht0	byte ptr [rcx + 512]
	add	rcx, 256
	dec	rax
	jne	.LBB0_16
.LBB0_17:
	test	r8, r8
	je	.LBB0_24
# %bb.18:
	lea	rdx, [r8 - 1]
	mov	r9d, r8d
	and	r9d, 7
	cmp	rdx, 7
	jb	.LBB0_21
# %bb.19:
	and	r8, -8
	neg	r8
	.p2align	4, 0x90
.LBB0_20:                               # =>This Inner Loop Header: Depth=1
	movzx	edx, byte ptr [rsi]
	mov	byte ptr [rcx], dl
	prefetcht0	byte ptr [rsi + 1]
	movzx	edx, byte ptr [rsi + 1]
	mov	byte ptr [rcx + 1], dl
	prefetcht0	byte ptr [rsi + 2]
	movzx	edx, byte ptr [rsi + 2]
	mov	byte ptr [rcx + 2], dl
	prefetcht0	byte ptr [rsi + 3]
	movzx	edx, byte ptr [rsi + 3]
	mov	byte ptr [rcx + 3], dl
	prefetcht0	byte ptr [rsi + 4]
	movzx	edx, byte ptr [rsi + 4]
	mov	byte ptr [rcx + 4], dl
	prefetcht0	byte ptr [rsi + 5]
	movzx	edx, byte ptr [rsi + 5]
	mov	byte ptr [rcx + 5], dl
	prefetcht0	byte ptr [rsi + 6]
	movzx	edx, byte ptr [rsi + 6]
	mov	byte ptr [rcx + 6], dl
	prefetcht0	byte ptr [rsi + 7]
	movzx	edx, byte ptr [rsi + 7]
	mov	byte ptr [rcx + 7], dl
	prefetcht0	byte ptr [rsi + 8]
	add	rsi, 8
	add	rcx, 8
	add	r8, 8
	jne	.LBB0_20
.LBB0_21:
	test	r9, r9
	je	.LBB0_24
# %bb.22:
	inc	rsi
	xor	edx, edx
	.p2align	4, 0x90
.LBB0_23:                               # =>This Inner Loop Header: Depth=1
	movzx	eax, byte ptr [rsi + rdx - 1]
	mov	byte ptr [rcx + rdx], al
	prefetcht0	byte ptr [rsi + rdx]
	inc	rdx
	cmp	r9, rdx
	jne	.LBB0_23
.LBB0_24:
	mov	rax, rdi
.LBB0_25:
	vzeroupper
	ret
.Lfunc_end0:
	.size	ft_memcpy, .Lfunc_end0-ft_memcpy
	.cfi_endproc
                                        # -- End function
	.globl	ft_memcpy_ERMS                  # -- Begin function ft_memcpy_ERMS
	.p2align	4, 0x90
	.type	ft_memcpy_ERMS,@function
ft_memcpy_ERMS:                         # @ft_memcpy_ERMS
	.cfi_startproc
# %bb.0:
	mov	rcx, rdx
	mov	rax, rdi
	test	rdx, rdx
	je	.LBB1_3
# %bb.1:
	lea	rdx, [rsi + 64]
	xor	edi, edi
	.p2align	4, 0x90
.LBB1_2:                                # =>This Inner Loop Header: Depth=1
	prefetcht0	byte ptr [rdx + rdi]
	add	rdi, 64
	cmp	rdi, rcx
	jb	.LBB1_2
.LBB1_3:
	mov	rdi, rax
	#APP
	rep		movsb	byte ptr es:[rdi], byte ptr [rsi]
	#NO_APP
	ret
.Lfunc_end1:
	.size	ft_memcpy_ERMS, .Lfunc_end1-ft_memcpy_ERMS
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 12.0.1-19ubuntu3"
	.section	".note.GNU-stack","",@progbits
	.addrsig
