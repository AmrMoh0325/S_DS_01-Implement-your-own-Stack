
#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include "Data_Types.h"
#include "linked_list.h"

// creates a new stack
stack_t *create_stack(uint32_t max_size);

// deletes a stack
void delete_stack(stack_t *s);

//pushes a new element to the provided stack ... return: 1=pass 0=fail
uint8_t push(stack_t *s,sint32_t value);

//pops the last element of the provided stack and places its value in the value_holder ... return: 1=pass 0=fail
uint8_t pull(stack_t *s,sint32_t *value_holder);

//prints the provided stack
void printStack(stack_t *s);

//returns current number of elements in the provided stack
uint32_t get_stack_Size(stack_t *s);

#endif // STACK_H_
