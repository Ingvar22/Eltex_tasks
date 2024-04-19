#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact_node.h"

ContactNode* createContact(char* firstName, char* lastName, char* jobTitle, char* workplace, char* phone, char* email, char* socialMedia, char* messenger) {
    ContactNode* newNode = (ContactNode*)malloc(sizeof(ContactNode));
    strcpy(newNode->name.firstName, firstName);
    strcpy(newNode->name.lastName, lastName);
    strcpy(newNode->info.jobTitle, jobTitle);
    strcpy(newNode->info.workplace, workplace);
    strcpy(newNode->info.phone, phone);
    strcpy(newNode->info.email, email);
    strcpy(newNode->info.socialMedia, socialMedia);
    strcpy(newNode->info.messenger, messenger);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
