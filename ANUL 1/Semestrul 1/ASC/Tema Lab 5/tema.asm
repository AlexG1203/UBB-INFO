bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ;Se dau 2 siruri de octeti A si B. Sa se construiasca sirul R care sa contina elementele lui B in ordine inversa urmate de elementele pare ale lui A.
    a db 2, 1, 3, 3, 4, 2, 6
    la equ $-a
    b db 4, 5, 7, 6, 2, 1
    lb equ $-b
    r resb la+lb
    
    ;Se da un sir de caractere S. Sa se construiasca sirul D care sa contina toate caracterele cifre din sirul S.
    ;s db '+', '4', '2', 'a', '8', '4', 'X', '5'
    ;ls equ $-s
    ;d resb ls

; our code starts here
segment code use32 class=code
    start:
    ;Se dau 2 siruri de octeti A si B. Sa se construiasca sirul R care sa contina elementele lui B in ordine inversa urmate de elementele pare ale lui A.
        mov ecx,lb; exc = lb (lungimea sirului b)
        mov esi,lb-1; esi = lb-1 (lungimea sirului b - 1)
        mov edi,0; edi = 0
        jecxz sfarsit; se executa codul din interior cat timp ecx != 0
            repeta:
                mov al,[b+esi]; al = [b+esi] (pune in al valoarea lui b de la b+esi)
                mov [r+edi],al; pune in sirul r valoarea din al (de la r+edi)
                dec esi; decrementeaza esi
                inc edi; incrementeaza edi
            loop repeta
        sfarsit:
        
        mov ecx,la; ecx = la (lungimea sirului a)
        mov esi,0; esi = 0
        mov edi,lb; edi = lb (lungimea sirului b)
        mov bl,2; bl = 2 (pentru a verifica paritatea)
        jecxz sfarsit2; se executa codul din interior cat timp ecx != 0
            repeta2:
                mov al,[a+esi]; al = [a+esi] (pune in al valoarea lui a de la a+esi)
                mov ah,0; pentru conversia al -> ax
                mov dx,ax; dx = ax
                div bl; divide pe ah = ax % bl (ah rest)
                cmp ah,0; se face scaderea fictiva ah - 0
                jne next; daca scaderea fictiva anterioara nu este 0 atunci se executa codul de la eticheta next
                    mov [r+edi],dx; pune in sirul r valoarea din dx (de la r+edi)
                    inc esi; incrementeaza esi
                    inc edi; incrementeaza edi
                next:
                inc esi; incrementeaza esi
                inc edi; incrementeaza edi
                loop repeta2            
        sfarsit2:

        ;Se da un sir de caractere S. Sa se construiasca sirul D care sa contina toate caracterele cifre din sirul S.
        ;mov ecx,ls; exc = ls (lungimea sirului s)
        ;mov esi,s; esi = s
        ;mov edi,d; edi = d
        ;mov bl,48; bl = 48 (pentru a putea vedea care din caracterele date sunt cifre)
        ;cld; sensul ->, si DF = 0
        ;jecxz final; se executa codul din interior cat timp ecx != 0
           ; repeta:
                ;lodsb; al = [esi] = s (parcurge fiecare caracter)
                ;mov dl,al; dl = al
                ;sub dl,bl; dl = dl - 48
                ;cmp dl,10; se face scadere fictiva dl - 10
                ;jnb next; daca scaderea fictiva anteriaora este peste 10 atunci se executa codul de la eticheta next
                    ;stosb; daca scderea fictiva anteriaora este sub 10 atunci se preia rezultatul si se pune in [edi] = d (echivalent cu mov [d+edi],al)
                ;next:
                ;loop repeta
        ;final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
