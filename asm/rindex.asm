BITS 64

SECTION .text

GLOBAL rindex:function

rindex:

 PUSH RBP
 MOV RBP, RSP

 XOR RAX, RAX

loop:
	CMP BYTE[RDI], SIL
	JNE end_store
	MOV RAX, RDI
	end_store:
	CMP BYTE[RDI], 0
	JE end
	INC RDI
	JMP loop

end:
 LEAVE
 RET