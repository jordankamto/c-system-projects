#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define n 10

int main(int argc, char const *argv[])
{
    int i, p = fork();

    if (p == -1)
    {
        perror("fork");
        return -1;
    }

    if (p > 0)
    {
        for (i = 0; i < 2; i++)
            printf("print %d de %d fils de %d\n", i, getpid(), getppid());
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            printf("printf %d de %d fils de %d\n", i, getpid(), getppid());
        }
    }

    // Le printf suivant est en dehors de la boucle for
    printf("printf %d de %d fils de %d\n", i, getpid(), getppid());

    return 0;
}
