#include <stdio.h>
#include "add_function.h"

void add_rec(struct Person dir[], int *cnt, int n) {
    if (*cnt < n) {
        printf("Введите фамилию: ");
        scanf("%s", dir[*cnt].name_person.last_name);
        printf("Введите имя: ");
        scanf("%s", dir[*cnt].name_person.first_name);
        printf("Введите отчество: ");
        scanf("%s", dir[*cnt].name_person.surname);
        printf("Введите место работы: ");
        scanf("%s", dir[*cnt].job_place);
        printf("Введите адрес электронной почты: ");
        scanf("%s", dir[*cnt].inf_person.email);
        printf("Введите ссылку на страницу в соцсетях: ");
        scanf("%s", dir[*cnt].inf_person.social);
        printf("Введите профиль в мессенджере: ");
        scanf("%s", dir[*cnt].inf_person.messenger);
        printf("Введите номер телефона: ");
        scanf("%s", dir[*cnt].inf_person.phone);
        (*cnt)++;
    } else {
        printf("Достигнуто максимальное количество записей.\n");
    }
}