#ifndef REC_STRUCT_H
#define REC_STRUCT_H

#include "struct_inf.h"
#include "struct_name.h"

struct Person{
    struct full_name name_person;
    char job_place[100];
    struct inf inf_person;
};

#endif