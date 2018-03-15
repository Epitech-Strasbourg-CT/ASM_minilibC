BITS 64

SECTION .text

GLOBAL memcpy:function

memcpy:

 PUSH RBP
 MOV RBP, RSP

 ; RDI => dest
 ; RSI => src
 ; RDX => size

loop:
 CMP RDX, 0
 JE endloop
 MOV R8B, BYTE[RSI]
 MOV BYTE[RDI], R8B
 DEC RDX
 INC RDI
 INC RSI
 JMP loop
endloop:

end:
 LEAVE
 RET
