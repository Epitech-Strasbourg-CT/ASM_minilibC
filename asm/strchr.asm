BITS 64

SECTION .text

GLOBAL strchr:function

strchr:

 PUSH RBP
 MOV RBP, RSP

 XOR RCX, RCX
 XOR RAX, RAX

loop:
	MOV R8B, [RDI+RCX]
	CMP R8B, SIL
	JE save_addr
	CMP R8B, 0
	JE end
	INC RCX
	JMP loop

save_addr:
 ADD RDI, RCX
 MOV RAX, RDI

end:
 LEAVE
 RET