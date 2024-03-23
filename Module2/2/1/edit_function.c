#include <stdio.h>
#include "edit_function.h"
#include "rec_struct.h"

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
