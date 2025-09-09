TITLE Lab05_03 - Alfabeto Completo
.MODEL SMALL
.STACK 100h

.DATA
    msg_maiusculas DB 'Letras Maiusculas: ', 13, 10, '$'
    msg_minusculas DB 13, 10, 'Letras Minusculas: ', 13, 10, '$'

.CODE
main PROC
    MOV AX, @data
    MOV DS, AX

    ; Imprime as letras maiúsculas
    MOV AH, 9
    LEA DX, msg_maiusculas
    INT 21h

    MOV CX, 26
    MOV AL, 'A'
loop_maiusculas:
    MOV AH, 2
    MOV DL, AL
    INT 21h
    INC AL
    LOOP loop_maiusculas

    ; Imprime as letras minúsculas
    MOV AH, 9
    LEA DX, msg_minusculas
    INT 21h

    MOV CX, 26
    MOV AL, 'a'
loop_minusculas:
    MOV AH, 2
    MOV DL, AL
    INT 21h
    INC AL
    LOOP loop_minusculas

    ; Finalização do Programa
    MOV AH, 4Ch
    INT 21h
main ENDP
END main