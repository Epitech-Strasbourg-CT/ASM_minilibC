BITS 64

SECTION .text

GLOBAL read:function
EXTERN __errno_location

read:

 PUSH RBP
 MOV RBP, RSP

 XOR RAX, RAX
 call __errno_location wrt ..plt

 MOV R10, RAX

 MOV RAX, 0
 SYSCALL

 CMP RAX, 0
 JG end
 NEG RAX
 MOV [R10], RAX
 MOV RAX, -1


end:
 LEAVE
 RET
