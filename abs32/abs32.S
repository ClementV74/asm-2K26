.text

.global abs32

abs32:
  mov %edi, %eax
  cmp $0, %eax
  jge end 
  neg %eax
  end:




ret
