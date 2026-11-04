
.text

.global facto_rec

facto_rec:
  cmp $1, %dil
  jle end
  movzbq %dil, %rdi
  push %rdi
  dec %dil
  call facto_rec
  pop %rdi

  imul %rdi, %rax
  ret
  end:
    mov $1, %rax
    ret

