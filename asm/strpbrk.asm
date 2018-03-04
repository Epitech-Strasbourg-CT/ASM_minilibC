BITS 64

SECTION .text

GLOBAL my_strpbrk:function

my_strpbrk:

 PUSH RBP
 MOV RBP, RSP

 XOR RAX, RAX
 XOR R8, R8

 CMP RDI, 0
 JE end

loop:
	CMP BYTE[RDI+R8], 0
	JE end

	XOR R9, R9
	accept_loop:
		MOV R10, [RSI+R9]
		CMP R10B, BYTE[RDI+R8]
		JNE end_check_char
		ADD RDI, R8
		MOV RAX, RDI
		JMP end
		end_check_char:
		CMP BYTE[RSI+R9], 0
		JE end_accept_loop
		INC R9
		JMP accept_loop
	end_accept_loop:

	INC R8
	JMP loop

end:
 LEAVE
 RET