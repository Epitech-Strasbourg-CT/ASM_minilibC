BITS 64

SECTION .text

GLOBAL my_memmove:function

my_memmove:

 PUSH RBP
 MOV RBP, RSP

 ; RDI => dest
 ; RSI => src
 ; RDX => size

 MOV RAX, RDI
 CMP RDI, RSI
 JL move_from_left

 ADD RDI, RDX
 ADD RSI, RDX
 SUB RDI, 1
 SUB RSI, 1
move_from_right:
 CMP RDX, 0
 JE end
 MOV R9B, [RSI]
 MOV [RDI], R9B
 DEC RSI
 DEC RDI
 DEC RDX
 JMP move_from_right

move_from_left:
 CMP RDX, 0
 JE end
 MOV R9B, [RSI]
 MOV [RDI], R9B
 INC RSI
 INC RDI
 DEC RDX
 JMP move_from_left

end:
 LEAVE
 RET
