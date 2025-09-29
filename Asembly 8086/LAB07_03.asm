TITLE VERIFICAÇÃO DE PAR OU IMPAR
.MODEL SMALL
.STACK 100H
.DATA
    MSG1    DB 'Digite o primeiro numero (0-9): $'
    MSG2    DB 13,10,'Digite o segundo numero (0-9): $'
    PAR1     DB 13,10,' O primeiro numero e PAR''$'
    IMPAR1   DB 13,10,' O primeiro numero e IMPAR''$'
    PAR2     DB 13,10,' O segundo numero e PAR''$'
    IMPAR2   DB 13,10,' O segundo numero e IMPAR''$'
    NUM1    DB ?
    NUM2    DB ?
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
    TEST NUM1, 01H  ; Testa se o bit menos significativo é 1 (ímpar)
    JZ IMPRIMEPAR1      ; Se zero, é par
    MOV AH, 09H    ; Função para exibir string
    LEA DX, IMPAR1
    INT 21H
    JMP TESTA2
IMPRIMEPAR1:
    MOV AH, 09H    ; Função para exibir string
    LEA DX, PAR1
    INT 21H
TESTA2:
    TEST NUM2, 01H  ; Testa se o bit menos significativo é 1 (ímpar)
    JZ IMPRIMEPAR2      ; Se zero, é par
    MOV AH, 09H    ; Função para exibir string
    LEA DX, IMPAR2
    INT 21H
    JMP FIM
IMPRIMEPAR2:
    MOV AH, 09H    ; Função para exibir string
    LEA DX, PAR2
    INT 21H
    FIM:
    MOV AH, 4CH    ; Função para encerrar o programa
    INT 21H
MAIN ENDP
END MAIN