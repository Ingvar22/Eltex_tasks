#ifndef CONTACT_LIST_H
#define CONTACT_LIST_H

#include "contact_node.h"

typedef struct {
    ContactNode* head;
    int count;
} ContactList;

#endif