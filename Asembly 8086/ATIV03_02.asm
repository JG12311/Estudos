.MODEL SMALL
.STACK 100h

.DATA
    ; Mensagens para o usuário, com nova linha embutida
    msg_prompt      DB 'Digite um caractere (ESC para sair): $'
    msg_letra       DB  13,10,'O caractere digitado e uma letra.$'
    msg_numero      DB  13,10,'O caractere digitado e um numero.$'
    msg_desconhecido DB  13,10,'O caractere digitado e um caractere desconhecido.$'
    msg_fim         DB  13,10,'Fim do programa.$'

.CODE
main PROC
    ; Inicializa o segmento de dados
    MOV AX, @data
    MOV DS, AX

; Início do loop principal
inicioloop:
    ; Solicita ao usuário para digitar um caractere
    MOV AH, 9
    MOV DX, OFFSET msg_prompt
    INT 21h

    ; Lê o caractere do teclado
    MOV AH, 1
    INT 21h

    ; Verifica a condição de parada (tecla ESC)
    CMP AL, 1Bh
    JE fim_programa

; Lógica de Classificação do Caractere
    CMP AL, '0'
    JL e_desconhecido
    CMP AL, '9'
    JG nao_e_numero
    JMP e_numero

nao_e_numero:
    CMP AL, 'A'
    JL e_desconhecido
    CMP AL, 'Z'
    JG nao_e_letra_maiuscula
    JMP e_letra

nao_e_letra_maiuscula:
    CMP AL, 'a'
    JL e_desconhecido
    CMP AL, 'z'
    JG e_desconhecido
    JMP e_letra

; Blocos de Resposta

e_numero:
    MOV AH, 9
    MOV DX, OFFSET msg_numero
    INT 21h
    JMP inicioloop

e_letra:
    MOV AH, 9
    MOV DX, OFFSET msg_letra
    INT 21h
    JMP inicioloop

e_desconhecido:
    MOV AH, 9
    MOV DX, OFFSET msg_desconhecido
    INT 21h
    JMP inicioloop

; Finalização do Programa
fim_programa:
    MOV AH, 9
    MOV DX, OFFSET msg_fim
    INT 21h

    ; Encerra o programa
    MOV AH, 4Ch
    INT 21h

main ENDP
END main