.text

.global clamp

clamp:
  mov %rdi, %rax

  cmp %rsi, %rax
  cmovg %rsi, %rax

  cmp %rdx, %rax
  cmovl %rdx, %rax


  ret
