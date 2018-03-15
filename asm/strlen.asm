BITS 64

SECTION .text

GLOBAL strlen:function

strlen:

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