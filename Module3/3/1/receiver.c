#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>

#define MAX_MSG_SIZE 256
#define MSG_TYPE 1
#define TERMINATE_MSG_TYPE 255

struct msg_buffer {
    long msg_type;
    char msg_text[MAX_MSG_SIZE];
};

int main() {
    key_t key;
    int msg_id;
    struct msg_buffer message;

    key = ftok("sender.c", 'A');

    
    msg_id = msgget(key, 0666 | IPC_CREAT);

    if (msg_id == -1) {
        perror("msgget");
        exit(1);
    }

    printf("Receiver process started.\n");

    
    while (1) {
        
        msgrcv(msg_id, &message, sizeof(message), MSG_TYPE, 0);

        
        if (message.msg_type == TERMINATE_MSG_TYPE) {
            printf("Terminating receiver process...\n");
            break;
        }

        
        printf("Received: %s\n", message.msg_text);
    }

    return 0;
}

