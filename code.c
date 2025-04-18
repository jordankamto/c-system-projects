#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define N_MAX 10

int a;
int *shared_variable =&a;

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Processus fils
        for (int i = 0; i < N_MAX; i++) {
            printf("Fils : %d\n", *shared_variable);
        }
    } else {
        // Processus père
        for (int i = 0; i <= N_MAX; i++) {
            *shared_variable = &i;
        }
        wait(5); // Attendez la fin du processus fils
    }

    return 0;
}