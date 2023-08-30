bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fprintf, fclose               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fopen msvcrt.dll  
import fprintf msvcrt.dll
import fclose msvcrt.dll


; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ;Se dau un nume de fisier si un text (definite in segmentul de date). Textul contine litere mici si spatii. Sa se inlocuiasca toate literele de pe pozitii pare cu numarul pozitiei. Sa se creeze un fisier cu numele dat si sa se scrie textul obtinut in fisier.
    nume_fisier db "ana.txt",0
    mod_acces db "a",0
    s db 'ana are multe mere si pere '
    ls equ $-s
    rez times ls db 0
    descriptor_fis dd -1
    format db "%s",0

; our code starts here
segment code use32 class=code
    start:
        ;Se dau un nume de fisier si un text (definite in segmentul de date). Textul contine litere mici si spatii. Sa se inlocuiasca toate literele de pe pozitii pare cu numarul pozitiei. Sa se creeze un fisier cu numele dat si sa se scrie textul obtinut in fisier.
    
        push dword mod_acces     
        push dword nume_fisier
        call [fopen]
        add esp, 4 * 2

        mov [descriptor_fis], eax
        
        cmp eax, 0
        je final
            
            mov ecx,ls; ecx = ls (lungimea sirului s)
            mov esi,0; esi = 0
            mov ax,0; ax = 0
            jecxz sfarsit
                repeta:
                    mov bh,[s+esi]; bh = [s+esi] (bh ia valoarea sirului la pozitia s+esi)
                    cmp bh,32; se realizeaza scaderea fictiva a codului ascii din bh si 32
                    jz next; daca scaderea fictiva este 0 se executa codul de la eticheta next
                        mov bl,2; bl = 2
                        mov dx,ax; dx = ax
                        div bl; ah = ax % bl
                        cmp ah,0; se realizeaza scaderea fictiva a valorii din ah si 0 (daca este 0 pozitia este para, impara altfel)
                        mov ax,dx; ax = dx
                        jz next1; daca scaderea fictiva este 0 se executa codul de la eticheta next1
                            mov [rez+esi],bh; [rez+esi] = bh (la pozitia rez+esi se pune valoarea din bh)
                            inc esi; incrementeaza esi
                            add ax,1; incrementeaza ax cu 1
                            loop repeta
                        next1:
                            mov [rez+esi],esi; [rez+esi] = esi (la pozitia rez+esi se pune valoarea lui esi)
                            inc esi; incrementeaza esi
                            add ax,1; incrementeaza ax cu 1
                            loop repeta
                    next:
                        mov [rez+esi],bh; [rez+esi] = bh (la pozitia rez+esi se pune valoarea din bh)
                        inc esi; incrementeaza esi
                        add ax,1; incrementeaza ax cu 1
                loop repeta
            sfarsit:
            
            push dword [rez]
            push dword format
            push dword [descriptor_fis]
            call [fprintf]
            add esp, 4 * 3
            
            push dword [descriptor_fis]
            call [fclose]
            add esp, 4 * 1
            
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
