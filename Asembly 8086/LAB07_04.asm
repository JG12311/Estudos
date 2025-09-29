TITLE VERIFICAÇÃO MAIOR OU MENOR
.MODEL SMALL
.STACK 100H
.DATA
    MSG1 DB 'Digite o primeiro numero (0-9): $'
    MSG2 DB 13,10,'Digite o segundo numero (0-9): $'
    MAIOR DB 13,10,' O maior numero e: $'
    MENOR DB 13,10,' O menor numero e: $'
    IGUAL DB 13,10,' Os numeros sao iguais$'
    NUM1 DB ?
    NUM2 DB ?
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX      ; Inicializa o segmento de dados
    MOV AH, 09H     ; Função para exibir string
    LEA DX, MSG1
    INT 21H
    MOV AH, 01H     ; Função para ler caractere do teclado  
    INT 21H
    AND AL, 0FH     ; Converte ASCII para valor numérico
    MOV NUM1, AL    ; Armazena o primeiro número
    MOV AH, 09H     ; Função para exibir string
    LEA DX, MSG2
    INT 21H
    MOV AH, 01H
    INT 21H
    AND AL, 0FH    ; Converte ASCII para valor numérico
    MOV NUM2, AL
    MOV AL, NUM1
    CMP AL, NUM2
    JG IMPRIME_MAIOR ; Se NUM1 > NUM2, pula para IMPRIME_MAIOR
    JL IMPRIME_MENOR ; Se NUM1 < NUM2, pula para IMPRIME_MENOR
    ; Se os números são iguais
    MOV AH, 09H    ; Função para exibir string
    LEA DX, IGUAL
    INT 21H
    JMP FIM
IMPRIME_MAIOR:
    MOV AH, 09H    ; Função para exibir string
    LEA DX, MAIOR
    INT 21H
    MOV AH, 02H
    MOV DL, NUM1
    ADD DL, 30h    ; Converte para caractere ASCII
    INT 21H
    MOV AH, 09H    ; Função para exibir string
    LEA DX, MENOR
    INT 21H
    MOV AH, 02H
    MOV DL, NUM2
    ADD DL, 30h    ; Converte para caractere ASCII
    INT 21H
    JMP FIM
IMPRIME_MENOR:
    MOV AH, 09H    ; Função para exibir string
    LEA DX, MAIOR
    INT 21H
    MOV AH, 02H
    MOV DL, NUM2
    ADD DL, 30h    ; Converte para caractere ASCII
    INT 21H
    MOV AH, 09H    ; Função para exibir string
    LEA DX, MENOR
    INT 21H
    MOV AH, 02H
    MOV DL, NUM1
    ADD DL, 30h    ; Converte para caractere ASCII
    INT 21H
    JMP FIM
FIM:
    MOV AX, 4C00H  ; Termina o programa
    INT 21H
MAIN ENDP
END MAIN