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
    b dd 0
    suma dd 0
    diferenta dd 0
    rez dd 0
    format db "%d",0
    mesaj_a db "a=",0
    mesaj_b db "b=",0
    mesaj_suma db "(a+b)=%d",10,13,0
    mesaj_diferenta db "(a-b)=%d",10,13,0
    mesaj_rez db "(a+b)*(a-b)=%d",0

; our code starts here
segment code use32 class=code
    start:
    
        ;Sa se citeasca de la tastatura doua numere a si b (in baza 10) si sa se calculeze: (a+b) * (a-b)
    
        push mesaj_a
        call [printf]
        add esp,4*1
        
        push dword a
        push dword format
        call [scanf]
        add esp, 4*2
        
        push mesaj_b
        call [printf]
        add esp,4*1
        
        push dword b
        push dword format
        call [scanf]
        add esp, 4*2
        
        mov al,[a]
        add al,[b]
        mov [suma],al
        
        mov al,[a]
        sub al,[b]
        mov [diferenta],al
        
        mov al,[suma]
        mov bl,[diferenta]
        mul bl
        mov [rez],ax
        
        push dword [suma]
        push dword mesaj_suma
        call [printf]
        add esp, 4*2
        
        push dword [diferenta]
        push dword mesaj_diferenta
        call [printf]
        add esp, 4*2
        
        push dword [rez]
        push dword mesaj_rez
        call [printf]
        add esp, 4*2
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
