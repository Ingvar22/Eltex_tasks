#include <stdio.h>
#include "rec_struct.h"
// #include "add_function.h"
// #include "delete_function.h"
// #include "edit_function.h"
// #include "display_records.h"

#include "dir_functions.h"

int main() {
    int n;
    int cnt = 0;
    printf("Введите количество записей: ");
    scanf("%d", &n);
    struct Person dir[n];
    int action;
    int num_rec;
    while (1) {
        printf("1) Редактировать;\n2) Добавить;\n3) Удалить;\n4) Отобразить записи в справочнике;\nВыберите действие: ");
        scanf("%d", &action);

        switch(action) {
            case 1: 
                printf("Введите номер записи для редактирования: ");
                scanf("%d", &num_rec);
                if (num_rec >= 0 && num_rec < n && !(num_rec > cnt))
                    edit_rec(dir, num_rec, n);
                else
                    printf("Недопустимый номер записи.\n");
                break;
            case 2:
                add_rec(dir, &cnt, n);
                break;
            case 3: 
                printf("Введите номер записи для удаления: ");
                scanf("%d", &num_rec);
                if (num_rec >= 0 && num_rec < n)
                    delete_rec(dir, num_rec, &cnt, n);
                else
                    printf("Недопустимый номер записи.\n");
                break;
            case 4:
                display_records(dir, cnt);
                break;
            default:
                printf("Неверный выбор.\n");
                break;
        }
    }

    return 0;
}