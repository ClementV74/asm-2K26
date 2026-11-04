.global sys_hello

.section .text

sys_hello:


  mov $1, %rax

  mov $1, %rdi

  lea msg (%rip), %rsi

  mov $14, %rdx


  syscall 
  ret


  msg:
    .ascii "Hello World !\n"
