#include<stdio.h>
#include<stdlib.h>
int main() {
    int age;
    char sex;
    printf("Entrez votre sex et votre age");
    scanf("%c %d", &sex,&age);
    if(sex=='M' && age>20){
             printf("Vous devez payer vos impots");
    }
    else if (sex=='F' && age<=35)
    {
        printf("Vous devez payer vos impots");
    }
    else{
        printf("Vous n'avez pas a payer d'impots");
    }
    return 0;
}