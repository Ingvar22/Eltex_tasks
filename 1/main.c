#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contact_list.h"
#include "list_contact.h"
#include "display_menu.h"
#include "create_contact.h"

void flushInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int main() {
    ContactList list;
    initializeList(&list);
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        flushInputBuffer(); 


        switch (choice) {
            case 1: {
                char firstName[50], lastName[50], jobTitle[100], workplace[100], phone[20], email[100], socialMedia[100], messenger[100];
                printf("Введите имя: ");
                fgets(firstName, sizeof(firstName), stdin);
                firstName[strcspn(firstName, "\n")] = 0; 
                printf("Введите фамилию: ");
                fgets(lastName, sizeof(lastName), stdin);
                lastName[strcspn(lastName, "\n")] = 0; 
                printf("Введите должность: ");
                fgets(jobTitle, sizeof(jobTitle), stdin);
                jobTitle[strcspn(jobTitle, "\n")] = 0; 
                printf("Введите место работы: ");
                fgets(workplace, sizeof(workplace), stdin);
                workplace[strcspn(workplace, "\n")] = 0; 
                printf("Введите номер телефона: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = 0; 
                printf("Введите email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; 
                printf("Введите ссылку на соцсети: ");
                fgets(socialMedia, sizeof(socialMedia), stdin);
                socialMedia[strcspn(socialMedia, "\n")] = 0; 
                printf("Введите профиль в мессенджере: ");
                fgets(messenger, sizeof(messenger), stdin);
                messenger[strcspn(messenger, "\n")] = 0; 

                ContactNode* newContact = createContact(firstName, lastName, jobTitle, workplace, phone, email, socialMedia, messenger);
                addContactToList(&list, newContact);
                break;
            }
            case 2: {
                char lastName[50];
                printf("Введите фамилию контакта для удаления: ");
                fgets(lastName, sizeof(lastName), stdin);
                lastName[strcspn(lastName, "\n")] = 0; 
                deleteContactFromList(&list, lastName);
                break;
            }
            case 3: {
                printList(&list);
                break;
            }
            case 4: {
                printf("Программа завершена.\n");
                freeList(&list);
                break;
            }
            default:
                printf("Неверный выбор. Пожалуйста, выберите от 1 до 4.\n");
        }
    } while (choice != 4);

    return 0;
}
