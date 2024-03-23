#include <stdio.h>
#include "dir_functions.h"

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

void delete_rec(struct Person dir[], int num_rec, int *cnt, int n) {
    for(int i = num_rec; i < n - 1; ++i) {
        dir[i] = dir[i+1];
    }
    --(*cnt);
}

void edit_rec(struct Person dir[], int num_rec, int n) {
    printf("Введите новую фамилию: ");
    scanf("%s", dir[num_rec].name_person.last_name);
    printf("Введите новое имя: ");
    scanf("%s", dir[num_rec].name_person.first_name);
    printf("Введите новое отчество: ");
    scanf("%s", dir[num_rec].name_person.surname);
    printf("Введите новое место работы: ");
    scanf("%s", dir[num_rec].job_place);
    printf("Введите новый адрес электронной почты: ");
    scanf("%s", dir[num_rec].inf_person.email);
    printf("Введите новую ссылку на страницу в соцсетях: ");
    scanf("%s", dir[num_rec].inf_person.social);
    printf("Введите новый профиль в мессенджере: ");
    scanf("%s", dir[num_rec].inf_person.messenger);
    printf("Введите номер телефона: ");
    scanf("%s", dir[num_rec].inf_person.phone);
}
