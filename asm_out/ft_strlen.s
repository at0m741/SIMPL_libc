	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0
	.intel_syntax noprefix
	.globl	_ft_strlen                      ## -- Begin function ft_strlen
	.p2align	4, 0x90
_ft_strlen:                             ## @ft_strlen
	.cfi_startproc
## %bb.0:
	mov	rax, rdi
	mov	rcx, rdi
	and	rax, 31
	je	LBB0_5
## %bb.1:
	mov	ecx, 32
	sub	rcx, rax
	xor	eax, eax
	.p2align	4, 0x90
LBB0_2:                                 ## =>This Inner Loop Header: Depth=1
	cmp	byte ptr [rdi + rax], 0
	je	LBB0_8
## %bb.3:                               ##   in Loop: Header=BB0_2 Depth=1
	inc	rax
	cmp	rcx, rax
	jne	LBB0_2
## %bb.4:
	add	rcx, rdi
LBB0_5:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	rdx, rcx
	sub	rdx, rdi
	add	rdx, -32
	add	rcx, 32
	.p2align	4, 0x90
LBB0_6:                                 ## =>This Inner Loop Header: Depth=1
	vmovdqu	ymm0, ymmword ptr [rcx - 32]
	prefetcht0	byte ptr [rcx]
	add	rdx, 32
	add	rcx, 32
	vptest	ymm0, ymm0
	je	LBB0_6
## %bb.7:
	vpxor	xmm1, xmm1, xmm1
	vpcmpeqb	ymm0, ymm0, ymm1
	vpmovmskb	eax, ymm0
	rep		bsf	eax, eax
	add	rax, rdx
	pop	rbp
LBB0_8:
	vzeroupper
	ret
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
