.text

.global my_mul

my_mul:
  mov %rdi, %rax
  imul %rsi, %rax
  ret
