.global endian_sum
endian_sum:
    mov $0, %eax      

loop:
    cmp $0, %rsi
    je end

    movbe (%rdi), %ecx
    add %ecx, %eax

    add $4, %rdi
    sub $1, %rsi
    jmp loop

end:
    ret

