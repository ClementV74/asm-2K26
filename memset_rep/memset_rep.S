.global memset_rep

memset_rep:

mov %rdi, %r8

mov %rdx, %rcx

mov %sil, %al

rep stosb

mov %r8, %rax
ret
