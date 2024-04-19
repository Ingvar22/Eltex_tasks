#include <stdio.h>
#include <dlfcn.h>

typedef void (*ArithmeticFunction)(int, int);

int main() {
    char action;
    int a, b;

    void *handle = dlopen("./liboperations.so", RTLD_LAZY);
    if (!handle) {
        printf("Ошибка: %s\n", dlerror());
        return 1;
    }

    ArithmeticFunction operation;
    while(1) {
        scanf("%d %c %d", &a, &action, &b);

        const char* functionName;
        switch (action) {
            case '+':
                functionName = "sum";
                break;
            case '-':
                functionName = "sub";
                break;
            case '*':
                functionName = "mul";
                break;
            case '/':
                functionName = "div";
                break;
            default:
                printf("Неверная операция!\n");
                continue;
        }

        operation = (ArithmeticFunction)dlsym(handle, functionName);
        if (!operation) {
            printf("Ошибка: %s\n", dlerror());
            dlclose(handle);
            return 1;
        }

        operation(a, b);
    }

    dlclose(handle);

    return 0;
}