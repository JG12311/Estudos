Title Numero
.model small
.stack 100h
.data
    msg1 db "digite um caractere:$"
    sim  db 10,13,"O caractere digitado e um numero.$"
    nao  db 10,13,"O caractere digitado nao e um numero.$"

.code
main proc
    ;permite o acesso as variaveis definidadas em .data
    mov ax,@data
    mov ds,ax

    ;exibe na tela a string msg1 
    mov ah,09
    mov dx, offset msg1
    int 21h

    ; Lê um caractere do teclado e salva o caractere lido em AL 
    MOV AH,1 
    INT 21h 

    ; Copia o caractere lido para BL 
    MOV BL,AL 

    ;compara o caractere em BL com o valor 48 (código ASCII do caractere “0”)  
    CMP BL,48 

    ; Se o caractere em BL for menor que 48 (“0”), salta para o rótulo NAOENUMERO 
    JB NAOENUMERO 

    ; Compara o caractere em BL com o valor 57 (código ASCII do caractere “9”) 
    CMP BL,57 

    ; Se o caractere em BL for maior que 57 (“9”), salta para o rótulo NAOENUMERO 
    JA NAOENUMERO 

    ; Se chegou até aqui, exibe na tela dizendo que o caracter é um número 
    MOV AH,9 
    MOV DX,offset sim
    INT 21h 

    ; Salta para o rótulo FIM 
    JMP FIM 

    ;define o rotulo NAOENUMERO
    NAOENUMERO:
    ;Exibe na tela dizendo q nao é numero
    MOV AH,9 
    MOV DX,offset nao
    INT 21h 

    ; Define o rótulo FIM 
    FIM: 
    ; Finaliza o programa 
    MOV AH,4Ch 
    INT 21h 
main endp
end main
