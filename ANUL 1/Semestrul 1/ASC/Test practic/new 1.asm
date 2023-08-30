bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,fopen,fscanf,fprintf,fread,fclose,printf,scanf                ; tell nasm that exit exists even if we won't be defining it
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
    nume_in db "input.txt",0
    nume_out db "output.txt",0
    mod_acces_in db "r",0
    mod_acces_out db "w",0
    format db '%s',0
    descriptor_in dd -1
    descriptor_out dd -1
    sursa times 100 db -1
    len equ 100
    n dd 0

; our code starts here
segment code use32 class=code
    start:
        
        push dword mod_acces_in
        push dword nume_in
        call[fopen]
        add esp, 4*2
        
        cmp eax,0
        je final
        
        mov [descriptor_in],eax
        
        push dword [descriptor_in]
        push dword len
        push dword 1
        push dword sursa
        call [fread]
        add esp, 4*4
        
        mov ebx,0
        mov esi,sursa
        nr_c:
            lodsb; al este caracter
            cmp al,0
            je fin_nr
            inc ebx
        jmp nr_c
        fin_nr:    
        
        mov [n],ebx
        mov eax,ebx
        mov bx,2
        div bx; ax - jum nr de caractt
        mov bx,ax
        mov eax,0
        mov ax,bx; eax - jum nr de carct
        mov ecx,eax
        mov esi,0
        mov ax,0
        schimba:
            mov eax,esi
            mov bx,2
            div bx ; dx rest
            cmp dx,0
            je nu_intersch
            mov bl,[sursa+esi]
            mov edi,[n]
            mov edi,esi
            sub edi,1
            mov al,[sursa+edi]
            mov [sursa+esi],al
            mov [sursa+edi],bl
            nu_intersch:
            inc esi
        loop schimba
       
        push dword mod_acces_out
        push dword nume_out
        call [fopen]
        add esp,4*2
        
        cmp eax,0
        je final
        mov [descriptor_out],eax
        
        push dword sursa
        push dword format
        push dword [descriptor_out]
        call [fprintf]
        add esp,4*3
        
        push dword sursa
        push dword format
        call [fprintf]
        add esp, 4*3
            
        final:    
        push descriptor_out
        call [fclose]
        add esp, 4*1
        
        push descriptor_in
        call [fclose]
        add esp, 4*1
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
