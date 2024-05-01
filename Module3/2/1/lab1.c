#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    int num_numbers = atoi(argv[1]);

    int fd[2]; 
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) { 
        close(fd[0]); 
        srand(getpid()); 

        for (int i = 0; i < num_numbers; ++i) {
            int random_number = rand() % 100; 
            if (write(fd[1], &random_number, sizeof(random_number)) == -1) {
                perror("write");
                return 1;
            }
        }

        close(fd[1]); 
        return 0;
    } else { 
        close(fd[1]); 

        FILE *output_file = fopen("numbers.txt", "w");
        if (output_file == NULL) {
            perror("fopen");
            return 1;
        }

        int received_number;
        while (read(fd[0], &received_number, sizeof(received_number)) > 0) {
            printf("%d\n", received_number);
            fprintf(output_file, "%d\n", received_number);
        }

        fclose(output_file);
        close(fd[0]); 

        wait(NULL); 
    }

    return 0;
}
