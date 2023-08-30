bits 32

global start        

; declare extern functions used by the programme
extern exit, printf, scanf ; add printf and scanf as extern functions            
import exit msvcrt.dll    
import printf msvcrt.dll    ; tell the assembler that function printf is found in msvcrt.dll library
import scanf msvcrt.dll     ; similar for scanf
%include "tema_modul.asm"
;extern calcul
                          
segment data use32 class=data
	a dd  0       
	b dd  0       
	c dd  0       
	message_a  db "a=", 0
	message_b  db "b=", 0
	message_c  db "c=", 0
	format_citire_numar  db "%d", 0
    format_printare_numar db "a + b - c = %d ", 0
    
segment code use32 class=code
    start:
       
        ;apel printf("a=")
        push dword message_a
        call [printf]      
        add esp, 4*1  
        
        ;apel scanf("%x", a)
        push dword a 
        push dword format_citire_numar
        call [scanf]       
        add esp, 4 * 2
        
        ;apel printf("b=")
        push dword message_b 
        call [printf]      
        add esp, 4*1
        
        ;apel scanf("%x", b)
        push dword b
        push dword format_citire_numar
        call [scanf]       
        add esp, 4 * 2
        
        ;apel printf("c=")
        push dword message_c 
        call [printf]      
        add esp, 4*1
        
        ;apel scanf("%x", c)
        push dword c
        push dword format_citire_numar
        call [scanf]       
        add esp, 4 * 1
        
        ;mov eax, 0
        ;mov al, [a]
        ;add al, [b]
        ;sub al, [c]
        ;mov [a], al
        
        push dword [c]; punem pe stiva c
        push dword [b]; punem pe stiva b
        push dword [a]; punem pe stiva a
        call calcul; apelam subprogramul
        ;add esp, 4 * 1
        
        ;format printare pe ecran
        push dword eax
        push dword format_printare_numar
        call [printf]
        add esp, 4 * 2
                           
        
        ; exit(0)
        push dword 0      ; place on stack parameter for exit
        call [exit]       ; call exit to terminate the program