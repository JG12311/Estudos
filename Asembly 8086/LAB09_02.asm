.MODEL SMALL
.STACK 100H

.DATA
    ; Matriz 4x4 conforme definida na atividade 
    MATRIZ4X4 DB 1, 2, 3, 4
              DB 4, 3, 2, 1
              DB 5, 6, 7, 8
              DB 8, 7, 6, 5
              
    N_LINHAS EQU 4      ; Constante para numero de linhas
    N_COLUNAS EQU 4     ; Constante para numero de colunas

    QUEBRA_LN DB 10, 13, '$' ; CR/LF para pular linha

.CODE
MAIN PROC
    ; Inicializa o segmento de dados (DS)
    MOV AX, @DATA
    MOV DS, AX

    ; Chama o procedimento para imprimir a matriz
    CALL IMPRIMIR_MATRIZ

    ; Encerra o programa
    MOV AH, 4CH
    INT 21H
MAIN ENDP

; --- PROCEDIMENTO PARA IMPRIMIR A MATRIZ ---
; Imprime a MATRIZ4X4 formatada em linhas e colunas.
; Utiliza SI como offset da linha e BX como indice da coluna.
IMPRIMIR_MATRIZ PROC
    MOV CX, N_LINHAS    ; CX = 4 (Contador do loop externo - linhas)
    XOR SI, SI          ; Zera o offset da linha (SI = 0)

LOOP_LINHA:
    PUSH CX             ; Salva o contador de linhas (CX) na pilha
    
    MOV CX, N_COLUNAS   ; CX = 4 (Contador do loop interno - colunas)
    XOR BX, BX          ; Zera o indice da coluna (BX = 0)

LOOP_COLUNA:
    ; Acessa o elemento: MATRIZ4X4[SI + BX]
    MOV DL, MATRIZ4X4[SI+BX]
    
    ; Converte o numero (0-9) para caractere ASCII
    ADD DL, '0'
    
    ; Imprime o caractere
    MOV AH, 02H
    INT 21H
    
    ; Imprime um espaco para separar os numeros
    MOV DL, ' '
    MOV AH, 02H
    INT 21H
    
    INC BX              ; Proxima coluna (BX++)
    LOOP LOOP_COLUNA    ; Repete para as 4 colunas

    ; Acabou uma linha, imprime uma quebra de linha
    LEA DX, QUEBRA_LN
    MOV AH, 09H
    INT 21H

    ADD SI, N_COLUNAS   ; Atualiza o offset da linha (SI = SI + 4)
                        ; (Pula para o inicio da proxima linha)
    
    POP CX              ; Restaura o contador de linhas (CX) da pilha
    LOOP LOOP_LINHA     ; Repete para as 4 linhas

    RET
IMPRIMIR_MATRIZ ENDP

END MAIN