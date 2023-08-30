%ifndef _TEMA_ASM_ ; 
%define _TEMA_ASM_;
;global calcul

calcul:
    mov eax, [esp+4]; eax = valoarea de la ebp+8
    mov ebx, [esp+8]; ebx = valoarea de la ebp+12
    mov ecx, [esp+12]; ecx = valoarea de la ebp+16
    add eax, ebx; eax = eax + ebx (a+b)
    sub eax, ecx; eax = eax - ecx (a+b-c)
    ret 
    
%endif
    