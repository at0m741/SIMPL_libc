section .text
global ft_memcpy_avx

; void* memcpy(void* dest, const void* src, size_t n);
ft_memcpy_avx:
    ; Arguments:
    ; dest: rdi
    ; src:  rsi
    ; n:    rdx

    push rbp                            ; save rbp
    mov rbp, rsp                        ; rbp = rsp
    push rsi                            ; save rsi
    push rdi                            ; save rdi
    push rbx                            ; save rbx

    mov rcx, rdx                        ; n

    cmp rcx, 32                         ; if n < 32 jump to copy_less_than_32_bytes
    jb copy_less_than_32_bytes          ; jump if n < 32

    mov rax, rcx                        ; rax = n
    shr rax, 5                          ; rax = n / 32
    mov rbx, rax                        ; rbx = n / 32

copy_32_bytes:
    vmovdqu ymm0, [rsi]                 ; load 32 bytes from src to ymm0
    vmovdqu [rdi], ymm0					; store 32 bytes from ymm0 to dest
    add rsi, 32
    add rdi, 32                         ; increment src and dest pointers by 32
    dec rbx
    jnz copy_32_bytes

    ; handle remaining bytes
    mov rcx, rdx
    and rcx, 31                         ; rcx = n % 32
    jz done

copy_less_than_32_bytes:
    rep movsb                           ; use ERMS for copying less than 32 bytes

done:
    pop rbx
    pop rdi
    pop rsi
    pop rbp
    vzeroupper
    ret
