#ifndef CONTACT_NODE_H
#define CONTACT_NODE_H

#include "full_name.h"
#include "contact_info.h"

typedef struct ContactNode {
    FullName name;
    ContactInfo info;
    struct ContactNode* next;
    struct ContactNode* prev;
} ContactNode;

#endif