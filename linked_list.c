
#include "linked_list.h"

list_t *create_list(void)
{
    list_t *l=(list_t *)malloc(sizeof(list_t));
    l->head = NULL;
    l->end = NULL;
    l->size=0;
    return l;
}

node_t *create_node(sint32_t value)
{
    node_t *n=(node_t *)malloc(sizeof(node_t));
    n->Next=NULL;
    n->Previous=NULL;
    n->value=value;
    return n;
}

uint32_t list_add_node(list_t *l,node_t *n)
{
    if (l->size==0)
    {
        l->head=n;
        l->end=n;
    }
    else
    {
        n->Previous=l->end;
        l->end->Next=n;
        l->end=n;
    }
    l->size++;
    return l->size;
}


uint32_t list_delete_node(list_t *l)
{
    node_t *temp;
    if (l->size==0)         return 0;
    else if(l->size==1)
    {
        temp=l->end;
        l->head=NULL;
        l->end=NULL;
    }
    else
    {
        temp=l->end;
        l->end=temp->Previous;
        l->end->Next=NULL;
    }
    l->size--;
    free(temp);
    return 1;
}

void print_list(list_t *l)
{
    node_t *temp;
    if (l->size==0)
    {
        printf("\nList is empty!\n");
        return 0;
    }
    else
    {
        temp=l->head;
        printf("\n");
        for (;temp;)
        {
            printf("%d, ",temp->value);
            temp=temp->Next;
        }
        printf("\n");
    }
    return 1;
}


void delete_list (list_t *l)
{
    for (;l->size;)
    {
        list_delete_node(l);
    }
    free(l);
}
