	.text
	.intel_syntax noprefix
	.file	"get_cpu_info.c"
	.globl	get_cpu_features                # -- Begin function get_cpu_features
	.p2align	4, 0x90
	.type	get_cpu_features,@function
get_cpu_features:                       # @get_cpu_features
	.cfi_startproc
# %bb.0:
	sub	rsp, 40
	.cfi_def_cfa_offset 48
	mov	qword ptr [rsp - 128], offset .L.str
	mov	eax, dword ptr [rip + __cpu_model+12]
	mov	ecx, eax
	shr	ecx
	and	ecx, 1
	mov	dword ptr [rsp - 120], ecx
	mov	qword ptr [rsp - 112], offset .L.str.1
	mov	ecx, eax
	shr	ecx, 3
	and	ecx, 1
	mov	dword ptr [rsp - 104], ecx
	mov	qword ptr [rsp - 96], offset .L.str.2
	mov	ecx, eax
	shr	ecx, 4
	and	ecx, 1
	mov	dword ptr [rsp - 88], ecx
	mov	qword ptr [rsp - 80], offset .L.str.3
	mov	ecx, eax
	shr	ecx, 5
	and	ecx, 1
	mov	dword ptr [rsp - 72], ecx
	mov	qword ptr [rsp - 64], offset .L.str.4
	mov	ecx, eax
	shr	ecx, 6
	and	ecx, 1
	mov	dword ptr [rsp - 56], ecx
	mov	qword ptr [rsp - 48], offset .L.str.5
	mov	ecx, eax
	shr	ecx, 7
	and	ecx, 1
	mov	dword ptr [rsp - 40], ecx
	mov	qword ptr [rsp - 32], offset .L.str.6
	mov	ecx, eax
	shr	ecx, 8
	and	ecx, 1
	mov	dword ptr [rsp - 24], ecx
	mov	qword ptr [rsp - 16], offset .L.str.7
	mov	ecx, eax
	shr	ecx, 9
	and	ecx, 1
	mov	dword ptr [rsp - 8], ecx
	mov	qword ptr [rsp], offset .L.str.8
	mov	ecx, eax
	shr	ecx, 10
	and	ecx, 1
	mov	dword ptr [rsp + 8], ecx
	mov	qword ptr [rsp + 16], offset .L.str.9
	shr	eax, 15
	and	eax, 1
	mov	dword ptr [rsp + 24], eax
	test	rsi, rsi
	je	.LBB0_6
# %bb.1:
	lea	rax, [rsi - 1]
	cmp	rax, 9
	mov	ecx, 10
	cmovb	rcx, rsi
	lea	rdx, [rcx - 1]
	mov	eax, ecx
	and	eax, 3
	cmp	rdx, 3
	jae	.LBB0_7
# %bb.2:
	xor	edx, edx
	jmp	.LBB0_3
.LBB0_7:
	and	rcx, -4
	mov	esi, 48
	xor	edx, edx
	.p2align	4, 0x90
.LBB0_8:                                # =>This Inner Loop Header: Depth=1
	vmovups	xmm0, xmmword ptr [rsp + rsi - 176]
	vmovups	xmmword ptr [rdi + rsi - 48], xmm0
	vmovups	xmm0, xmmword ptr [rsp + rsi - 160]
	vmovups	xmmword ptr [rdi + rsi - 32], xmm0
	vmovups	xmm0, xmmword ptr [rsp + rsi - 144]
	vmovups	xmmword ptr [rdi + rsi - 16], xmm0
	vmovups	xmm0, xmmword ptr [rsp + rsi - 128]
	vmovups	xmmword ptr [rdi + rsi], xmm0
	add	rdx, 4
	add	rsi, 64
	cmp	rcx, rdx
	jne	.LBB0_8
.LBB0_3:
	test	rax, rax
	je	.LBB0_6
# %bb.4:
	shl	rdx, 4
	lea	rcx, [rsp + rdx]
	add	rcx, -128
	add	rdi, rdx
	shl	rax, 4
	xor	edx, edx
	.p2align	4, 0x90
.LBB0_5:                                # =>This Inner Loop Header: Depth=1
	vmovups	xmm0, xmmword ptr [rcx + rdx]
	vmovups	xmmword ptr [rdi + rdx], xmm0
	add	rdx, 16
	cmp	rax, rdx
	jne	.LBB0_5
.LBB0_6:
	add	rsp, 40
	.cfi_def_cfa_offset 8
	ret
.Lfunc_end0:
	.size	get_cpu_features, .Lfunc_end0-get_cpu_features
	.cfi_endproc
                                        # -- End function
	.globl	check_cpu_features              # -- Begin function check_cpu_features
	.p2align	4, 0x90
	.type	check_cpu_features,@function
check_cpu_features:                     # @check_cpu_features
	.cfi_startproc
# %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	push	r14
	.cfi_def_cfa_offset 24
	push	rbx
	.cfi_def_cfa_offset 32
	.cfi_offset rbx, -32
	.cfi_offset r14, -24
	.cfi_offset rbp, -16
	mov	ebp, dword ptr [rip + __cpu_model+12]
	mov	edi, offset .Lstr
	call	puts@PLT
	test	bpl, 2
	mov	ebx, offset .L.str.13
	mov	r14d, offset .L.str.12
	mov	edx, offset .L.str.12
	cmove	rdx, rbx
	mov	edi, offset .L.str.11
	mov	esi, offset .L.str
	xor	eax, eax
	call	printf
	test	bpl, 8
	mov	edx, offset .L.str.12
	cmove	rdx, rbx
	mov	edi, offset .L.str.11
	mov	esi, offset .L.str.1
	xor	eax, eax
	call	printf
	test	bpl, 16
	mov	edx, offset .L.str.12
	cmove	rdx, rbx
	mov	edi, offset .L.str.11
	mov	esi, offset .L.str.2
	xor	eax, eax
	call	printf
	test	bpl, 32
	mov	edx, offset .L.str.12
	cmove	rdx, rbx
	mov	edi, offset .L.str.11
	mov	esi, offset .L.str.3
	xor	eax, eax
	call	printf
	test	bpl, 64
	mov	edx, offset .L.str.12
	cmove	rdx, rbx
	mov	edi, offset .L.str.11
	mov	esi, offset .L.str.4
	xor	eax, eax
	call	printf
	test	bpl, bpl
	mov	edx, offset .L.str.12
	cmovns	rdx, rbx
	mov	edi, offset .L.str.11
	mov	esi, offset .L.str.5
	xor	eax, eax
	call	printf
	test	ebp, 256
	mov	edx, offset .L.str.12
	cmove	rdx, rbx
	mov	edi, offset .L.str.11
	mov	esi, offset .L.str.6
	xor	eax, eax
	call	printf
	test	ebp, 512
	mov	edx, offset .L.str.12
	cmove	rdx, rbx
	mov	edi, offset .L.str.11
	mov	esi, offset .L.str.7
	xor	eax, eax
	call	printf
	test	ebp, 1024
	mov	edx, offset .L.str.12
	cmove	rdx, rbx
	mov	edi, offset .L.str.11
	mov	esi, offset .L.str.8
	xor	eax, eax
	call	printf
	test	bp, bp
	cmovns	r14, rbx
	mov	edi, offset .L.str.11
	mov	esi, offset .L.str.9
	mov	rdx, r14
	xor	eax, eax
	pop	rbx
	.cfi_def_cfa_offset 24
	pop	r14
	.cfi_def_cfa_offset 16
	pop	rbp
	.cfi_def_cfa_offset 8
	jmp	printf                          # TAILCALL
.Lfunc_end1:
	.size	check_cpu_features, .Lfunc_end1-check_cpu_features
	.cfi_endproc
                                        # -- End function
	.globl	get_cpu_info                    # -- Begin function get_cpu_info
	.p2align	4, 0x90
	.type	get_cpu_info,@function
get_cpu_info:                           # @get_cpu_info
	.cfi_startproc
# %bb.0:
	movzx	ecx, word ptr [rip + __cpu_model+12]
	xor	eax, eax
	test	ecx, 34810
	setne	al
	ret
.Lfunc_end2:
	.size	get_cpu_info, .Lfunc_end2-get_cpu_info
	.cfi_endproc
                                        # -- End function
	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"mmx"
	.size	.L.str, 4

	.type	.L.str.1,@object                # @.str.1
.L.str.1:
	.asciz	"sse"
	.size	.L.str.1, 4

	.type	.L.str.2,@object                # @.str.2
.L.str.2:
	.asciz	"sse2"
	.size	.L.str.2, 5

	.type	.L.str.3,@object                # @.str.3
.L.str.3:
	.asciz	"sse3"
	.size	.L.str.3, 5

	.type	.L.str.4,@object                # @.str.4
.L.str.4:
	.asciz	"ssse3"
	.size	.L.str.4, 6

	.type	.L.str.5,@object                # @.str.5
.L.str.5:
	.asciz	"sse4.1"
	.size	.L.str.5, 7

	.type	.L.str.6,@object                # @.str.6
.L.str.6:
	.asciz	"sse4.2"
	.size	.L.str.6, 7

	.type	.L.str.7,@object                # @.str.7
.L.str.7:
	.asciz	"avx"
	.size	.L.str.7, 4

	.type	.L.str.8,@object                # @.str.8
.L.str.8:
	.asciz	"avx2"
	.size	.L.str.8, 5

	.type	.L.str.9,@object                # @.str.9
.L.str.9:
	.asciz	"avx512f"
	.size	.L.str.9, 8

	.type	.L.str.11,@object               # @.str.11
.L.str.11:
	.asciz	"%s: %s\n"
	.size	.L.str.11, 8

	.type	.L.str.12,@object               # @.str.12
.L.str.12:
	.asciz	"supported"
	.size	.L.str.12, 10

	.type	.L.str.13,@object               # @.str.13
.L.str.13:
	.asciz	"not supported"
	.size	.L.str.13, 14

	.type	.Lstr,@object                   # @str
.Lstr:
	.asciz	"Checking CPU features:"
	.size	.Lstr, 23

	.ident	"Ubuntu clang version 12.0.1-19ubuntu3"
	.section	".note.GNU-stack","",@progbits
	.addrsig
