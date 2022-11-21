//
// Created by jplop on 20/11/2022.
//

#include "Lists.h"

typedef struct node
{
    void *element;
    struct node *next;
}Node;

struct list
{
    Node *head;
};

Node* node_new(void *value)
{
    Node *new = malloc(sizeof (Node));
    new->element = value;
    new->next = NULL;
    return new;
}

List* list_new()
{
    List *new = malloc(sizeof (List));
    new->head = NULL;
    return new;
}

List* list_append(List *l,void *element)
{
    if(l->head == NULL)
    {
        l->head = node_new(element);
        return l;
    }

    Node *current = l->head;

    while (current->next != NULL)
        current = current->next;

    current->next = node_new(element);
    return l;
}

void delete_at(List *l, int index)
{
    if(index == 0)
    {
        // queremos borrar head
        Node *to_delete = l->head;
        l->head = l->head->next;
        free(to_delete);
        return;
    }
    Node *current = l->head;
    for(int i=0; i < index - 1; i++)
    {
        if(current->next == NULL)
            return; // el indice no es valido
        current = current->next;
    }

    Node *to_delete = current->next;
    current->next = current->next->next;
    free(to_delete);
}

void* get_element(List *l, int index)
{
    if(index == 0)
    {
        // queremos borrar head
        Node *to_return = l->head->element;
        l->head = l->head->next;
        return to_return;
    }
    Node *current = l->head;
    for(int i=0; i < index - 1; i++)
    {
        if(current->next == NULL)
            return NULL; // el indice no es valido
        current = current->next;
    }

    Node *to_return = current->next->element;

    return to_return;
}

//int list_contains(List *l, int value_to_find)
//{
//    Node *current = (*l).head;
////    for (Node *current = (*l).head; current != NULL; current = (*current).next) {
////        if((*current).value == value_to_find)
////            return 1;
////    }
//    while (current)
//    {
//        if((*current).value == value_to_find)
//            return 1;
//        current = (*current).next;
//    }
//    return 0;
//}
