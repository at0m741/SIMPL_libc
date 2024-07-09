	.text
	.intel_syntax noprefix
	.file	"benchmark.c"
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3                               # -- Begin function benchmark
.LCPI0_0:
	.quad	0x412e848000000000              # double 1.0E+6
	.text
	.globl	benchmark
	.p2align	4, 0x90
	.type	benchmark,@function
benchmark:                              # @benchmark
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
	sub	rsp, 24
	.cfi_def_cfa_offset 80
	.cfi_offset rbx, -56
	.cfi_offset r12, -48
	.cfi_offset r13, -40
	.cfi_offset r14, -32
	.cfi_offset r15, -24
	.cfi_offset rbp, -16
	mov	r13, r9
	mov	r12, r8
	mov	rbx, rcx
	mov	rbp, rdx
	mov	qword ptr [rsp + 16], rsi       # 8-byte Spill
	mov	r14, rdi
	call	clock
	mov	qword ptr [rsp + 8], rax        # 8-byte Spill
	test	r13, r13
	je	.LBB0_3
# %bb.1:
	mov	r15, r13
	.p2align	4, 0x90
.LBB0_2:                                # =>This Inner Loop Header: Depth=1
	mov	rdi, rbp
	mov	rsi, rbx
	mov	rdx, r12
	call	r14
	add	r15, -1
	jne	.LBB0_2
.LBB0_3:
	call	clock
	sub	rax, qword ptr [rsp + 8]        # 8-byte Folded Reload
	vcvtsi2sd	xmm0, xmm0, rax
	vdivsd	xmm0, xmm0, qword ptr [rip + .LCPI0_0]
	mov	edi, offset .L.str
	mov	rsi, qword ptr [rsp + 16]       # 8-byte Reload
	mov	rdx, r13
	mov	al, 1
	add	rsp, 24
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
	jmp	printf                          # TAILCALL
.Lfunc_end0:
	.size	benchmark, .Lfunc_end0-benchmark
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3                               # -- Begin function main
.LCPI1_0:
	.quad	0x412e848000000000              # double 1.0E+6
	.text
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	push	r15
	.cfi_def_cfa_offset 16
	push	r14
	.cfi_def_cfa_offset 24
	push	r12
	.cfi_def_cfa_offset 32
	push	rbx
	.cfi_def_cfa_offset 40
	push	rax
	.cfi_def_cfa_offset 48
	.cfi_offset rbx, -40
	.cfi_offset r12, -32
	.cfi_offset r14, -24
	.cfi_offset r15, -16
	mov	edi, 10485761
	call	malloc
	mov	r14, rax
	mov	edi, 10485761
	call	malloc
	test	r14, r14
	je	.LBB1_2
# %bb.1:
	mov	r12, rax
	test	rax, rax
	je	.LBB1_2
# %bb.3:
	mov	edx, 10485760
	mov	rdi, r14
	mov	esi, 65
	call	memset@PLT
	mov	byte ptr [r14 + 10485760], 0
	mov	edx, 10485760
	mov	rdi, r12
	mov	esi, 65
	call	memset@PLT
	mov	byte ptr [r12 + 10485760], 0
	call	clock
	mov	r15, rax
	call	clock
	sub	rax, r15
	vcvtsi2sd	xmm0, xmm0, rax
	vdivsd	xmm0, xmm0, qword ptr [rip + .LCPI1_0]
	mov	ebx, 10000
	mov	edi, offset .L.str
	mov	esi, offset .L.str.2
	mov	edx, 10000
	mov	al, 1
	call	printf
	call	clock
	mov	r15, rax
	.p2align	4, 0x90
.LBB1_4:                                # =>This Inner Loop Header: Depth=1
	mov	edx, 10485760
	mov	rdi, r14
	mov	rsi, r12
	call	ft_strncmp
	add	rbx, -1
	jne	.LBB1_4
# %bb.5:
	call	clock
	sub	rax, r15
	vcvtsi2sd	xmm0, xmm1, rax
	vdivsd	xmm0, xmm0, qword ptr [rip + .LCPI1_0]
	mov	edi, offset .L.str
	mov	esi, offset .L.str.3
	mov	edx, 10000
	mov	al, 1
	call	printf
	mov	rdi, r14
	call	free
	mov	rdi, r12
	call	free
	xor	eax, eax
.LBB1_6:
	add	rsp, 8
	.cfi_def_cfa_offset 40
	pop	rbx
	.cfi_def_cfa_offset 32
	pop	r12
	.cfi_def_cfa_offset 24
	pop	r14
	.cfi_def_cfa_offset 16
	pop	r15
	.cfi_def_cfa_offset 8
	ret
.LBB1_2:
	.cfi_def_cfa_offset 48
	mov	rcx, qword ptr [rip + stderr]
	mov	edi, offset .L.str.1
	mov	esi, 25
	mov	edx, 1
	call	fwrite@PLT
	mov	eax, 1
	jmp	.LBB1_6
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"%s took %f seconds to execute %zu iterations.\n"
	.size	.L.str, 47

	.type	.L.str.1,@object                # @.str.1
.L.str.1:
	.asciz	"Memory allocation failed\n"
	.size	.L.str.1, 26

	.type	.L.str.2,@object                # @.str.2
.L.str.2:
	.asciz	"glibc strncmp"
	.size	.L.str.2, 14

	.type	.L.str.3,@object                # @.str.3
.L.str.3:
	.asciz	"ft_strncmp"
	.size	.L.str.3, 11

	.ident	"Ubuntu clang version 12.0.1-19ubuntu3"
	.section	".note.GNU-stack","",@progbits
	.addrsig
