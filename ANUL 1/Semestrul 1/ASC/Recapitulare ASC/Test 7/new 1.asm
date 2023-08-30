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
    formatc db "%c", 0
    format db "%d", 0
    k dd 5
    rez dd 0
    numar_curent dd 0
    suma_curenta dd 0

; our code starts here
segment code use32 class=code
    start:
        repeta:
        
            ;Nu merge
        
            push mesaj_a
            call [printf]
            add esp, 4*1
            
            push dword a
            push dword format
            call [scanf]
            add esp, 4*2
            
            mov ax,[a]
            cmp ax,0
            jz iesi_repeta
            
            mov esi,0
            mov [suma_curenta],esi
            
            repeta_numar:
            
                cmp byte[a],'#'
                je afisare
                
                mov bl,byte[a]
                add [suma_curenta],bl
                
                push dword a
                push dword formatc
                call [scanf]
                add esp, 4*2
                
            loop repeta_numar
            
            afisare:
                push dword a
                push dword format
                call [printf]
                add esp, 4*2
        
        loop repeta
        iesi_repeta:
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
