TITLE LE CARACTER
.MODEL SMALL
.DATA
MSG1 DB "Digite um caracter: $"
MSG2 DB 13, 10, "O caracter digitado foi: $"
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    ; Exibe a mensagem para o usuário
    MOV AH, 09h
    MOV DX, OFFSET MSG1
    INT 21h

    ; Lê um caracter do teclado
    MOV AH, 01h
    INT 21h

    ; Armazena o caracter lido
    MOV BL, AL

    ; Exibe a mensagem com o caracter lido
    MOV AH, 09h
    MOV DX, OFFSET MSG2
    INT 21h

    ; Exibe o caracter lido
    MOV DL, BL
    MOV AH, 02h
    INT 21h

    ; Finaliza o programa
    MOV AX, 4Ch
    INT 21h
MAIN ENDP
END MAIN
