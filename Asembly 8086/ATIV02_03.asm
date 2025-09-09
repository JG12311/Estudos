title soma
.model small
.data
msg1 db "Digite o primeiro numero:$"
msg2 db 13,10, "Digite o segundo numero:$"
msg3 db 13,10, "Resultado:$"

.code
main proc
    mov ax,@data ; inicializar DS com endereco do segmento de dados
    mov ds,ax

    mov ah,09h
    mov dx, offset msg1  ;imprime string
    int 21h
    
    mov ah,01h
    int 21h
    sub al,'0' ; converte para numero
    mov bl,al ;guarda em bl

    mov ah,09h
    mov dx, offset msg2  ; imprime string
    int 21h

    mov ah,01h
    int 21h
    sub al,'0'  ; converte para numero
    mov bh,al ;guarda em bh

    add bl,bh ; soma

    mov ah,09h
    mov dx, offset msg3  ; imprime string
    int 21h
    
    add bl, '0' ; converte para numero
    mov dl, bl
    mov ah, 02h   ; imprime resultado
    int 21h

    mov ah,4ch ; fim do programa
    int 21h ; retorno ao SO
main endp
end main 





    