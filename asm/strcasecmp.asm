BITS 64

SECTION .text

GLOBAL my_strcasecmp:function

my_strcasecmp:

 PUSH RBP
 MOV RBP, RSP

 XOR RCX, RCX
 XOR R8, R8
 XOR R9, R9
 XOR RAX, RAX
 JMP cmp_loop

cmp_loop:
	MOV R8B, [RDI+RCX]
	MOV R9B, [RSI+RCX]
	CMP R8B, 0
	JE end
	CMP R9B, 0
	JE end

		; lowering RDI
		CMP R8B, 65
		JL end_lower1
		CMP R8B, 90
		JG end_lower1
		ADD R8B, 32
		end_lower1:

		; lowering RSI
		CMP R9B, 65
		JL end_lower2
		CMP R9B, 90
		JG end_lower2
		ADD R9B, 32
		end_lower2:

	CMP R8B, R9B
    	JNE end
	INC RCX
	JMP cmp_loop

end:
 SUB R8, R9
 MOV RAX, R8
 LEAVE
 RET
