.globl print_string
print_string:
loop:
    movb (%rdi), %al    


    cmpb $0, %al
    je end

   
    movb %al, %sil


    call print_char


    addq $1, %rdi
    jmp loop

end:
    ret
