#ifndef CONTACT_INFO_H
#define CONTACT_INFO_H

#include "full_name.h"

typedef struct {
    FullName name;
    char jobTitle[100];
    char workplace[100];
    char phone[20];
    char email[100];
    char socialMedia[100];
    char messenger[100];
} ContactInfo;

#endif