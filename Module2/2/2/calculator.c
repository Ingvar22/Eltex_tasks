#include <stdio.h>
#include "sub.h"
#include "mul.h"
#include "div.h"
#include "sum.h"

int main() {
    while(1) {
        char action;
        int a;
        int b;
        scanf("%d %c %d", &a, &action, &b);
        switch(action) {
            case '+':
                sum(a, b);
                break;
            case '-':
                sub(a, b);
                break;            
            case '/':
                div(a, b);
                break;
            case '*':
                mul(a, b);
                break;
        }
    }
    return 0;
}