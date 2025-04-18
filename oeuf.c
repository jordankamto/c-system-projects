#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int N, NB=0;
    printf("entrez le nombre d'oeufs\n");
    scanf("%d", &N);
    while (N>=12)
    {
        N-=12;
        NB+=1;
    }
    printf("il faut %d boite(s) et le reste d'oeufs est %d", NB, N);
    return 0;
}
