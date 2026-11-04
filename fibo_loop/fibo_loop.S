.global fibo_loop

fibo_loop:
    movl $0, %eax # a
    movl $0, %ecx # i
    movl $1, %ebx # b
    movl $0, %edx # temp
    # n est %edi

loop:
    cmpl %edi, %ecx

    jge end

    addl %ebx, %eax # a + b vont dans eax 
    movl %eax, %edx # on donne le resultat dans temp
    movl %ebx, %eax # on donne la valeur de b dans a 
    movl %edx, %ebx # on donne la valeur temp a b 
    addl $1, %ecx

    jmp loop


end:
ret



