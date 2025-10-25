.MODEL SMALL
.STACK 100h

.CODE
MAIN PROC
    MOV BX, 0ABCDh      ; Coloque o número a ser impresso em BX.
    MOV CX, 4           ; Inicia o contador para 4 dígitos hexadecimais.

PrintHexLoop:
    ROL BX, 4           ; Rotaciona os 4 bits da esquerda para a direita.
    
    MOV DL, BL          ; Copia o byte para DL para trabalhar com ele.
    AND DL, 0Fh         ; Isola apenas os 4 bits que nos interessam (0-15).

    ; Converte o valor numérico (0-15) para caractere ASCII
    CMP DL, 9           ; Verifica se o valor é menor que 10.
    JBE IsDigitPrint
    ADD DL, '7'         ; Se for 10-15, soma 55 para virar 'A'-'F'. 10+55=65 ('A').
    JMP PrintChar

IsDigitPrint:
    ADD DL, '0'         ; Se for 0-9, soma 48 para virar '0'-'9'.

PrintChar:
    MOV AH, 02h         ; Função do DOS para exibir o caractere em DL.
    INT 21h

    LOOP PrintHexLoop   ; Repete o processo 4 vezes.

    MOV AH, 4Ch         ; Termina o programa.
    INT 21h

MAIN ENDP
END MAIN