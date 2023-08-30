#include <stdio.h>

int ProgramC(int a, int b, int c);

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int rez = 0;
    
    printf("a=");
    scanf("%d", &a);
    
    printf("b=");
    scanf("%d", &b);
    
    printf("c=");
    scanf("%d", &c);
    
    rez = ProgramC(a,b,c);
    printf("a+b-c = %d", rez);
    return 0;
}