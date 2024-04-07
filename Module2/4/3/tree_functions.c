#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contact_node.h"
#include "full_name.h"
#include "contact_info.h"

ContactNode* createContactNode(ContactInfo info) {
    ContactNode* newNode = (ContactNode*)malloc(sizeof(ContactNode));
    if (newNode == NULL) {
        printf("Ошибка: Не удалось выделить память для нового узла.\n");
        exit(EXIT_FAILURE);
    }
    newNode->info = info;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int compareContacts(FullName name1, FullName name2) {
    int lastNameComparison = strcmp(name1.lastName, name2.lastName);
    if (lastNameComparison != 0) {
        return lastNameComparison;
    }
    return strcmp(name1.firstName, name2.firstName);
}

void addContactToTree(ContactNode** root, ContactInfo info) {
    if (*root == NULL) {
        *root = createContactNode(info);
    } else {
        if (compareContacts(info.name, (*root)->info.name) < 0) {
            addContactToTree(&((*root)->left), info);
        } else {
            addContactToTree(&((*root)->right), info);
        }
    }
}


ContactNode* findMin(ContactNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

void deleteContactFromTree(ContactNode** root, FullName name) {
    if (*root == NULL) {
        return;
    }

    if (compareContacts(name, (*root)->info.name) < 0) {
        deleteContactFromTree(&((*root)->left), name);
    } else if (compareContacts(name, (*root)->info.name) > 0) {
        deleteContactFromTree(&((*root)->right), name);
    } else {
        if ((*root)->left == NULL) {
            ContactNode* temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            ContactNode* temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            ContactNode* temp = findMin((*root)->right);
            (*root)->info = temp->info;
            deleteContactFromTree(&((*root)->right), temp->info.name);
        }
    }
}

void printContact(ContactInfo info) {
    printf("Имя: %s %s\n", info.name.firstName, info.name.lastName);
    printf("Должность: %s\n", info.jobTitle);
    printf("Место работы: %s\n", info.workplace);
    printf("Номер телефона: %s\n", info.phone);
    printf("Email: %s\n", info.email);
    printf("Ссылка на соцсети: %s\n", info.socialMedia);
    printf("Профиль в мессенджере: %s\n", info.messenger);
    printf("\n");
}

void printTree(ContactNode* root) {
    if (root != NULL) {
        printTree(root->left);
        printContact(root->info);
        printTree(root->right);
    }
}

void freeTree(ContactNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void displayMenu() {
    printf("\nМеню:\n");
    printf("1. Добавить контакт\n");
    printf("2. Удалить контакт\n");
    printf("3. Вывести список контактов\n");
    printf("4. Выйти\n");
    printf("Выберите действие (1-4): ");
}