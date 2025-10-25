.MODEL SMALL
.STACK 100h
.DATA
    MSG1 DB "DIGITE UMA SEQUENCIA DE 0s E 1s, TERMINANDO COM ENTER:$"
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AH, 09h         ; Função do DOS para exibir string.
    LEA DX, MSG1        ; Carrega o endereço da mensagem em DX.
    INT 21h             ; Chama a interrupção do DOS para exibir a mensagem
   
    XOR BX, BX          ; Zera o registrador BX. É a forma mais eficiente.

    MOV AH, 01h         ; Função do DOS para ler um caractere do teclado.
    INT 21h             ; O caractere lido fica em AL.

LeituraLoop
    CMP AL, 0Dh         ; Compara o caractere lido com Carriage Return (Enter).
    JE FimLeitura       ; Se for igual (JE = Jump if Equal), finaliza o loop.

    AND AL, 0FH         ; AL agora contém 0 ou 1.

    SHL BX, 1           ; Multiplica o valor em BX por 2,1 casa pra esquerda
    ;    insere o novo bit na posição correta.
    OR BL, AL           ; Adiciona o novo bit (0 ou 1) ao byte baixo de BX.

    MOV AH, 01h         ; Prepara para ler o próximo caractere.
    INT 21h             ; Lê o caractere.
    JMP LeituraLoop     ; Volta para o início do loop para verificar o caractere.

FimLeitura:
    ; Finaliza o programa e retorna o controle ao sistema operacional.
    MOV AH, 4Ch
    INT 21h

MAIN ENDP
END MAIN