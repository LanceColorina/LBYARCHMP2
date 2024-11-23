section .text
bits 64
default rel
global DAXPY
DAXPY:
    ; a = xmm0
    ; x = xmm1
    ; y = xmm2
    ; return to xmm0
    MULSD xmm0, xmm1
    ADDSD xmm0, xmm2
    ;write your code here
    xor rax, rax
    ret