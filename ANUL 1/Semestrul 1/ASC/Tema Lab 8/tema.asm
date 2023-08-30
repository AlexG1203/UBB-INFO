bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, scanf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import printf msvcrt.dll
import scanf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ;Sa se citeasca de la tastatura in baza 16 doua numere a si b de tip dword si sa se afiseze suma partilor low si diferenta partilor high.
    a dd 0
    b dd 0
    suma dd 0
    alow dd 0
    blow dd 0
    diferenta dd 0
    ahigh dd 0
    bhigh dd 0
    format1 db 'a=', 0
    format2 db 'b=', 0      
    readformat db '%x', 0  
    sumaformat db 'suma partilor low este: %x + %x = %x',10 , 0
    diferentaformat db 'diferenta partilor high este: %x - %x = %x', 0

; our code starts here
segment code use32 class=code
    start:
        ;Sa se citeasca de la tastatura in baza 16 doua numere a si b de tip dword si sa se afiseze suma partilor low si diferenta partilor high.
        
        ;apel printf("a=")
        push dword format1
        call [printf]
        add esp, 4 * 1
        
        ;apel scanf("%x", a)
        push dword a
        push dword readformat
        call [scanf]
        add esp, 4 * 2         
        
        ;apel printf("b=")
        push dword format2
        call [printf]
        add esp, 4 * 1
        
        ;apel scanf("%x", b)
        push dword b
        push dword readformat
        call [scanf]
        add esp, 4 * 2  
        
        mov esi,a; ofsset-ul sirului sursa a
        mov edi,alow; ofsset-ul sirului destinatie alow
        cld; df = 0
        lodsd; mov eax, [esi] + esi := esi + 4
        stosw; mov [edi], ax + edi := edi + 2
        
        mov esi,alow; ofsset-ul sirului sursa alow
        mov bx,word[esi]; bx = ofsset-ul sirului sursa alow
        
        mov esi,b; ofsset-ul sirului sursa b
        mov edi,blow; ofsset-ul sirului destinatie blow
        cld; df = 0
        lodsd; mov eax, [esi] + esi := esi + 4
        stosw; mov [edi], ax + edi := edi + 2
        
        mov esi,blow; ofsset-ul sirului sursa blow
        mov cx,word[esi]; cx = ofsset-ul sirului sursa blow
        
        add bx,cx; bx = bx + cx
        mov [suma],bx; [suma] = bx
        
        push dword [suma]; pune pe stiva valoarea sumei
        push dword [blow]; pune pe stiva valoarea lui blow
        push dword [alow]; pune pe stiva valoarea lui alow
        push dword sumaformat
        call [printf]
        add esp,4 * 4
        
        
        mov esi,a; ofsset-ul sirului sursa a
        mov edi,ahigh; ofsset-ul sirului destinatie ahigh
        lodsw; mov ax, [esi] + esi := esi + 2
        lodsw; mov ax, [esi] + esi := esi + 2
        stosw; mov [edi], ax + edi := edi + 2
        
        mov esi,ahigh; ofsset-ul sirului sursa ahigh
        mov bx,word[esi]; cx = ofsset-ul sirului sursa ahigh
        
        mov esi,b; ofsset-ul sirului sursa b
        mov edi,bhigh; ofsset-ul sirului destinatie bhigh
        lodsw; mov ax, [esi] + esi := esi + 2
        lodsw; mov ax, [esi] + esi := esi + 2
        stosw; mov [edi], ax + edi := edi + 2
        
        mov esi,bhigh; ofsset-ul sirului sursa bhigh
        mov cx,word[esi]; cx = ofsset-ul sirului sursa bhigh
        
        sub bx,cx; bx = bx - cx
        mov [diferenta],bx; [diferenta] = bx

        push dword [diferenta]; pune pe stiva valoarea diferentei
        push dword [bhigh]; pune pe stiva valoarea lui bhigh
        push dword [ahigh]; pune pe stiva valoarea lui ahigh
        push dword diferentaformat
        call [printf]
        add esp,4 * 4
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program