#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int i,n,somme=0;
    printf("enter a number");
    scanf("%d", &n);
    for (i = 0; i <= n; i++)
    {
        somme += i;
    };
    printf("la somme est: %d", somme);
    return 0;
}