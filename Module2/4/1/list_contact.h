#ifndef LIST_CONTACT_H
#define LIST_CONTACT_H

#include "contact_list.h"
#include "contact_node.h"

void initializeList(ContactList* list);
void addContactToList(ContactList* list, ContactNode* newContact);
void deleteContactFromList(ContactList* list, char* lastName);
void printList(ContactList* list);
void freeList(ContactList* list);

#endif