#include <stdio.h> 
#include "sub.h"
#include "sum.h"
#include "mul.h"
#include "div.h"


void* load_function(void (*function)(int, int)) {
    return *function;
}

void (*load_function2(char action))(int, int) {
    switch (action)
    {
        case '+':
            return sum;
            break;
        case '-':
            return sub;
            break;
        case '*':
            return mul;
            break;
        case '/':
            return div;
            break;
        default:
            return NULL;
    }
}

int main() {
    char action;
    int a;
    int b;
    void (*functions[])(int, int) = {sum, sub, mul, div};
    void (*function)(int, int);
    char operations_name[] = { '+', '-', '*', '/'};
    int action_id;
    while(1) {
        scanf("%d %c %d", &a, &action, &b);
        // for(int i = 0; i < 4; ++i) {
        //     if(action == operations_name[i]) {
        //         action_id = i;
        //         break;
        //     }
        // }
        // switch (action)
        // {
        //     case '+':
        //         load_function(sum, a, b);
        //         break;
        //     case '-':
        //         load_function(sub, a, b);
        //         break;
        //     case '*':
        //         load_function(mul, a, b);
        //         break;
        //     case '/':
        //         load_function(div, a, b);
        //         break;
        // }
        // function = load_function(functions[action_id]);
        // function(a, b);
        function = load_function2(action);
        if(function != NULL) {
            function(a, b);
        } else {
            printf("Invalid operation!\n");
        }
    }

    return 0;
}