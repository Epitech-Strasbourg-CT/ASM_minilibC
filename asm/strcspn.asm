BITS 64

SECTION .text

GLOBAL my_strcspn:function

my_strcspn:

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
	MOV R11, 1
	accept_loop:
		CMP BYTE[RSI+R9], 0
        	JE end_accept_loop

		MOV R10, [RSI+R9]
		CMP R10B, BYTE[RDI+R8]
		MOV R11, 0
		end_check_char:

		INC R9
		JMP accept_loop
	end_accept_loop:
	ADD RAX, R11
	INC R8
	JMP loop

end:
 LEAVE
 RET