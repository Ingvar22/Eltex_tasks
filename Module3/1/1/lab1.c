#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

    pid_t pid = fork();

    if(pid == 0) {
        printf("%d, %d\n", atoi(argv[1]), atoi(argv[2]));
        return 0;
    } else {
        printf("%d, %d\n", atoi(argv[1]), atoi(argv[2]));
    }
    return 0;
}