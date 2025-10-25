.MODEL SMALL
.STACK 100H

.DATA
    ; Define o vetor de 7 posicoes 
    VETOR DB 7 DUP(?)
    TAMANHO EQU 7       ; Constante para o tamanho do vetor

    ; Mensagens para interacao com o usuario
    MSG_LER   DB 'Digite 7 numeros (0-9): $'
    MSG_IMP   DB 10, 13, 'Vetor invertido: $'
    QUEBRA_LN DB 10, 13, '$'

.CODE
MAIN PROC
    ; Inicializa o segmento de dados (DS)
    MOV AX, @DATA
    MOV DS, AX

    ; 1. Chama o procedimento para ler o vetor 
    CALL LER_VETOR

    ; 2. Chama o procedimento para inverter o vetor 
    CALL INVERTER_VETOR

    ; 3. Chama o procedimento para imprimir o vetor 
    CALL IMPRIMIR_VETOR

    ; Encerra o programa
    MOV AH, 4CH
    INT 21H
MAIN ENDP

; --- PROCEDIMENTO PARA LER O VETOR ---
; Le 7 caracteres (numeros de 0-9) do teclado e armazena em VETOR.
; Utiliza SI (Enderecamento Indexado) 
LER_VETOR PROC
    ; Imprime a mensagem "Digite 7 numeros:"
    LEA DX, MSG_LER
    MOV AH, 09H
    INT 21H

    XOR SI, SI      ; Zera o indice (SI) 
    MOV CX, TAMANHO ; Define o contador do loop (CX = 7)

LER_LOOP:
    ; Le um caractere do teclado (INT 21H / AH=01H)
    MOV AH, 01H
    INT 21H
    
    ; O caractere ASCII esta em AL. Convertemos para numero (ex: '1' (31h) -> 1)
    SUB AL, '0'     ; SUB AL, 30H
    
    ; Armazena o numero no vetor na posicao [SI] 
    MOV VETOR[SI], AL
    
    INC SI          ; Incrementa o indice (SI)
    LOOP LER_LOOP

    RET
LER_VETOR ENDP

;  PROCEDIMENTO PARA INVERTER O VETOR 
; Inverte os elementos do vetor sem usar um vetor auxiliar.
; Utiliza SI como indice inicial e DI como indice final.
INVERTER_VETOR PROC
    LEA SI, VETOR   ; SI aponta para o inicio do VETOR (elemento 0) 
    LEA DI, VETOR   ; DI tambem aponta para o inicio
    ADD DI, TAMANHO ; DI agora aponta para o final do vetor
    DEC DI          ; DI aponta para o ultimo elemento (posicao 6)

    ; O loop deve rodar TAMANHO / 2 vezes. (7 / 2 = 3)
    MOV CX, TAMANHO
    SHR CX, 1       ; Desloca 1 bit para a direita (CX = CX / 2)

INVERTE_LOOP:
    ; Troca (swap) os elementos VETOR[SI] e VETOR[DI]
    MOV AL, [SI]    ; Pega o elemento do inicio
    MOV AH, [DI]    ; Pega o elemento do fim
    
    MOV [SI], AH    ; Coloca o elemento do fim no inicio
    MOV [DI], AL    ; Coloca o elemento do inicio no fim
    
    INC SI          ; Avanca o indice do inicio
    DEC DI          ; Recua o indice do fim
    
    LOOP INVERTE_LOOP

    RET
INVERTER_VETOR ENDP

; --- PROCEDIMENTO PARA IMPRIMIR O VETOR ---
; Imprime os 7 elementos do vetor na tela.
; Utiliza BX (Enderecamento por Base) [cite: 11, 34]
IMPRIMIR_VETOR PROC
    ; Imprime a mensagem "Vetor invertido:"
    LEA DX, MSG_IMP
    MOV AH, 09H
    INT 21H

    XOR BX, BX      ; Zera o indice (BX) 
    MOV CX, TAMANHO ; Define o contador do loop (CX = 7)

IMPRIMIR_LOOP:
    ; Pega o elemento do vetor na posicao [BX] 
    MOV DL, VETOR[BX]
    
    ; Converte o numero para caractere ASCII (ex: 1 -> '1' (31h))
    ADD DL, '0'     ; ADD DL, 30H
    
    ; Imprime o caractere (INT 21H / AH=02H)
    MOV AH, 02H
    INT 21H
    
    INC BX          ; Incrementa o indice (BX)
    LOOP IMPRIMIR_LOOP

    RET
IMPRIMIR_VETOR ENDP

END MAIN