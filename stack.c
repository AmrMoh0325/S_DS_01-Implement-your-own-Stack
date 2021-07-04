#include "stack.h"

stack_t *create_stack(uint32_t max_size)
{
    stack_t *s=(stack_t *) malloc(sizeof(stack_t));
    s->list=create_list();
    s->max_size=max_size;

    return s;
}

void delete_stack(stack_t *s)
{
    delete_list(s->list);
    free(s);
}


uint8_t push(stack_t *s,sint32_t value)
{
    if ((s->list->size)<(s->max_size))
    {
        list_add_node(s->list,create_node(value));
        return 1;
    }
    return 0;
}

uint8_t pull(stack_t *s,sint32_t *value_holder)
{
    if ((s->list->size)>0)
    {
        *value_holder=s->list->end->value;
        list_delete_node(s->list);
        return 1;
    }
    return 0;
}


void printStack(stack_t *s)
{
    if (s->list->size)
    {
        print_list(s->list);
        printf("Stack size= %d      Max size= %d\n\n",s->list->size,s->max_size);
    }
    else
    {
        printf("\nstack is empty!\n\n");
    }
}

uint32_t get_stack_Size(stack_t *s)
{
    return s->list->size;
}
