#ifndef TREE_FUNCTIONS_H
#define TREE_FUNCTIONS_H

#include "contact_node.h"
#include "full_name.h"
#include "contact_info.h"

ContactNode* createContactNode(ContactInfo info);
int compareContacts(FullName name1, FullName name2);
void addContactToTree(ContactNode** root, ContactInfo info);
ContactNode* findMin(ContactNode* node);
void deleteContactFromTree(ContactNode** root, FullName name);
void printContact(ContactInfo info);
void printTree(ContactNode* root);
void freeTree(ContactNode* root);
void displayMenu();

#endif