TITLE Lab05_04 - 4 caracteres por linha
.model small
.stack 100h
.data
    letra db 'a'           ; Inicializa com 'a'
    count db 0             ; Contador para 4 letras por linha
    novaLinha db 13,10,'$' ; Quebra de linha para DOS
.code
start:
    mov ax, @data
    mov ds, ax

imprimir:
    mov ah, 02h            ; Função do DOS: exibir caractere
    mov dl, letra          ; Caractere a exibir
    int 21h

    inc letra              ; Próxima letra
    inc count              ; Incrementa contador de letras

    cmp count, 4           ; Verifica se já exibiu 4 letras
    jne verificarFim

    ; Exibe nova linha
    mov ah, 09h
    lea dx, novaLinha
    int 21h

    mov count, 0           ; Reseta contador

verificarFim:
    cmp letra, 'z'+1       ; Checa se terminou
    jne imprimir

    ; Exibe última linha caso não tenha completado 4 letras
    cmp count, 0
    je fim
    mov ah, 09h
    lea dx, novaLinha
    int 21h

fim:
    mov ah, 4Ch            ; Função do DOS: encerrar programa
    int 21h
end start