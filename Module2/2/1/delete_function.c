#include <stdio.h>
#include "delete_function.h"

void delete_rec(struct Person dir[], int num_rec, int *cnt, int n) {
    for(int i = num_rec; i < n - 1; ++i) {
        dir[i] = dir[i+1];
    }
    --(*cnt);
}