#ifndef CONTACT_NODE_H
#define CONTACT_NODE_H

#include "contact_info.h"

typedef struct ContactNode {
    ContactInfo info;
    struct ContactNode* left;
    struct ContactNode* right;
} ContactNode;

#endif