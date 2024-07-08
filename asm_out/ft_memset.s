	.text
	.intel_syntax noprefix
	.file	"ft_memset.c"
	.globl	ft_memset                       # -- Begin function ft_memset
	.p2align	4, 0x90
	.type	ft_memset,@function
ft_memset:                              # @ft_memset
	.cfi_startproc
# %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	push	r15
	.cfi_def_cfa_offset 24
	push	r14
	.cfi_def_cfa_offset 32
	push	r13
	.cfi_def_cfa_offset 40
	push	r12
	.cfi_def_cfa_offset 48
	push	rbx
	.cfi_def_cfa_offset 56
	push	rax
	.cfi_def_cfa_offset 64
	.cfi_offset rbx, -56
	.cfi_offset r12, -48
	.cfi_offset r13, -40
	.cfi_offset r14, -32
	.cfi_offset r15, -24
	.cfi_offset rbp, -16
	mov	r13, rdx
	mov	r12d, esi
	mov	r14, rdi
	mov	rax, rdi
	movzx	r15d, r12b
	and	rax, 31
	je	.LBB0_1
# %bb.2:
	mov	ebp, 32
	sub	rbp, rax
	cmp	rbp, r13
	cmova	rbp, r13
	test	rbp, rbp
	je	.LBB0_4
# %bb.3:
	mov	rdi, r14
	mov	esi, r15d
	mov	rdx, rbp
	call	memset@PLT
.LBB0_4:
	lea	rdi, [r14 + rbp]
	sub	r13, rbp
	jmp	.LBB0_5
.LBB0_1:
	mov	rdi, r14
.LBB0_5:
	mov	rax, r13
	shr	rax, 5
	mov	edx, r13d
	and	edx, 31
	test	rax, rax
	je	.LBB0_18
# %bb.6:
	lea	r8, [rax - 1]
	mov	rsi, r8
	shr	rsi, 3
	add	rsi, 1
	mov	ecx, esi
	and	ecx, 7
	cmp	r8, 56
	jae	.LBB0_8
# %bb.7:
	xor	ebp, ebp
	jmp	.LBB0_10
.LBB0_8:
	lea	rbx, [rdi + 1792]
	and	rsi, -8
	neg	rsi
	xor	ebp, ebp
	.p2align	4, 0x90
.LBB0_9:                                # =>This Inner Loop Header: Depth=1
	prefetcht1	byte ptr [rbx - 1792]
	prefetcht1	byte ptr [rbx - 1536]
	prefetcht1	byte ptr [rbx - 1280]
	prefetcht1	byte ptr [rbx - 1024]
	prefetcht1	byte ptr [rbx - 768]
	prefetcht1	byte ptr [rbx - 512]
	prefetcht1	byte ptr [rbx - 256]
	prefetcht1	byte ptr [rbx]
	add	rbp, 64
	add	rbx, 2048
	add	rsi, 8
	jne	.LBB0_9
.LBB0_10:
	vmovd	xmm0, r12d
	test	rcx, rcx
	je	.LBB0_13
# %bb.11:
	shl	rbp, 5
	add	rbp, rdi
	shl	rcx, 8
	xor	esi, esi
	.p2align	4, 0x90
.LBB0_12:                               # =>This Inner Loop Header: Depth=1
	prefetcht1	byte ptr [rbp + rsi]
	add	rsi, 256
	cmp	rcx, rsi
	jne	.LBB0_12
.LBB0_13:
	vpbroadcastb	ymm0, xmm0
	mov	esi, eax
	and	esi, 7
	cmp	r8, 7
	jae	.LBB0_21
# %bb.14:
	xor	ecx, ecx
	jmp	.LBB0_15
.LBB0_21:
	and	rax, -8
	lea	rbp, [rdi + 224]
	xor	ecx, ecx
	.p2align	4, 0x90
.LBB0_22:                               # =>This Inner Loop Header: Depth=1
	vmovdqu	ymmword ptr [rbp - 224], ymm0
	vmovdqu	ymmword ptr [rbp - 192], ymm0
	vmovdqu	ymmword ptr [rbp - 160], ymm0
	vmovdqu	ymmword ptr [rbp - 128], ymm0
	vmovdqu	ymmword ptr [rbp - 96], ymm0
	vmovdqu	ymmword ptr [rbp - 64], ymm0
	vmovdqu	ymmword ptr [rbp - 32], ymm0
	vmovdqu	ymmword ptr [rbp], ymm0
	add	rcx, 8
	add	rbp, 256
	cmp	rax, rcx
	jne	.LBB0_22
.LBB0_15:
	test	rsi, rsi
	je	.LBB0_18
# %bb.16:
	shl	rcx, 5
	add	rcx, rdi
	shl	rsi, 5
	xor	eax, eax
	.p2align	4, 0x90
.LBB0_17:                               # =>This Inner Loop Header: Depth=1
	vmovdqu	ymmword ptr [rcx + rax], ymm0
	add	rax, 32
	cmp	rsi, rax
	jne	.LBB0_17
.LBB0_18:
	test	rdx, rdx
	je	.LBB0_20
# %bb.19:
	and	r13, -32
	add	rdi, r13
	mov	esi, r15d
	vzeroupper
	call	memset@PLT
.LBB0_20:
	mov	rax, r14
	add	rsp, 8
	.cfi_def_cfa_offset 56
	pop	rbx
	.cfi_def_cfa_offset 48
	pop	r12
	.cfi_def_cfa_offset 40
	pop	r13
	.cfi_def_cfa_offset 32
	pop	r14
	.cfi_def_cfa_offset 24
	pop	r15
	.cfi_def_cfa_offset 16
	pop	rbp
	.cfi_def_cfa_offset 8
	vzeroupper
	ret
.Lfunc_end0:
	.size	ft_memset, .Lfunc_end0-ft_memset
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 12.0.1-19ubuntu3"
	.section	".note.GNU-stack","",@progbits
	.addrsig
