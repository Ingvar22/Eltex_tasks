#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>

#define MAX_MSG_SIZE 256
#define MSG_TYPE_USER1 1
#define MSG_TYPE_USER2 2
#define TERMINATE_MSG_TYPE 255

struct msg_buffer {
    long msg_type;
    char msg_text[MAX_MSG_SIZE];
};

int main() {
    key_t key;
    int msg_id;
    struct msg_buffer message;

    
    key = ftok("chat", 'A');

    
    msg_id = msgget(key, 0666 | IPC_CREAT);

    if (msg_id == -1) {
        perror("msgget");
        exit(1);
    }

    printf("User 2 connected to chat.\n");

    while (1) {
        
        msgrcv(msg_id, &message, sizeof(message), MSG_TYPE_USER2, 0);
        printf("User 1 > %s\n", message.msg_text);

        
        if (strcmp(message.msg_text, "exit") == 0) {
            printf("User 1 has left the chat.\n");
            break;
        }

       
        printf("User 2 > ");
        fgets(message.msg_text, MAX_MSG_SIZE, stdin);

        
        message.msg_text[strcspn(message.msg_text, "\n")] = '\0';

        
        message.msg_type = MSG_TYPE_USER1;
        msgsnd(msg_id, &message, sizeof(message), 0);

        
        if (strcmp(message.msg_text, "exit") == 0) {
            printf("User 2 leaving chat...\n");
            
            message.msg_type = TERMINATE_MSG_TYPE;
            msgsnd(msg_id, &message, sizeof(message), 0);
            break;
        }
    }

    return 0;
}