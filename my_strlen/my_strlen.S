.global my_strlen

my_strlen:

  mov $0, %rcx

  loop:
  cmpb $0, (%rdi)

  jle sort

  add $1, %rcx

  add $1, %rdi

  jmp loop

  sort:

  mov %rcx, %rax

  ret

