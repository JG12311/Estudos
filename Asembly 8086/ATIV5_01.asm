TITLE Lab05_01 - Comando For 
.MODEL SMALL
.STACK 100h

.DATA
    msg_parte1 DB 'Parte 1: Exibindo 50 asteriscos na mesma linha...', 13, 10, '$'
    msg_parte2 DB 13, 10, 'Parte 2: Exibindo 50 asteriscos, um por linha...', 13, 10, '$'

.CODE
main PROC
    MOV AX, @data
    MOV DS, AX

    ; Parte 1: Mesma Linha
    MOV AH, 9
    LEA DX, msg_parte1
    INT 21h

    MOV CX, 50
loop_1linha:
    MOV AH, 2
    MOV DL, '*'
    INT 21h
    
    DEC CX              ; Decrementa o contador CX
    JNZ loop_1linha     ; Salta para 'loop_1linha' se CX for diferente de zero

    ; Parte 2: Linhas Separadas
    MOV AH, 9
    LEA DX, msg_parte2
    INT 21h

    MOV CX, 50
loop_1cadalinha:
    MOV AH, 2
    MOV DL, '*'
    INT 21h

    MOV DL, 13
    INT 21h
    MOV DL, 10
    INT 21h

    DEC CX              ; Decrementa o contador CX
    JNZ loop_1cadalinha ; Salta para 'loop_1cadalinha' se CX for diferente de zero

    MOV AH, 4Ch
    INT 21h
main ENDP
END main