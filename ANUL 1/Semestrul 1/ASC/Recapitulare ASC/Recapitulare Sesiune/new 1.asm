bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; x dw -256,256h
    ; y dw 256|-256,256h & 256
    ; z db $-z,y-x
      ; db 'y'-'x','y-x'
    ; a db 512>>2,-512<<2
    ; b db z-a
    ; a2 dw 256,256h
    ; a3 dw $-a2
    ; a4 equ -256/4
    ; a5 db 128>>1,-128<<1
    ; a6 dw a5-a2
    ; a1 dd '0abcdefh',0abcdefh
    ; a2 dw '0abcdefh',3|6
    ; a3 dw $-a2,a2-a1
    ; a4 db 129>>1,-129<<1
    ; a5 dw a2-a4,~(a2-a4)

    ; a7 dd 256h^256,256256h
    ; a8 dd (a9-$),-256
    ; a9 dw -255,-128
    ; a10 times 4 dw 128h,-128
    ; a11 db a3
    ; ; a12 dw a3

; our code starts here
segment code use32 class=code
    start:
        mov eax,256h&255
        mov ebx,256^256h
        mul bh
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
