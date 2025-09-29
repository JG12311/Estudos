TITLE MULTIPLICAÇÃO DE INTEIROS
.MODEL SMALL
.STACK 100H
.DATA
    NUM1 DB ?
    NUM2 DB ?
    PRODUTO DB ?
    MSG1 DB 'Digite o multiplicador (0-9): $'
    MSG2 DB 13,10, 'Digite o multiplicando (0-9): $'
    MSG3 DB 13,10, 'Produto: $'
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
    MOV NUM2, AL    ; Armazena o segundo número
    XOR CX,CX      ; Limpa o registrador CX (contador)
    MOV AL,NUM1  ; Carrega o multiplicador em AL
    MOV CL,NUM2  ; Carrega o multiplicando em CL (parte baixa de CX)
    XOR BL,BL    ; Limpa o registrador BL (produto)
    LOOP_MUL:
        ADD BL,AL      ; Adiciona AL ao produto em BL
        LOOP LOOP_MUL  ; Decrementa CX e repete se não for zero
    OR BL,30H     ; Converte o produto para ASCII
    MOV PRODUTO,BL ; Armazena o produto
    MOV AH, 09H     ; Função para exibir string
    LEA DX, MSG3
    INT 21H
    MOV AH, 02H
    MOV DL,PRODUTO ; Carrega o produto em DL
    INT 21H
    FIM:
        MOV AH, 4CH     ; Função para encerrar o programa
        INT 21H
     MAIN ENDP
END MAIN    