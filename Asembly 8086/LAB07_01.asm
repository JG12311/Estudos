TITLE DIVISÃO DE INTEIROS
.MODEL SMALL
.STACK 100H
.DATA
    NUM1 DB ?
    NUM2 DB ?
    QUOCIENTE DB ?
    RESTO DB ?
    MSG1 DB 'Digite o dividendo  (0-9): $'
    MSG2 DB 13,10, 'Digite o divisor (1-9): $'
    MSG3 DB 13,10, 'Quociente: $'
    MSG4 DB 13,10, 'Resto: $'
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
    XOR CX,CX      ; Limpa o registrador CX (contador de quociente)
    XOR AH,AH      ; Limpa o registrador AH (resto)
    MOV CL,NUM2  ; Carrega o divisor em CL
    MOV AL,NUM1  ; Carrega o dividendo em AL   
    LOOP_DIV:
        CMP AL,CL      ; Compara AL (dividendo) com CL (divisor)
        JL FIM_DIV     ; Se AL < CL, termina a divisão
        SUB AL,CL      ; Subtrai CL de AL
        INC AH         ; Incrementa o contador de quociente
        JMP LOOP_DIV   ; Repete o processo

    FIM_DIV:
        OR AH,30H     ; Converte o quociente para ASCII
        OR AL,30H     ; Converte o resto para ASCII
        MOV QUOCIENTE,AH ; Armazena o quociente
        MOV RESTO,AL      ; Armazena o resto
        MOV AH, 09H     ; Função para exibir string
        LEA DX, MSG3
        INT 21H
        MOV AH,2
        MOV DL,QUOCIENTE
        INT 21H
        MOV AH, 09H     ; Função para exibir string
        LEA DX, MSG4
        INT 21H
        MOV AH,2
        MOV DL,RESTO
        INT 21H
    FIM:
        MOV AH, 4CH     ; Função para encerrar o programa
        INT 21H
MAIN ENDP
END MAIN