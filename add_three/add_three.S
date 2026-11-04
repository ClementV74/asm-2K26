
.text

.global add_three

add_three:

  mov %rdi, %rax
  add %rsi, %rax
  add %rdx, %rax
  ret
