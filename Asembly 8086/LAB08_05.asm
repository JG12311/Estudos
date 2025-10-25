.MODEL SMALL
.STACK 100h

.DATA
    ; Strings para o menu e prompts
    menu_in_msg     DB '--- MENU DE ENTRADA ---', 0Dh, 0Ah
                    DB '1. Ler Numero Binario', 0Dh, 0Ah
                    DB '2. Ler Numero Hexadecimal', 0Dh, 0Ah
                    DB 'Escolha a entrada: $'
    
    menu_out_msg    DB 0Dh, 0Ah, '--- MENU DE SAIDA ---', 0Dh, 0Ah
                    DB '1. Imprimir em Binario', 0Dh, 0Ah
                    DB '2. Imprimir em Hexadecimal', 0Dh, 0Ah
                    DB 'Escolha a saida: $'
    
    prompt_msg      DB 0Dh, 0Ah, 'Digite o numero e pressione Enter: $'
    result_msg      DB 0Dh, 0Ah, 'Resultado: $'

.CODE

; --- PROCEDIMENTO PRINCIPAL (MENU) ---
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; --- Menu de Entrada ---
    LEA DX, menu_in_msg
    MOV AH, 09h         ; Função para imprimir string.
    INT 21h

    MOV AH, 01h         ; Lê a escolha do usuário.
    INT 21h
    
    LEA DX, prompt_msg
    MOV AH, 09h
    INT 21h

    CMP AL, '1'
    JE  EntradaBinaria
    CALL ReadHex        ; Se não for '1', assume '2' e chama a leitura Hex.
    JMP MenuSaida

EntradaBinaria:
    CALL ReadBinary     ; Chama a leitura Binária.

MenuSaida:
    ; --- Menu de Saida ---
    LEA DX, menu_out_msg
    MOV AH, 09h
    INT 21h

    MOV AH, 01h         ; Lê a escolha do usuário.
    INT 21h

    LEA DX, result_msg
    MOV AH, 09h
    INT 21h
    
    CMP AL, '1'
    JE SaidaBinaria
    CALL PrintHex       ; Se não for '1', assume '2' e chama a impressão Hex.
    JMP FimPrograma

SaidaBinaria:
    CALL PrintBinary    ; Chama a impressão Binária.

FimPrograma:
    MOV AH, 4Ch         ; Termina o programa.
    INT 21h
MAIN ENDP


; --- PROCEDIMENTO 1: LEITURA DE BINARIO ---
ReadBinary PROC
    XOR BX, BX
LeituraBinLoop:
    MOV AH, 01h
    INT 21h
    CMP AL, 0Dh
    JE FimReadBin
    SUB AL, '0'
    SHL BX, 1
    OR BL, AL
    JMP LeituraBinLoop
FimReadBin:
    RET
ReadBinary ENDP


; --- PROCEDIMENTO 2: IMPRESSAO DE BINARIO ---
PrintBinary PROC
    MOV CX, 16
PrintBinLoop:
    ROL BX, 1
    JC PrintUm
    MOV DL, '0'
    JMP ImprimeChar
PrintUm:
    MOV DL, '1'
ImprimeChar:
    MOV AH, 02h
    INT 21h
    LOOP PrintBinLoop
    RET
PrintBinary ENDP


; --- PROCEDIMENTO 3: LEITURA DE HEXADECIMAL ---
ReadHex PROC
    XOR BX, BX
LeituraHexLoop:
    MOV AH, 01h
    INT 21h
    CMP AL, 0Dh
    JE FimReadHex
    CMP AL, '9'
    JBE IsDigito
    SUB AL, '7'
    JMP Combina
IsDigito:
    SUB AL, '0'
Combina:
    SHL BX, 4
    OR BL, AL
    JMP LeituraHexLoop
FimReadHex:
    RET
ReadHex ENDP


; --- PROCEDIMENTO 4: IMPRESSAO DE HEXADECIMAL ---
PrintHex PROC
    MOV CX, 4
PrintHexLoop:
    ROL BX, 4
    MOV DL, BL
    AND DL, 0Fh
    CMP DL, 9
    JBE IsDigitoPrint
    ADD DL, '7'
    JMP ImprimeHexChar
IsDigitoPrint:
    ADD DL, '0'
ImprimeHexChar:
    MOV AH, 02h
    INT 21h
    LOOP PrintHexLoop
    RET
PrintHex ENDP

END MAIN