	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0
	.intel_syntax noprefix
	.globl	_ft_strncmp                     ## -- Begin function ft_strncmp
	.p2align	4, 0x90
_ft_strncmp:                            ## @ft_strncmp
	.cfi_startproc
## %bb.0:
	mov	eax, edi
	mov	rcx, rsi
	mov	r8, rdi
	and	eax, 31
	je	LBB0_8
## %bb.1:
	mov	ecx, 32
	sub	ecx, eax
	cmp	rcx, rdx
	cmovae	rcx, rdx
	test	rdx, rdx
	je	LBB0_7
## %bb.2:
	xor	r8d, r8d
	.p2align	4, 0x90
LBB0_4:                                 ## =>This Inner Loop Header: Depth=1
	movzx	eax, byte ptr [rdi + r8]
	movzx	r9d, byte ptr [rsi + r8]
	cmp	al, r9b
	jne	LBB0_5
## %bb.3:                               ##   in Loop: Header=BB0_4 Depth=1
	inc	r8
	cmp	rcx, r8
	jne	LBB0_4
LBB0_7:
	shl	rcx, 5
	lea	r8, [rdi + rcx]
	add	rcx, rsi
LBB0_8:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	rax, rdx
	and	rax, -32
	je	LBB0_15
## %bb.9:
	mov	r10d, 32
	xor	r9d, r9d
	.p2align	4, 0x90
LBB0_10:                                ## =>This Inner Loop Header: Depth=1
	vmovdqu	ymm0, ymmword ptr [r8 + r10 - 32]
	vpcmpeqb	ymm0, ymm0, ymmword ptr [rcx + r10 - 32]
	vpmovmskb	r11d, ymm0
	cmp	r11d, -1
	jne	LBB0_13
## %bb.11:                              ##   in Loop: Header=BB0_10 Depth=1
	vmovdqu	ymm0, ymmword ptr [r8 + r10]
	vpcmpeqb	ymm0, ymm0, ymmword ptr [rcx + r10]
	vpmovmskb	r11d, ymm0
	cmp	r11d, -1
	jne	LBB0_12
## %bb.14:                              ##   in Loop: Header=BB0_10 Depth=1
	add	r9, 2
	add	r10, 64
	cmp	rax, r9
	jne	LBB0_10
LBB0_15:
	and	edx, 31
	je	LBB0_20
## %bb.16:
	shl	rax, 5
	add	r8, rax
	add	rcx, rax
	xor	esi, esi
	.p2align	4, 0x90
LBB0_18:                                ## =>This Inner Loop Header: Depth=1
	movzx	eax, byte ptr [r8 + rsi]
	movzx	edi, byte ptr [rcx + rsi]
	cmp	al, dil
	jne	LBB0_19
## %bb.17:                              ##   in Loop: Header=BB0_18 Depth=1
	inc	rsi
	cmp	rdx, rsi
	jne	LBB0_18
LBB0_20:
	## InlineAsm Start
	## InlineAsm End
	xor	eax, eax
	pop	rbp
	vzeroupper
	ret
LBB0_5:
	sub	eax, r9d
	ret
LBB0_12:
	inc	r9
LBB0_13:
	shl	r9, 5
	not	r11d
	rep		bsf	ecx, r11d
	or	rcx, r9
	movzx	eax, byte ptr [rdi + rcx]
	movzx	ecx, byte ptr [rsi + rcx]
	sub	eax, ecx
	pop	rbp
	vzeroupper
	ret
LBB0_19:
	sub	eax, edi
	pop	rbp
	vzeroupper
	ret
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
