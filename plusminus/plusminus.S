.global plusminus

plusminus:
  
movq %rdi, %rax
addq %rsi, %rax
subq %rdx, %rax

ret

