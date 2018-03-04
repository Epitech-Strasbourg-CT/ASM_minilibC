BITS 64

SECTION .text

GLOBAL my_strlen:function

my_strlen:

 PUSH RBP
 MOV RBP, RSP

 XOR RAX, RAX

loop:
	CMP BYTE[RDI+RAX], 0
	JE end
	INC RAX
	JMP loop

end:
 LEAVE
 RET