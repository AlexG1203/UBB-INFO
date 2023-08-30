bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,fopen,fscanf,fprintf,fread,fclose,printf,scanf            ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fopen msvcrt.dll
import fscanf msvcrt.dll
import fprintf msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    nume_fisier db "input.txt",0
    mod_acces db "r",0
    descriptor dd -1
    len equ 100
    sir times (len+1) db 0
    format db "%s",0
    nr_cifp dd 0
    ;format_cifp db "Numarul de cifre pare este: %d", 0

; our code starts here
segment code use32 class=code
    start:
    
        ;Se citeste un sir de numaere pana la introducerea '#', afiseaza de cate ori apare cifra 2 in sir (merge doar in olly)
        
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 4*2
        
        mov [descriptor],eax
        
        cmp eax,0
        je final
            push dword [descriptor]
            push dword len
            push dword 1
            push dword sir        
            call [fread]
            add esp, 4*4
            
            mov esi,0
            mov edi,0
            repeta:
                mov ax,[sir+esi]
                inc esi
                cmp ah,'#'
                jz iesi_repeta
                cmp ah,'2'
                jnz repeta
                inc edi
                
            loop repeta
            
            iesi_repeta:
            
            mov dword [nr_cifp],edi
            
            ; push dword sir
            ; push dword eax
            ; push dword format
            ; call [printf]
            ; add esp, 4*3
            
            push dword [nr_cifp]
            push dword format
            call [printf]
            add esp, 4*2

            push dword [descriptor]
            call [fclose]
            add esp, 4*1

        final:
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
