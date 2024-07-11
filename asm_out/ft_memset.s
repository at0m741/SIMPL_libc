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
	mov	rbx, rdx
	mov	r12d, esi
	mov	r14, rdi
	mov	rax, rdi
	movzx	r15d, r12b
	and	rax, 31
	je	.LBB0_1
# %bb.2:
	mov	ebp, 32
	sub	rbp, rax
	cmp	rbp, rbx
	cmova	rbp, rbx
	test	rbp, rbp
	je	.LBB0_4
# %bb.3:
	mov	rdi, r14
	mov	esi, r15d
	mov	rdx, rbp
	call	memset@PLT
.LBB0_4:
	lea	rdi, [r14 + rbp]
	sub	rbx, rbp
	mov	edx, ebx
	and	edx, 31
	cmp	rbx, 32
	jae	.LBB0_6
	jmp	.LBB0_11
.LBB0_1:
	mov	rdi, r14
	mov	edx, ebx
	and	edx, 31
	cmp	rbx, 32
	jb	.LBB0_11
.LBB0_6:
	vmovd	xmm0, r12d
	vpbroadcastb	ymm0, xmm0
	mov	rsi, rbx
	shr	rsi, 5
	lea	rcx, [rsi - 1]
	mov	eax, esi
	and	eax, 7
	cmp	rcx, 7
	jae	.LBB0_14
# %bb.7:
	xor	ecx, ecx
	jmp	.LBB0_8
.LBB0_14:
	and	rsi, -8
	lea	rbp, [rdi + 224]
	xor	ecx, ecx
	.p2align	4, 0x90
.LBB0_15:                               # =>This Inner Loop Header: Depth=1
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
	cmp	rsi, rcx
	jne	.LBB0_15
.LBB0_8:
	test	rax, rax
	je	.LBB0_11
# %bb.9:
	shl	rcx, 5
	add	rcx, rdi
	shl	rax, 5
	xor	esi, esi
	.p2align	4, 0x90
.LBB0_10:                               # =>This Inner Loop Header: Depth=1
	vmovdqu	ymmword ptr [rcx + rsi], ymm0
	add	rsi, 32
	cmp	rax, rsi
	jne	.LBB0_10
.LBB0_11:
	test	rdx, rdx
	je	.LBB0_13
# %bb.12:
	and	rbx, -32
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
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	sub	rsp, 216
	.cfi_def_cfa_offset 224
	vmovups	ymm0, ymmword ptr [rip + .L__const.main.str2]
	vmovups	ymmword ptr [rsp + 112], ymm0
	vmovups	ymm1, ymmword ptr [rip + .L__const.main.str2+64]
	vmovups	ymmword ptr [rsp + 176], ymm1
	vmovups	ymm2, ymmword ptr [rip + .L__const.main.str2+32]
	vmovups	ymmword ptr [rsp + 144], ymm2
	mov	dword ptr [rsp + 208], 0
	mov	dword ptr [rsp + 112], 1094795585
	vmovups	ymmword ptr [rsp], ymm0
	vmovups	ymmword ptr [rsp + 64], ymm1
	mov	byte ptr [rsp + 116], 65
	vmovups	ymmword ptr [rsp + 32], ymm2
	mov	dword ptr [rsp + 96], 0
	mov	dword ptr [rsp], 1094795585
	mov	byte ptr [rsp + 4], 65
	mov	rdi, rsp
	vzeroupper
	call	puts@PLT
	lea	rdi, [rsp + 112]
	call	puts@PLT
	xor	eax, eax
	add	rsp, 216
	.cfi_def_cfa_offset 8
	ret
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.type	.L__const.main.str2,@object     # @__const.main.str2
	.section	.rodata,"a",@progbits
	.p2align	4
.L__const.main.str2:
	.asciz	"Hello, World!\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
	.size	.L__const.main.str2, 100

	.ident	"Ubuntu clang version 14.0.0-1ubuntu1.1"
	.section	".note.GNU-stack","",@progbits
	.addrsig
