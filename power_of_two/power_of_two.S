.text

.global power_of_two

power_of_two:
  mov %dil, %cl
  mov $1, %rax
  sal %cl, %rax
  ret
