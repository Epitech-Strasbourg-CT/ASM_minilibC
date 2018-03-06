BITS 64

SECTION .text

GLOBAL my_strcspn:function

my_strcspn:

 PUSH RBP
 MOV RBP, RSP

 XOR RAX, RAX

loop:
	CMP BYTE[RDI+RAX], 0
	JE end
	MOV R8B, BYTE[RDI+RAX]
	XOR R9, R9
	search_loop:
		CMP BYTE[RSI+R9], 0
		JE end_search_loop
		CMP BYTE[RSI+R9], R8B
		JE end
		INC R9
		JMP search_loop
	end_search_loop:
	INC RAX
	JMP loop

end:
 LEAVE
 RET
