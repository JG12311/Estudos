title minisculo para maisculo
.model small
.data
 msg1 DB "Digite uma letra minuscula:$"
 msg2 DB 13,10,"Letra maiuscula:$"


.code 
main proc 
    mov ax,@data ; inicializar DS com endereco do segmento de dados
    mov ds, ax

    mov ah,09h         ;funcao 09 impirme um string
    mov dx, offset msg1 ; endereço incial do string
    int 21h            ; executa a funcao 09

    mov ah,01h         ;leitura de 1 caracter
    int 21h
    mov bl, al      ;guarda irformação lida

    sub bl, 32      ; troca para maisculo

    mov ah,09h
    mov dx, offset msg2  ;imprime segunda string
    int 21h

    mov dl, bl
    mov ah,02h  ;imprime segundo caracter
    int 21h
    

    mov ah,4ch ; fim do programa
    int 21h ; retorno ao SO
main endp
end main 