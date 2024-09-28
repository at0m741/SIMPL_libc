section .text
global ft_strlen_avx_asm
%define PAGE_SIZE 4096
%define VEC_SIZE 32

ft_strlen_avx_asm:

    test        rdi, rdi
    je          return_zero

    mov         rsi, rdi
    mov         rax, rdi
    and         eax, VEC_SIZE - 1
    jz          aligned_start     ; If aligned, skip to aligned start

    mov         ecx, VEC_SIZE
    sub         ecx, eax
    prefetcht0  [rdi + PAGE_SIZE]
    vpxor       xmm0, xmm0, xmm0
    vmovdqu     xmm1, [rdi]
    vpcmpeqb    xmm1, xmm1, xmm0
    pmovmskb    edx, xmm1
    test        edx, edx
    jne         found_null_unaligned   ; If a null byte is found, handle it

    add         rdi, rcx
    vzeroupper
    jmp         aligned_start      ; Go to aligned handling

aligned_start:
    vpxor       ymm0, ymm0, ymm0   ; Clear the ymm register for aligned operations

aligned_loop:
    prefetcht0  [rdi + PAGE_SIZE]
    vmovdqa     ymm1, [rdi]
    vpcmpeqb    ymm1, ymm1, ymm0
    vpmovmskb   edx, ymm1
    test        edx, edx
    jne         found_null_aligned

    add         rdi, VEC_SIZE
    jmp         aligned_loop

found_null_unaligned:
    bsf         eax, edx
    sub         rdi, rsi
    add         rax, rdi
    vzeroupper
    ret

found_null_aligned:
    bsf         eax, edx           ; Find the first zero byte
    sub         rdi, rsi           ; Calculate bytes processed
    add         rax, rdi           ; Total bytes processed + offset to null byte
    vzeroupper
    ret

return_zero:
    xor         eax, eax           ; Return 0
    vzeroupper
    ret
