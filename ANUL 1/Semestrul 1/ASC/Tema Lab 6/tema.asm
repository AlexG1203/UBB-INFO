bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ;Se da un sir de octeti reprezentand un text (succesiune de cuvinte separate de spatii). Sa se identifice cuvintele de tip palindrom (ale caror oglindiri sunt similare cu cele de plecare): "cojoc", "capac" etc.
    s db 'cojoc rac mac capac masina '
    ls equ $-s
    cuv_curent times ls db 0
    rez times ls db 0

; our code starts here
segment code use32 class=code
    start:
        mov ecx,ls; ecx = ls (lungimea sirului s)
        mov esi,0; esi = 0
        mov edi,0; edi = 0
        jecxz final; se executa codul din interior cat timp ecx != 0
            repeta:
                mov al,[s+esi]; al = [s+esi] (pune in al valoarea lui s de la s+esi)
                mov bl,al; bl = al
                cmp bl,32; se face scaderea fictiva bl - 32
                jz next; daca scaderea fictiva anterioara este 0 se executa codul de la eticheta next
                mov [cuv_curent+edi],al; [cuv_curent+edi] = al (pune in cuv_curent la pozitia edi valoarea lui al)
                inc esi; incrementeaza esi
                inc edi; incrementeaza edi
            loop repeta
                next:
                    mov ebp,ls-(ls-edi); ebp = ls-(ls-edi) (pune in ebp lungimea cuv_curent)
                    mov dl,2; dl = 2 (pentru a afisa 2 daca cuvantul nu e palindrom)
                    mov dh,1; dh = 1 (pentru a afisa 1 daca cuvantul e palindrom)
                    mov edi,0; edi = 0
                        repeta1:
                        mov cl,[cuv_curent+ebp-1]; cl = [cuv_curent+ebp-1] (pune in cl valoarea de la cuv_curent+ebp-1)
                        mov ch,[cuv_curent+edi]; ch = [cuv_curent+edi] (pune in ch valoarea de la cuv_curent+edi)
                        sub ch,cl; ch = ch - cl
                        cmp ch,0; se face scaderea fictiva ch - 0
                        jnz next2; daca scaderea fictiva anterioara nu este 0 se executa codul de la eticheta next2
                        inc edi; incrementeaza edi
                        dec ebp; decrementeaza ebp
                        cmp ebp,0; se face scaderea fictiva ebp - 0
                        jnz next1; daca scaderea fictiva anterioara nu este 0 se executa codul de la eticheta next1
                        mov [rez+esi],dh; [rez+esi] = dh (pune in rez la pozitia esi valoarea lui dh => cuvantul este palindrom)
                        inc esi; incrementeaza esi
                        mov edi,0; edi = 0
                        loop repeta
                        next1:
                        loop repeta1
                    next2:
                    mov [rez+esi],dl; [rez+esi] = dl (pune in rez la pozitia esi valoarea lui dl => cuvantul nu este palindrom)
                inc esi; incrementeaza esi
                mov edi,0; edi = 0
                loop repeta
        final:
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
