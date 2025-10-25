.MODEL SMALL
.STACK 100h

.CODE
MAIN PROC
    MOV CX, 16          ; Inicia o contador para 16 bits.

PrintLoop:
    ROR BX, 1           ; Rotaciona o bit da esquerda (MSB)

    JC UM         ; Se o Carry Flag for 1, o bit era '1', então pula.

    MOV DL, '0'         ; Se não, o bit era '0'. Prepara '0' para impressão.
    JMP imprimi     ; Pula para a rotina de impressão.

UM:
    MOV DL, '1'         ; Prepara o caractere '1' para impressão.

imprimi:
    MOV AH, 02h         ; Função do DOS para exibir o caractere em DL.
    INT 21h

    LOOP PrintLoop      ; Repete o processo para os 16 bits.

    MOV AH, 4Ch         ; Termina o programa.
    INT 21h

MAIN ENDP
END MAIN