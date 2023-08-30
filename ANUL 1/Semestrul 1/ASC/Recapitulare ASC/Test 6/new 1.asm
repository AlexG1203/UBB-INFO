bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,fopen,fscanf,fclose,printf,scanf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fopen msvcrt.dll
import fscanf msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a dd 0
    mesaj_a db "a=",0
    format db "%d", 0

; our code starts here
segment code use32 class=code
    start:
    
        ;Citire pana la introducerea cifrei 0
    
        repeta:
            push mesaj_a
            call [printf]
            add esp, 4*1
            
            push dword a
            push dword format
            call [scanf]
            add esp, 4*2
            
            mov al,[a]
            cmp al,0
            jz iesi_repeta
        
        loop repeta
        iesi_repeta:
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
