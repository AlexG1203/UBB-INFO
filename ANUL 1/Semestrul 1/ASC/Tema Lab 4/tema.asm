bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ;Se dau cuvintele A si B. Se cere dublucuvantul C:
    ;bitii 0-5 ai lui C coincid cu bitii 3-8 ai lui A
    ;bitii 6-8 ai lui C coincid cu bitii 2-4 ai lui B
    ;bitii 9-15 ai lui C reprezinta bitii 6-12 ai lui A
    ;bitii 16-31 ai lui C sunt 0
    ;a dw 0111011101010111b
    ;b dw 1001101110111110b
    ;c dd 0
    
    
    ;Se dau cuvintele A, B si C. Sa se obtina octetul D ca suma a numerelor reprezentate de:
    ;biţii de pe poziţiile 0-4 ai lui A
    ;biţii de pe poziţiile 5-9 ai lui B
    ;Octetul E este numarul reprezentat de bitii 10-14 ai lui C. Sa se obtina octetul F ca rezultatul scaderii D-E.
    ;a dw 0111011101010111b
    ;b dw 1001101110111110b
    ;c dw 1001101101010111b
    ;d db 0
    ;e db 0
    ;f db 0

; our code starts here
segment code use32 class=code
    start:
        ;Se dau cuvintele A si B. Se cere dublucuvantul C:
        ;bitii 0-5 ai lui C coincid cu bitii 3-8 ai lui A
        ;bitii 6-8 ai lui C coincid cu bitii 2-4 ai lui B
        ;bitii 9-15 ai lui C reprezinta bitii 6-12 ai lui A
        ;bitii 16-31 ai lui C sunt 0
        ;mov ebx,0
        ;mov ax,[a]; ax = a
        ;cwde; eax = a
        ;and eax,0000000111111000b; izolam bitii 3-8 a lui a
        ;mov cl,3
        ;ror eax,cl; roteste 3 pozitii spre dreapta
        ;or ebx,eax; pune in ebx rezultatul
        
        ;mov ax,[b]; ax = b
        ;cwde; eax = b
        ;and eax,0000000000011100b; izolam bitii 2-4 a lui b
        ;mov cl,4
        ;rol eax,cl; roteste 4 pozitii spre stanga
        ;or ebx,eax; pune in ebx rezultatul
        
        ;mov ax,[a]; ax = a
        ;cwde; eax = a
        ;and eax,0001111111000000b; izolam bitii 6-12 a lui a
        ;mov cl,3
        ;rol eax,cl; roteste 3 pozitii spre stanga
        ;or ebx,eax; pune in ebx rezultatul
        
        
        ;Se dau cuvintele A, B si C. Sa se obtina octetul D ca suma a numerelor reprezentate de:
        ;biţii de pe poziţiile 0-4 ai lui A
        ;biţii de pe poziţiile 5-9 ai lui B
        ;Octetul E este numarul reprezentat de bitii 10-14 ai lui C. Sa se obtina octetul F ca rezultatul scaderii D-E.
        ;mov bx,0
        ;mov ax,[a]
        ;and ax,0000000000011111b; izolam bitii 0-4 a lui a
        ;or bx,ax; pune in bx rezultatul
        
        ;mov cx,0
        ;mov ax,[b]
        ;and ax,0000001111100000b; izolam bitii 5-9 a lui b
        ;mov cl,5
        ;ror ax,cl; roteste 5 pozitii spre dreapta
        ;or cx,ax; pune in cx rezultatul
        
        ;add bx,cx; bx = bitii 0-4 A + bitii 5-9 B
        ;mov al,[d]; al = d
        ;cbw; ax = d
        ;mov ax,bx; ax = bx
        ;mov dx,ax; dx = ax
        
        ;mov bx,0
        ;mov ax,[c]
        ;and ax,0111110000000000b; izolam bitii 5-9 a lui c
        ;mov cl,10
        ;ror ax,cl; roteste 10 pozitii spre dreapta
        ;or bx,ax; pune in bx rezultatul
        
        ;sub dx,bx; dx = D-E
        ;mov al,[f]; al = f
        ;cbw; ax = f
        ;mov ax,dx; ax = dx
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
