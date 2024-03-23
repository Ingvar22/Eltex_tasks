#include <stdio.h>
#include "display_records.h"

void display_records(struct Person dir[], int cnt) {
    if(cnt == 0) printf("В справочнике нет записей.\n");
    else {
        printf("\n\nСписок контактов:\n");
        for (int i = 0; i < cnt; ++i) {
            printf("Запись %d:\n", i + 1);
            printf("Фамилия: %s\n", dir[i].name_person.last_name);
            printf("Имя: %s\n", dir[i].name_person.first_name);
            printf("Отчество: %s\n", dir[i].name_person.surname);
            printf("Место работы: %s\n", dir[i].job_place);
            printf("Адрес электронной почты: %s\n", dir[i].inf_person.email);
            printf("Ссылка на страницу в соцсетях: %s\n", dir[i].inf_person.social);
            printf("Профиль в мессенджере: %s\n", dir[i].inf_person.messenger);
            printf("Номер телефона: %s\n", dir[i].inf_person.phone);
            printf("\n");
        } 
    }
}