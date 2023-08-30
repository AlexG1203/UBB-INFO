bits 32
global _ProgramC       
segment data public data use32
segment code public code use32
_ProgramC:
    start:
        push ebp; punem ebp pe stiva
        mov ebp, esp
        
        mov eax, [ebp + 8]; eax = valoarea de la ebp+8
        mov ebx, [ebp + 12]; ebx = valoarea de la ebp+12
        mov ecx, [ebp + 16]; ecx = valoarea de la ebp+16
        
        add eax, ebx; eax = eax + ebx (a+b)
        sub eax,ecx; eax = eax - ecx (a+b-c)
        
        mov esp, ebp
        pop ebp; eliberam stiva

        ret