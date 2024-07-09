	.text
	.intel_syntax noprefix
	.file	"ft_strlen_v2.c"
	.globl	strlen_avx2                     # -- Begin function strlen_avx2
	.p2align	4, 0x90
	.type	strlen_avx2,@function
strlen_avx2:                            # @strlen_avx2
	.cfi_startproc
# %bb.0:
	test	rdi, rdi
	je	.LBB0_1
# %bb.2:
	prefetchnta	byte ptr [rdi]
	prefetchnta	byte ptr [rdi + 4096]
	prefetchnta	byte ptr [rdi + 8192]
	prefetchnta	byte ptr [rdi + 12288]
	mov	rcx, rdi
	test	dil, 31
	je	.LBB0_5
# %bb.3:
	cmp	byte ptr [rdi], 0
	je	.LBB0_4
# %bb.10:
	lea	rcx, [rdi + 1]
	mov	rax, rdi
	.p2align	4, 0x90
.LBB0_11:                               # =>This Inner Loop Header: Depth=1
	lea	edx, [rax + 1]
	test	dl, 31
	je	.LBB0_5
# %bb.8:                                #   in Loop: Header=BB0_11 Depth=1
	add	rax, 1
	cmp	byte ptr [rcx], 0
	lea	rcx, [rcx + 1]
	jne	.LBB0_11
# %bb.9:
	sub	rax, rdi
	ret
.LBB0_5:
	vpxor	xmm0, xmm0, xmm0
	vpcmpeqb	ymm1, ymm0, ymmword ptr [rcx]
	vpmovmskb	eax, ymm1
	test	eax, eax
	je	.LBB0_6
# %bb.18:
	sub	rcx, rdi
	bsf	eax, eax
	add	rax, rcx
.LBB0_19:
	vzeroupper
	ret
.LBB0_4:
	mov	rax, rdi
	sub	rax, rdi
	ret
.LBB0_6:
	vpcmpeqb	ymm0, ymm0, ymmword ptr [rcx + 32]
	vpmovmskb	eax, ymm0
	test	eax, eax
	je	.LBB0_12
# %bb.7:
	mov	rdx, rcx
.LBB0_17:
	sub	rdx, rdi
	add	rdx, 32
	mov	rax, rdx
	vzeroupper
	ret
.LBB0_12:
	mov	rax, rcx
	sub	rax, rdi
	add	rax, 96
	vpxor	xmm0, xmm0, xmm0
	.p2align	4, 0x90
.LBB0_13:                               # =>This Inner Loop Header: Depth=1
	vpcmpeqb	ymm1, ymm0, ymmword ptr [rcx + 64]
	vpmovmskb	edx, ymm1
	test	edx, edx
	jne	.LBB0_14
# %bb.15:                               #   in Loop: Header=BB0_13 Depth=1
	vpcmpeqb	ymm1, ymm0, ymmword ptr [rcx + 96]
	vpmovmskb	edx, ymm1
	test	edx, edx
	jne	.LBB0_19
# %bb.16:                               #   in Loop: Header=BB0_13 Depth=1
	lea	rdx, [rcx + 32]
	prefetchnta	byte ptr [rdx]
	prefetchnta	byte ptr [rcx + 4128]
	prefetchnta	byte ptr [rcx + 8224]
	prefetchnta	byte ptr [rcx + 12320]
	vpcmpeqb	ymm1, ymm0, ymmword ptr [rcx + 64]
	vpmovmskb	esi, ymm1
	add	rax, 32
	mov	rcx, rdx
	test	esi, esi
	je	.LBB0_13
	jmp	.LBB0_17
.LBB0_14:
	add	rax, -32
	vzeroupper
	ret
.LBB0_1:
	xor	eax, eax
	ret
.Lfunc_end0:
	.size	strlen_avx2, .Lfunc_end0-strlen_avx2
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 12.0.1-19ubuntu3"
	.section	".note.GNU-stack","",@progbits
	.addrsig
