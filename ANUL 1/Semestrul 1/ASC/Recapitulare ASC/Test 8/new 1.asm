bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,fopen,fscanf,fprintf,fread,fclose,printf,scanf,gets               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fopen msvcrt.dll
import fscanf msvcrt.dll
import fprintf msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
import gets msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    sursa times 100 db -1
    destinatie times 100 db -1
    format db "%s ",0
    cuv times 100 db -1

; our code starts here
segment code use32 class=code
    start:
        
        push dword sursa
        call [gets]
        add esp, 4*2
        
        mov esi,sursa
        mov edi,destinatie
        mov ecx,-1
        
        repeta:
            cmp byte[esi],0 ;verificam daca am ajuns la final  - conditie de oprire
            je final_repeta
            
            cmp byte[esi],'*'
            jne stocheaza_litera
            je operatie
            
            stocheaza_litera:
                movsb  ;se stocheaza in edi caracterul de la esi
                jmp repeta
            
            operatie:
                sub edi,2 ;l-a crescut la ultima litera stocata
                mov ebx,cuv

                    mov al,byte[edi]
                    mov byte[ebx],al 
                    add ebx,1                    
                
                mov byte[ebx],0 ;resetam
                
                ;printf(format,variabila) - afisam cuvantul inversat din edi
                push dword cuv
                push dword format
                call [printf]
                add esp, 4*2
                
                mov edi,destinatie ; resetam,sa nu mai avem cuvantul deja prelucrat
                add esi,1 ; sa treaca de spatiu
                jmp repeta
                
        final_repeta:
        sub edi,2
        mov ebx,cuv
        repeta2:
            mov al,byte[edi]
            mov byte[ebx],al
            add ebx,1
       final_repeta2:
       mov byte[ebx],0
       ;printf(format,variabila) - afisam cuvantul inversat din edi
       push dword cuv
       push dword format
       call [printf]
       add esp, 4*2
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
