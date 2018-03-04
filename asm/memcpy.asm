BITS 64

SECTION .text

GLOBAL my_memcpy:function

my_memcpy:

 PUSH RBP
 MOV RBP, RSP

 ; RDI => dest
 ; RSI => src
 ; RDX => size

loop:
 CMP RDX, 0
 JE endloop
 MOV R8, [RSI]
 MOV [RDI], R8
 DEC RDX
 INC RDI
 INC RSI
 JMP loop
endloop:

end:
 LEAVE
 RET
