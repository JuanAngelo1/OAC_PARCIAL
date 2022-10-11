global powerimpASM
    section .text


;recibo dos int

; x-> RDI
; N-> RSI
powerimpASM:

    xorps xmm0,xmm0
    xorps xmm1,xmm1
    xorps xmm2,xmm2
    xorps xmm3,xmm3

    xor rax,rax
    xor rdx,rdx

    mov r8,rsi 
    mov r12,r8
    mov rax,2
    mul r8
    inc rax
    mov r8,rax ; r8<- 2*N+1

    mov r9,1
    mov r10,0
    mov r11,rdi

    cvtsi2ss xmm0,r9; xmm0<- 1 (Result)
    cvtsi2ss xmm1,r10; contador xmm1
    cvtsi2ss xmm2,r11; Paso el valor de x a xmm2
    cvtsi2ss xmm3,r9; 

compar_par:
    mov r13,2
    mov rax,r12
    div r13

    cmp rdx,0
    je bucle

    mov r13,-1
    cvtsi2ss xmm3,r13


bucle:
    cmp r10,r8
    je fin

    mulss xmm0,xmm2

    inc r10

    jmp bucle

fin:
    mulss xmm0,xmm3
    ret 
