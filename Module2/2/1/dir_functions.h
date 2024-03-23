#ifndef DIR_FUNCTIONS_H
#define DIR_FUNCTIONS_H

#include "rec_struct.h"

void edit_rec(struct Person dir[], int num_rec, int n);
void display_records(struct Person dir[], int cnt);
void add_rec(struct Person dir[], int *cnt, int n);
void delete_rec(struct Person dir[], int num_rec, int *cnt, int n);
 
#endif