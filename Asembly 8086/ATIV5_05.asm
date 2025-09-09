TITLE Lab05_05 - Somatoria de 5 Numeros
.MODEL SMALL
.STACK 100h

.DATA
    msg_prompt    DB 'Digite um numero (de 0 a 9): $'
    msg_resultado DB 13, 10, 'A somatoria e: $'

.CODE
main PROC
    MOV AX, @data
    MOV DS, AX

    MOV CX, 5
    XOR BX, BX

loop_leitura:
    MOV AH, 9
    LEA DX, msg_prompt
    INT 21h

    MOV AH, 1
    INT 21h

    SUB AL, '0'
    ADD BL, AL

    MOV AH, 2
    MOV DL, 13
    INT 21h
    MOV DL, 10
    INT 21h

    LOOP loop_leitura

    ; Exibe o resultado
    MOV AH, 9
    LEA DX, msg_resultado
    INT 21h

    ADD BL, '0'
    MOV AH, 2
    MOV DL, BL
    INT 21h

    ; Finalização do Programa
    MOV AH, 4Ch
    INT 21h
main ENDP
END main