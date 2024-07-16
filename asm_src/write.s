section .text
    global write

write:
    mov rax, 1
    syscall
    jc error
    ret

error:
    mov rax, -1
    ret

