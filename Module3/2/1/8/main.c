#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define FILE_ACCESS_BLOCK SIGUSR1
#define FILE_ACCESS_PERMISSION SIGUSR2

volatile sig_atomic_t file_access_flag = 0;

void file_access_handler(int signal) {
    if (signal == FILE_ACCESS_BLOCK) {
            file_access_flag = 1;
        } else if (signal == FILE_ACCESS_PERMISSION) {
            file_access_flag = 0;
    }
}

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

        signal(FILE_ACCESS_BLOCK, file_access_handler);
        signal(FILE_ACCESS_PERMISSION, file_access_handler);

        while (1) {
            
            while (file_access_flag == 1);

            FILE *input_file = fopen("numbers.txt", "r");
            if (input_file == NULL) {
                perror("fopen");
                return 1;
            }

            int number;
            while (fscanf(input_file, "%d", &number) == 1) {
                printf("Child Process Read: %d\n", number);
            }

            fclose(input_file);

            
            int random_number = rand() % 100;
            if (write(fd[1], &random_number, sizeof(random_number)) == -1) {
                perror("write");
                return 1;
            }

            
            kill(getppid(), FILE_ACCESS_BLOCK);
        }
    } else { 
        close(fd[1]); 

        signal(FILE_ACCESS_BLOCK, file_access_handler);
        signal(FILE_ACCESS_PERMISSION, file_access_handler);

        FILE *output_file = fopen("numbers.txt", "w");
        if (output_file == NULL) {
            perror("fopen");
            return 1;
        }

        while (1) {
            
            while (file_access_flag == 0);

            
            int received_number;
            while (read(fd[0], &received_number, sizeof(received_number)) > 0) {
                printf("Parent Process Received: %d\n", received_number);
                fprintf(output_file, "%d\n", received_number);
            }

           
            kill(pid, FILE_ACCESS_PERMISSION);
        }

        fclose(output_file);
        close(fd[0]);

        wait(NULL);
    }

    return 0;
}