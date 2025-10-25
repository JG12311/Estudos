.MODEL SMALL
.STACK 100H

.DATA
    MATRIZ DB 16 DUP(?) ; Matriz 4x4 (16 bytes)
    SOMA DW ?           ; Variavel para a soma (Word, 16 bits)

    N_LINHAS EQU 4
    N_COLUNAS EQU 4

    ; Mensagens
    MSG_LER     DB 'Digite os 16 numeros da matriz (0-6):', 10, 13, '$'
    MSG_IMP     DB 10, 13, 'Matriz digitada:', 10, 13, '$'
    MSG_SOMA    DB 10, 13, 'Soma total dos elementos: $'
    QUEBRA_LN   DB 10, 13, '$'

.CODE
MAIN PROC
    ; Inicializa o segmento de dados (DS)
    MOV AX, @DATA
    MOV DS, AX

    ; 1. Chama o procedimento para ler a matriz
    CALL LER_MATRIZ

    ; 2. Chama o procedimento para imprimir a matriz lida
    CALL IMPRIMIR_MATRIZ

    ; 3. Chama o procedimento para somar os elementos
    CALL SOMAR_MATRIZ
    
    ; 4. Chama o procedimento para imprimir o resultado da soma
    CALL IMPRIMIR_SOMA

    ; Encerra o programa
    MOV AH, 4CH
    INT 21H
MAIN ENDP

; --- PROCEDIMENTO PARA LER A MATRIZ ---
; Le 16 caracteres (0-6) e armazena na matriz.
; Utiliza SI (offset linha) e BX (indice coluna).
LER_MATRIZ PROC
    ; Imprime a mensagem inicial
    LEA DX, MSG_LER
    MOV AH, 09H
    INT 21H

    MOV CX, N_LINHAS    ; CX = 4 (Loop externo - linhas)
    XOR SI, SI          ; Zera o offset da linha (SI = 0)

LER_LINHA:
    PUSH CX             ; Salva o contador de linhas
    MOV CX, N_COLUNAS   ; CX = 4 (Loop interno - colunas)
    XOR BX, BX          ; Zera o indice da coluna (BX = 0)

LER_COLUNA:
    ; Le um caractere
    MOV AH, 01H
    INT 21H
    
    ; Converte ASCII para numero (ex: '3' -> 3)
    SUB AL, '0'
    
    ; Armazena em MATRIZ[SI+BX]
    MOV MATRIZ[SI+BX], AL
    
    ; Imprime um espaco para formatar a entrada
    MOV DL, ' '
    MOV AH, 02H
    INT 21H
    
    INC BX
    LOOP LER_COLUNA

    ; Pula linha no console apos o usuario digitar 4 numeros
    LEA DX, QUEBRA_LN
    MOV AH, 09H
    INT 21H

    ADD SI, N_COLUNAS   ; Atualiza offset da linha (SI = SI + 4)
    POP CX              ; Restaura contador de linhas
    LOOP LER_LINHA
    
    RET
LER_MATRIZ ENDP

;  PROCEDIMENTO PARA IMPRIMIR A MATRIZ 
; Imprime a matriz formatada.

IMPRIMIR_MATRIZ PROC
    ; Imprime a mensagem "Matriz digitada:"
    LEA DX, MSG_IMP
    MOV AH, 09H
    INT 21H

    MOV CX, N_LINHAS    ; CX = 4 (Loop externo - linhas)
    XOR SI, SI          ; Zera o offset da linha

LOOP_IMP_LINHA:
    PUSH CX
    MOV CX, N_COLUNAS   ; CX = 4 (Loop interno - colunas)
    XOR BX, BX          ; Zera o indice da coluna

LOOP_IMP_COLUNA:
    ; Acessa o elemento MATRIZ[SI+BX]
    MOV DL, MATRIZ[SI+BX]
    
    ; Converte numero para ASCII
    ADD DL, '0'
    
    ; Imprime o caractere
    MOV AH, 02H
    INT 21H
    
    ; Imprime um espaco
    MOV DL, ' '
    MOV AH, 02H
    INT 21H
    
    INC BX
    LOOP LOOP_IMP_COLUNA

    ; Pula linha no console
    LEA DX, QUEBRA_LN
    MOV AH, 09H
    INT 21H

    ADD SI, N_COLUNAS   ; Proxima linha
    POP CX
    LOOP LOOP_IMP_LINHA

    RET
IMPRIMIR_MATRIZ ENDP

; PROCEDIMENTO PARA SOMAR OS ELEMENTOS 
; Soma todos os 16 elementos da matriz e guarda em SOMA.
SOMAR_MATRIZ PROC
    XOR DX, DX          ; Zera o acumulador da soma (DX)
    
    MOV CX, N_LINHAS    ; CX = 4 (Loop externo - linhas)
    XOR SI, SI          ; Zera o offset da linha

LOOP_SOMA_LINHA:
    PUSH CX
    MOV CX, N_COLUNAS   ; CX = 4 (Loop interno - colunas)
    XOR BX, BX          ; Zera o indice da coluna

LOOP_SOMA_COLUNA:
    XOR AX, AX          ; Limpa AX (registrador temporario)
    
    ; Pega o valor (byte) da matriz
    MOV AL, MATRIZ[SI+BX] 
    
    ; Adiciona o valor (byte em AX) ao acumulador (word em DX)
    ADD DX, AX
    
    INC BX
    LOOP LOOP_SOMA_COLUNA

    ADD SI, N_COLUNAS   ; Proxima linha
    POP CX
    LOOP LOOP_SOMA_LINHA
    
    ; Armazena o resultado final na variavel SOMA
    MOV SOMA, DX
    
    RET
SOMAR_MATRIZ ENDP

;  PROCEDIMENTO PARA IMPRIMIR A SOMA 
; Imprime o valor da variavel SOMA 
IMPRIMIR_SOMA PROC
    ; Imprime a mensagem "Soma total:"
    LEA DX, MSG_SOMA
    MOV AH, 09H
    INT 21H

    ; Pega o valor da soma 
    MOV AX, SOMA
    XOR DX, DX          ; Limpa DX para a divisao
    MOV BX, 10          ; Divisor
    
    ; Divide AX por 10.
   
    DIV BX
    
    ; Converte os digitos para ASCII
    ADD AX, '0'         ; Converte a dezena (AL)
    ADD DX, '0'         ; Converte a unidade (DL)

    ; Salva a unidade na pilha
    PUSH DX

    ; Imprime a dezena (se for diferente de '0')
    CMP AL, '0'
    JE PULA_DEZENA      ; Se for '0', nao imprime
    
    MOV DL, AL
    MOV AH, 02H
    INT 21H

PULA_DEZENA:
    ; Recupera e imprime a unidade
    POP DX
    MOV AH, 02H
    INT 21H

    RET
IMPRIMIR_SOMA ENDP

END MAIN