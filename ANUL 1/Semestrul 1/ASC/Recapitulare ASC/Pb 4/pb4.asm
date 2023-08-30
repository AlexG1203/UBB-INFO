bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,fopen,fclose,fscanf,printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fopen msvcrt.dll
import fscanf msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    nume_fisier db 'input.txt',0
    acces_mode db 'r',0
    descriptor dd -1
    format db '%d',0
    spatiu db ' '
    cif dd -1
    contor dd 0

; our code starts here
segment code use32 class=code
    start:
        push dword acces_mode
        push dword nume_fisier
        call [fopen]
        add esp, 4 * 2
        
        cmp eax,0
        je out_program
        mov dword[descriptor],eax
        
        repeta:
            push dword cif
            push dword format
            push dword [descriptor]
            call [fscanf]
            add esp,4*3
            
            cmp eax,-1
            je out_citire
            
            mov ebx,contor
            mov ecx,dword[cif]
            cmp ecx,'2'
            jne repeta
            add ebx,1
            mov dword[contor],ebx
        out_citire:
        
        push dword [descriptor]
        call [fclose]
        add esp,4*1
        
        push dword contor
        push dword format
        call [printf]
        add esp,4*2
        
        out_program:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
