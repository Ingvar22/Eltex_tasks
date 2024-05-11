#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char input[100];
    char *args[10];

    while (1) {
        printf("Enter: ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\n");
            break;
        }

        input[strcspn(input, "\n")] = 0;

        char *token = strtok(input, " ");
        int i = 0;
        while (token != NULL && i < 10 - 1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (i == 0) {
            continue;
        }

        pid_t pid = fork();

        if (pid < 0) {
            return 1;
        } else if (pid == 0) {
            execvp(args[0], args);
            return 1;
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
