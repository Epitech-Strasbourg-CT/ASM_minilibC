BITS 64

SECTION .text

GLOBAL memset:function

memset:

 PUSH RBP
 MOV RBP, RSP

 ; RDI => str
 ; RSI => value
 ; RDX => size

loop:
 CMP RDX, 0
 JE endloop
 MOV [RDI], RSI
 DEC RDX
 INC RDI
 JMP loop
endloop:

end:
 LEAVE
 RET
