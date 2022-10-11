global factimpASM
    section .text

factimpASM:
    xor rax,rax ; Se limpia el registro rax porque sirve para hacer las multiplicaciones y divisiones
    xor rdx,rdx
    ; tenemos el valor de N en rdi
    mov r8,rdi; movemos el valor de N a r8

    mov rax,2 ; movemos el 2 a RAX para hacer el MUL

    mul r8 ; RDX/RAX -> RAX*R8 -> 2*N

    add rax,1; inc rax -> RAX+1 -> 2*N + 1 

    mov r8,rax ; r8-> 2*N + 1

    mov r10,1; Contador
    xorps xmm0,xmm0; limpiamos el registro xmm0 por donde devolveremos el resultado
    xorps xmm1,xmm1
    xorps xmm2,xmm2

    cvtsi2ss xmm0,r10; xmmo<- 1 (Siempre tendra 1)
    cvtsi2ss xmm2,r10; xmm2<- 1  (Para hacer el producto)
    
bucle:

    cmp r10,r8
    je fin

    cvtsi2ss xmm1,r10 ;xmm1<- i
    addss xmm1,xmm0 ; xmm1<- i+1

    mulss xmm2,xmm1 ; xmm2<- xmm2+xmm1 <- result*=(i+1)

    add r10,1

    jmp bucle

fin:
    movss xmm0,xmm2
    ret

