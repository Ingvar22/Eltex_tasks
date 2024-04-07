#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact_list.h"
#include "contact_node.h"

void initializeList(ContactList* list) {
    list->head = NULL;
    list->count = 0;
}

void addContactToList(ContactList* list, ContactNode* newContact) {
    if (list->head == NULL) {
        list->head = newContact;
    } else {
        newContact->next = list->head;
        list->head->prev = newContact;
        list->head = newContact;
    }
    list->count++;
}

void deleteContactFromList(ContactList* list, char* lastName) {
    ContactNode* current = list->head;
    while (current != NULL) {
        if (strcmp(current->name.lastName, lastName) == 0) {
            if (current == list->head) {
                list->head = current->next;
                if (list->head != NULL) {
                    list->head->prev = NULL;
                }
            } else {
                current->prev->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
            }
            free(current);
            list->count--;
            printf("Контакт с фамилией %s удален.\n", lastName);
            return;
        }
        current = current->next;
    }
    printf("Контакт с фамилией %s не найден.\n", lastName);
}

void printList(ContactList* list) {
    ContactNode* current = list->head;
    if (current == NULL) {
        printf("Список контактов пуст.\n");
        return;
    }
    printf("Список контактов:\n");
    while (current != NULL) {
        printf("Имя: %s, Фамилия: %s\n", current->name.firstName, current->name.lastName);
        printf("Должность: %s\n", current->info.jobTitle);
        printf("Место работы: %s\n", current->info.workplace);
        printf("Номер телефона: %s\n", current->info.phone);
        printf("Email: %s\n", current->info.email);
        printf("Ссылка на соцсети: %s\n", current->info.socialMedia);
        printf("Профиль в мессенджере: %s\n", current->info.messenger);
        printf("\n");
        current = current->next;
    }
}

void freeList(ContactList* list) {
    ContactNode* current = list->head;
    ContactNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->count = 0;
}