#include <stdio.h>

void afisare(int v[],int n){
    for (int i = 1; i <= n; i++) {
        printf("%d",v[i]);
    }
}

int prim(int n)
{
    int ok = 0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
            ok++;
    }
    if(ok == 2)
        return 1;
    return 0;
}

int main() {
    int comanda;
    printf("\n1.Determina primele n cifre din scrierea fractiei subunitare"
                        "k/m = 0.c1c2c3..., pentru k si m numere naturale date.\n"
                        "2.Tipareste un numar precizat de termeni din sirul"
                        "1, 2,1, 3,2,1, 4,2,2, 5,4,3,2,1, 6,2,2,3,3,3, 7,6, ..."
                        "obtinut din sirul numerelor naturale prin inlocuirea fiecarui"
                        "numar natural n printr-un grup de numere. Numarul prim p este"
                        "inlocuit prin numerele p,p-1,...3,2,1, iar numarul compus n"
                        "este inlocuit prin n urmat de toti divizorii sai proprii,"
                        "un divizor d repetandu-se de d ori.\n");
    printf("Introduceti numarul cerintei: ");
    scanf("%d",&comanda);
    if(comanda == 1)
    {
        int n,k,m;
        int rez[100];
        printf("Cititi numarul n:");
        scanf("%d",&n);
        printf("Cititi numarul k:");
        scanf("%d",&k);
        printf("Cititi numarul m:");
        scanf("%d",&m);
        int rest = (k % m) * 10;
        int i = 1;
        while (i<=n){
            int restc = rest / m;
            rez[i] = restc;
            rest = (rest - (restc * m)) * 10;
            i++;
        }
        afisare(rez,n);
    }
    else{
        int termeni;
        int i = 0;
        int nr = 1;
        printf("Introduceti numarul de termeni: ");
        scanf("%d",&termeni);
        printf("%d ",nr);
        i++;
        nr = 2;
        while (i < termeni){
            if(prim(nr)==1)
            {
                for(int j=nr;j>=1;j--)
                {
                    printf("%d ",j);
                    i++;
                    if(i>=termeni)
                        return 0;
                }
                nr++;
            }
            else{
                int cnr=nr;
                printf("%d ",nr);
                i++;
                if(i>=termeni)
                    return 0;
                int p,d=2;
                while(nr>1)
                {
                    p=0;
                    while(nr%d==0)
                        p++,nr=nr/d;

                    int put = d;
                    for(int j=1;j<=put;j++)
                    {
                        printf("%d ",put);
                        i++;
                        if(i>=termeni)
                            return 0;
                    }
                    ++d;
                }
                cnr++;
                nr = cnr;
            }
        }
    }
    return 0;
}
