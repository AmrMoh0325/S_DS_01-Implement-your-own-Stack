#include <stdio.h>
#include <stdlib.h>

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "Data_Types.h"

//creates a pointer to a new list
list_t *create_list(void);

//creates a pointer to a new node that can be added to any list
node_t *create_node(sint32_t value);

// adds the provided node to the end of the provided list
uint32_t list_add_node(list_t *l,node_t *n);

// deletes the ending node of the provided list, returns 0 if the list is already empty
uint32_t list_delete_node(list_t *l);

// prints the provided list on console
void print_list(list_t *l);

// deletes the provided array
void delete_list (list_t *l);

#endif // LINKED_LIST_H_


