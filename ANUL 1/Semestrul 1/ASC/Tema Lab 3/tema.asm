bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ;(a+c)-b+a + (d-c) a - byte, b - word, c - double word, d - qword - Interpretare fara semn, Adunari/Scaderi
    ;a db 2
    ;b dw 3
    ;c dd 5
    ;d dq 7
    
    ;a-b-(c-d)+d a - byte, b - word, c - double word, d - qword - Interpretare cu semn, Adunari/Scaderi
    ;a db 5
    ;b dw 3
    ;c dd 5
    ;d dq 2
    
    ;x-b+8+(2*a-b)/(b*b)+e; a-word; b-byte; e-doubleword; x-qword - Interpretare fara semn, Inmultiri/Impartiri
    ;a dw 5
    ;b db 2
    ;e dd 3
    ;x dq 7
    
    ;x-b+8+(2*a-b)/(b*b)+e; a-word; b-byte; e-doubleword; x-qword - Interpretare cu semn, Inmultiri/Impartiri
    ;a dw 5
    ;b db 2
    ;e dd 3
    ;x dq 2

; our code starts here
segment code use32 class=code
    start:
        ;(a+c)-b+a + (d-c) a - byte, b - word, c - double word, d - qword - Interpretare fara semn, Adunari/Scaderi
        ;mov eax,0
        ;mov eax,dword [a+0]; eax = dword a
        ;add eax,[c]; eax = a+c
        ;sub eax,dword [b+0]; eax = (a+c) - dword b
        ;add eax,dword [a+0]; eax = (a+c) - b + dword a
        ;mov ebx,eax; ebx = eax
        ;mov edx,0
        ;mov eax,[d]
        ;sub eax,dword [c+0]
        ;add ebx,eax
        
        ;a-b-(c-d)+d a - byte, b - word, c - double word, d - qword - Interpretare cu semn, Adunari/Scaderi
        ;mov eax,[c]
        ;cdq
        ;sub eax,dword [d+0]
        ;sub edx,dword [d+4]; edx:eax = c-d
        ;mov ebx,eax; edx:ebx = c-d
        ;mov al,[a]
        ;cbw; ax=a
        ;sub ax,[b]; ax= a-b
        ;mov cx,ax
        ;mov eax,0
        ;mov ax,cx
        ;mov ecx,edx; ecx:ebx= c-d
        ;cdq; edx:eax= a-b
        ;sub edx,ecx
        ;sub eax,ebx
        ;add eax,dword [d+0]
        ;add edx,dword [d+4]
        
        ;x-b+8+(2*a-b)/(b*b)+e; a-word; b-byte; e-doubleword; x-qword - Interpretare fara semn, Inmultiri/Impartiri
        ;mov ax,2
        ;mov dx,[a]
        ;mul dx; ax = 2*a
        ;mov dx,0; dx:ax = 2*a
        ;sub dx,word [b+2]
        ;sub ax,word [b]; al = 2*a-b
        ;mov ah,0; ax = 2*a-b
        ;mov bx,ax; bx = 2*a-b
        ;mov al,[b]
        ;mov ah,[b]
        ;mul ah; ax = b*b
        ;mov cx,ax; cx = b*b
        ;mov ax,0
        ;mov ax,bx; ax = 2*a-b
        ;div cx; ax = (2*a-b)/(b*b)
        ;mov bx,ax; bx = (2*a-b)/(b*b)
        ;mov al,[b]
        ;cbw; ax = word b
        ;cwde; eax = dword b
        ;cdq; edx:eax = qword b
        ;mov cx,bx; cx = (2*a-b)/(b*b)
        ;cwde; ecx = (2*a-b)/(b*b)
        ;mov ebx,[x]
        ;sub ebx,eax
        ;add ebx,8; ebx = x-b+8
        ;cdq; edx:ebx = x-b+8
        ;add ecx,ebx; ecx = x-b+8+(2*a-b)/(b*b)
        ;add ecx, dword [e]; ecx = x-b+8+(2*a-b)/(b*b)+e
        
        ;x-b+8+(2*a-b)/(b*b)+e; a-word; b-byte; e-doubleword; x-qword - Interpretare cu semn, Inmultiri/Impartiri
        ;mov ax,2
        ;mov dx,[a]
        ;imul dx; ax = 2*a
        ;sbb dx,word [b+2]
        ;sbb ax,word [b]; ax = 2*a-b
        ;cbw
        ;mov bx,ax; bx = 2*a-b
        ;mov al,[b]
        ;mov ah,[b]
        ;imul ah; ax = b*b
        ;mov cx,ax; cx = b*b
        ;mov ax,0
        ;mov ax,bx; ax = 2*a-b
        ;idiv cx; ax = (2*a-b)/(b*b)
        ;mov bx,ax; bx = (2*a-b)/(b*b)
        ;mov al,[b]
        ;cbw; ax = word b
        ;cwde; eax = dword b
        ;cdq; edx:eax = qword b
        ;mov cx,bx; cx = (2*a-b)/(b*b)
        ;cwde; ecx = (2*a-b)/(b*b)
        ;mov ebx,[x]
        ;sbb ebx,eax
        ;adc ebx,8; ebx = x-b+8
        ;cdq; edx:ebx = x-b+8
        ;adc ecx,ebx; ecx = x-b+8+(2*a-b)/(b*b)
        ;adc ecx, dword [e]; ecx = x-b+8+(2*a-b)/(b*b)+e
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
