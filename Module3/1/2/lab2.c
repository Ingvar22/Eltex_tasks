#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

double square(double x) {
    return x*x;
}

int main(int argc, char* argv[]) {
    pid_t pid = fork();
    if(pid == 0) {
        printf("2: %.2f\n", square(atoi(argv[1])));
    } else {
        printf("1: %.2f\n", square(atoi(argv[1])));
    }
}
