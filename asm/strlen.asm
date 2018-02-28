BITS 64

SECTION .text

GLOBAL my_strlen

my_strlen:

 PUSH RBP		; Prologue
 MOV RBP, RSP		; Stack frame setup

 XOR RAX, RAX

loop:
	CMP BYTE[RDI+RAX], 0
	JE end
	INC RAX
	JMP loop

end:
 LEAVE			; Epilogue
 RET			; Return