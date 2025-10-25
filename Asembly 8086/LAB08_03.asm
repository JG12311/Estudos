.MODEL SMALL
.STACK 100h

.CODE
MAIN PROC
    XOR BX, BX          ; Zera BX para iniciar.

    MOV AH, 01h         ; Lê o primeiro caractere.
    INT 21h

LeituraHexLoop:
    CMP AL, 0Dh         ; Compara o caractere com a tecla Enter.
    JE FimLeituraHex    ; Se for Enter, finaliza.

    ; Converte o caractere para seu valor numérico (0-15)
    CMP AL, '9'         ; Verifica se é um número ('0'-'9').
    JBE IsDigit
    SUB AL, '7'         ; Se for letra ('A'-'F'), subtrai 55 (ASCII '7'). 'A'(65)-55=10.
    JMP Combine

IsDigit:
    SUB AL, '0'         ; Se for número, subtrai 48 (ASCII '0').

Combine:
    SHL BX, 4           ; Desloca BX 4 bits para a esquerda para abrir espaço.
    OR BL, AL           ; Insere o novo valor (0-15) nos 4 bits inferiores de BX.

    MOV AH, 01h         ; Lê o próximo caractere.
    INT 21h
    JMP LeituraHexLoop  ; Repete o loop.

FimLeituraHex:
    MOV AH, 4Ch         ; Termina o programa.
    INT 21h

MAIN ENDP
END MAIN