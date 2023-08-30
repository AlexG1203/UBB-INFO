bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ;(a+b)-(a+d)+(c-a) a,b,c,d - byte, Adunari/Scaderi
    ;a db 7
    ;b db 6
    ;c db 9
    ;d db 3
    
    ;c-(d+a)+(b+c) a,b,c,d - word, Adunari/Scaderi
    ;a dw 3
    ;b dw 2
    ;c dw 15
    ;d dw 4
    
    ;[2*(a+b)-5*c]*(d-3) a,b,c - byte, d - word, Inmultiri/Impartiri
    ;a db 3
    ;b db 3
    ;c db 2
    ;d dw 5
    
    ;(a*b)/c a,b,c,d-byte, e,f,g,h-word, Inmultiri/Impartiri
    ;a db 2
    ;b db 8
    ;c db 4

; our code starts here
segment code use32 class=code
    start:
        ;(a+b)-(a+d)+(c-a) a,b,c,d - byte, Adunari/Scaderi
        ;mov al,[a]
        ;add al,[b]
        ;mov bl,[a]
        ;add bl,[d]
        ;mov cl,[c]
        ;sub cl,[a]
        ;sub al,bl
        ;add al,cl
        
        ;c-(d+a)+(b+c) a,b,c,d - word, Adunari/Scaderi
        ;mov ax,[d]
        ;add ax,[a]
        ;mov bx,[b]
        ;add bx,[c]
        ;mov cx,[c]
        ;sub cx,ax
        ;add cx,bx
        
        ;[2*(a+b)-5*c]*(d-3) a,b,c - byte, d - word, Inmultiri/Impartiri
        ;mov al,[a]
        ;add al,[b]
        ;mov ah,2
        ;mul ah; ax=2*(a+b)
        ;mov bx,ax
        ;mov al,5
        ;mov ah,[c]
        ;mul ah; ax=al*ah
        ;sub bx,ax
        ;mov ax,[d]
        ;sub ax,3
        ;mul bx
        
        ;(a*b)/c a,b,c,d-byte, e,f,g,h-word, Inmultiri/Impartiri
        ;mov al,[a]
        ;mov bl,[b]
        ;mul bl; ax=a*b
        ;mov cl,[c]
        ;div cl
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
