section .text
global ft_strlen_sse_asm

ft_strlen_sse_asm:
    test rdi, rdi
    jz .return_zero

    mov rcx, rdi					; rcx = rdi
    mov rax, rdi					; rax = rdi  (rax is the return value of the function)
    and rcx, 15						; rcx = rdi & 31  (size_t align = (uintptr_t *)rdi & 31;)  (align = rdi over 32 bytes)
    jz .aligned						; if (align == 0) goto aligned

    vpxor xmm0, xmm0, xmm0			; xmm0 = 0 (zero out xmm0) (zero = _mm_setzero_si128();)
    vmovdqu xmm1, [rdi]				; xmm1 = *rdi (load 16 bytes from rdi to xmm1) (data = _mm_loadu_si128((__m128i *)ptr);) 
    vpcmpeqb xmm1, xmm0, xmm1		; xmm1 = _mm_cmpeq_epi8(data, zero); (compare data with zero)
    vpmovmskb eax, xmm1				; eax = _mm_movemask_epi8(data); (get the mask of the comparison)  yes, all of these bozos are the same as in my C code
    test eax, eax					; if (mask == 0) goto unaligned_next
    jz .unaligned_next
    bsf eax, eax					; eax = __builtin_ctz(mask); (get the index of the first set bit)
	ret

.unaligned_next:
    neg rcx
    lea rax, [rdi + rcx]
    add rax, 16

.aligned:
    prefetchnta [rax + 16]
    mov rcx, rax
    sub rcx, rdi
    add rcx, -16
    add rax, 16
    vpxor xmm0, xmm0, xmm0


.align_loop:
    prefetchnta [rax + 16]		; prefetch the next 32 bytes of memory in cache (non-temporal)
    vmovdqa xmm1, [rax - 16]
    vpcmpeqb xmm1, xmm0, xmm1
    vpmovmskb edx, xmm1
    add rcx, 16					; rcx += 32  (ptr - start) + (size_t)__builtin_ctz(mask)
    add rax, 16					; rax += 32  (ptr += 32)
    test edx, edx
    jz .align_loop
    bsf eax, edx
    add rax, rcx
    ret

.return_zero:
    xor eax, eax				; return 0 using xor because it's faster than mov
    ret

