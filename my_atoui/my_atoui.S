.global my_atoui

my_atoui:

mov $0, %rax

jump:

movzbq (%rdi), %rcx

test %rcx, %rcx
je fin

imul $10, %rax
sub $'0', %cl
add %rcx, %rax


add $1, %rdi

jmp jump


fin:
ret


