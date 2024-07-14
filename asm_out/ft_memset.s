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
	push	r12
	.cfi_def_cfa_offset 40
	push	rbx
	.cfi_def_cfa_offset 48
	.cfi_offset rbx, -48
	.cfi_offset r12, -40
	.cfi_offset r14, -32
	.cfi_offset r15, -24
	.cfi_offset rbp, -16
	mov	r14, rdi
	test	rdi, rdi
	je	.LBB0_13
# %bb.1:
	mov	rbx, rdx
	test	rdx, rdx
	je	.LBB0_13
# %bb.2:
	mov	r12d, esi
	mov	rax, r14
	prefetchnta	byte ptr [r14]
	movzx	r15d, r12b
	and	rax, 31
	je	.LBB0_3
# %bb.4:
	mov	ebp, 32
	sub	rbp, rax
	cmp	rbp, rbx
	cmova	rbp, rbx
	mov	rdi, r14
	mov	esi, r15d
	mov	rdx, rbp
	call	memset@PLT
	lea	rdi, [r14 + rbp]
	sub	rbx, rbp
	prefetchnta	byte ptr [r14 + rbp]
	prefetchnta	byte ptr [r14 + rbp + 32]
	jmp	.LBB0_5
.LBB0_3:
	mov	rdi, r14
.LBB0_5:
	mov	rcx, rbx
	shr	rcx, 5
	mov	edx, ebx
	and	edx, 31
	and	rbx, -32
	prefetchnta	byte ptr [rdi + rbx]
	test	rcx, rcx
	je	.LBB0_11
# %bb.6:
	vmovd	xmm0, r12d
	vpbroadcastb	ymm0, xmm0
	lea	rsi, [rcx - 1]
	mov	eax, ecx
	and	eax, 7
	cmp	rsi, 7
	jae	.LBB0_14
# %bb.7:
	xor	esi, esi
	jmp	.LBB0_8
.LBB0_14:
	and	rcx, -8
	lea	rbp, [rdi + 256]
	xor	esi, esi
	.p2align	4, 0x90
.LBB0_15:                               # =>This Inner Loop Header: Depth=1
	prefetchnta	byte ptr [rbp - 224]
	vmovdqu	ymmword ptr [rbp - 256], ymm0
	prefetchnta	byte ptr [rbp - 192]
	vmovdqu	ymmword ptr [rbp - 224], ymm0
	prefetchnta	byte ptr [rbp - 160]
	vmovdqu	ymmword ptr [rbp - 192], ymm0
	prefetchnta	byte ptr [rbp - 128]
	vmovdqu	ymmword ptr [rbp - 160], ymm0
	prefetchnta	byte ptr [rbp - 96]
	vmovdqu	ymmword ptr [rbp - 128], ymm0
	prefetchnta	byte ptr [rbp - 64]
	vmovdqu	ymmword ptr [rbp - 96], ymm0
	prefetchnta	byte ptr [rbp - 32]
	vmovdqu	ymmword ptr [rbp - 64], ymm0
	add	rsi, 8
	prefetchnta	byte ptr [rbp]
	vmovdqu	ymmword ptr [rbp - 32], ymm0
	add	rbp, 256
	cmp	rcx, rsi
	jne	.LBB0_15
.LBB0_8:
	test	rax, rax
	je	.LBB0_11
# %bb.9:
	shl	rsi, 5
	lea	rcx, [rsi + rdi]
	add	rcx, 32
	shl	rax, 5
	xor	esi, esi
	.p2align	4, 0x90
.LBB0_10:                               # =>This Inner Loop Header: Depth=1
	prefetchnta	byte ptr [rcx + rsi]
	vmovdqu	ymmword ptr [rcx + rsi - 32], ymm0
	add	rsi, 32
	cmp	rax, rsi
	jne	.LBB0_10
.LBB0_11:
	test	rdx, rdx
	je	.LBB0_13
# %bb.12:
	add	rdi, rbx
	mov	esi, r15d
	vzeroupper
	call	memset@PLT
.LBB0_13:
	mov	rax, r14
	pop	rbx
	.cfi_def_cfa_offset 40
	pop	r12
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
	.globl	ERMS                            # -- Begin function ERMS
	.p2align	4, 0x90
	.type	ERMS,@function
ERMS:                                   # @ERMS
	.cfi_startproc
# %bb.0:
	push	rbx
	.cfi_def_cfa_offset 16
	.cfi_offset rbx, -16
	mov	eax, 7
	xor	ecx, ecx
	#APP
	cpuid
	#NO_APP
	mov	eax, ecx
	shr	eax, 9
	and	eax, 1
	pop	rbx
	.cfi_def_cfa_offset 8
	ret
.Lfunc_end1:
	.size	ERMS, .Lfunc_end1-ERMS
	.cfi_endproc
                                        # -- End function
	.globl	ft_memset_ERMS                  # -- Begin function ft_memset_ERMS
	.p2align	4, 0x90
	.type	ft_memset_ERMS,@function
ft_memset_ERMS:                         # @ft_memset_ERMS
	.cfi_startproc
# %bb.0:
	mov	rcx, rdx
	mov	eax, esi
	mov	rdx, rdi
	test	rcx, rcx
	je	.LBB2_3
# %bb.1:
	xor	esi, esi
	.p2align	4, 0x90
.LBB2_2:                                # =>This Inner Loop Header: Depth=1
	prefetcht0	byte ptr [rdx + rsi]
	add	rsi, 64
	cmp	rsi, rcx
	jb	.LBB2_2
.LBB2_3:
                                        # kill: def $al killed $al killed $eax
	mov	rdi, rdx
	#APP
	rep		stosb	byte ptr es:[rdi], al
	#NO_APP
	mov	rax, rdx
	ret
.Lfunc_end2:
	.size	ft_memset_ERMS, .Lfunc_end2-ft_memset_ERMS
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 12.0.1-19ubuntu3"
	.section	".note.GNU-stack","",@progbits
	.addrsig
