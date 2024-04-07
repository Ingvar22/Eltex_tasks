#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contact_node.h"
#include "full_name.h"
#include "contact_info.h"
#include "tree_functions.h"

int main() {
    ContactNode* root = NULL;
    ContactInfo info;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                printf("Введите имя: ");
                scanf("%s", info.name.firstName);
                printf("Введите фамилию: ");
                scanf("%s", info.name.lastName);
                printf("Введите должность: ");
                scanf("%s", info.jobTitle);
                printf("Введите место работы: ");
                scanf("%s", info.workplace);
                printf("Введите номер телефона: ");
                scanf("%s", info.phone);
                printf("Введите email: ");
                scanf("%s", info.email);
                printf("Введите ссылку на соцсети: ");
                scanf("%s", info.socialMedia);
                printf("Введите профиль в мессенджере: ");
                scanf("%s", info.messenger);
                addContactToTree(&root, info);
                break;
            case 2:
                printf("Введите имя для удаления: ");
                scanf("%s", info.name.firstName);
                printf("Введите фамилию для удаления: ");
                scanf("%s", info.name.lastName);
                deleteContactFromTree(&root, info.name);
                break;
            case 3:
                printf("Список контактов:\n");
                printTree(root);
                break;
            case 4:
                printf("Выход из программы.\n");
                break;
            default:
                printf("Неверный выбор. Пожалуйста, выберите от 1 до 4.\n");
        }
    } while (choice != 4);

    freeTree(root);

    return 0;
}