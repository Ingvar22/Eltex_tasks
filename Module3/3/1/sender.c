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

    printf("Sender process started.\n");
    printf("Enter lines of text, terminate by entering 'exit':\n");

    
    while (1) {
        printf("> ");
        fgets(message.msg_text, MAX_MSG_SIZE, stdin);

        
        message.msg_text[strcspn(message.msg_text, "\n")] = '\0';

        
        message.msg_type = MSG_TYPE;
        msgsnd(msg_id, &message, sizeof(message), 0);

        
        if (strcmp(message.msg_text, "exit") == 0) {
            printf("Terminating sender process...\n");
            
            message.msg_type = TERMINATE_MSG_TYPE;
            msgsnd(msg_id, &message, sizeof(message), 0);
            break;
        }
    }

    
    msgctl(msg_id, IPC_RMID, NULL);

    return 0;
}