bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,fopen,fscanf,fprintf,fread,fclose,printf,scanf               ; tell nasm that exit exists even if we won't be defining it
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
    nume db "input.txt",0
    mod_acces db "r",0
    descriptor dd -1
    format db "%d", 0
    par1 dd -1
    par2 dd 0
    nr dd -1

; our code starts here
segment code use32 class=code
    start:
        
        push dword mod_acces
        push dword nume
        call [fopen]
        add esp,4*2
        
        cmp eax,0
        je final_tot
        mov dword[descriptor],eax
        
        repeta:
            ;fscanf(descriptor,format,variabile)
            push dword nr
            push dword format
            push dword[descriptor]
            call [fscanf]
            add esp,4*3
            
            cmp eax,-1
            je final_repeta
            
            mov eax,dword[nr]
            cmp dword[par1],-1
            jne nu_afisa
            
            mov cx,2
            
            mov bx,ax
            div cx
            cmp ah,0
            jne nu_afisa
            
            mov [par1],bx
            
            push par1
            push dword format
            call [printf]
            add esp,4*2
            
            nu_afisa:
            jmp repeta
            
        final_repeta:
        
        ;fclose(descriptor)
        push dword[descriptor]
        call [fclose]
        add esp,4*1
        
        final_tot:
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
