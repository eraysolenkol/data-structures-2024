#include <stdio.h>
#include <stdlib.h>
#define INT_SIZE 4

typedef struct node_t
{
    int data;
    struct node_t* next;
} node;

node* create_linked_list();
void add(node** list, int data);
void add_from_array(node** list, int* array, int array_size);
int get_linked_list_size(node* list);
void print_linked_list(node* list);
int pop(node** list);

void tests();

void main() {
    tests();
}

node* create_linked_list() {
    node* list = NULL;
    return list;
}

void add(node** list, int data) {
    if (*list == NULL) {
        *list = calloc(1, sizeof(node));
        (*list)->data = data;
        (*list)->next = NULL;
        return;
    }
    node* new_element = calloc(1,sizeof(node));
    node* iter = *list;
    while (iter->next != NULL)
    {
        iter = iter->next;
    }
    new_element->data = data;
    new_element->next = NULL;
    iter->next = new_element;
}

void add_from_array(node** list, int* array, int array_size) {
    if (array_size < 1) {
        return;
    } 
    if (*list == NULL) {
        *list = calloc(1,sizeof(node));
        (*list)->data = array[0];
        (*list)->next = NULL;
        node* iter = *list;
        for (int i = 1; i < array_size; i++) {
            node* new_element = calloc(1, sizeof(node));
            iter->next = new_element;
            new_element->data = array[i];
            new_element->next = NULL;
            iter = iter->next;
        }
        return;
    }
    node* iter = *list;
    while (iter->next != NULL)
    {
        iter = iter->next;
    }
    for (int i = 0; i < array_size; i++) {
        node* new_element = calloc(1, sizeof(node));
        iter->next = new_element;
        new_element->data = array[i];
        new_element->next = NULL;
        iter = iter->next;
    }
}

int get_linked_list_size(node* list) {
    int size = 0;
    while (list != NULL) {
        size++;
        list = list->next;
    }
    return size;
}

void print_linked_list(node* list) {
    node* iter = list;
    int size = get_linked_list_size(list);
    printf("LinkedList[%d] [", size);
    while (iter != NULL) {
        if (iter->next == NULL) {
            printf("%d", iter->data);
        } else {
            printf("%d,", iter->data);
        }
        iter = iter->next;
    }
    printf("]\n");
}

int pop(node** list) {
    int val = -1;
    if (*list == NULL) {
        return val;
    }

    if ((*list)->next == NULL) {
        val = (*list)->data;
        free((*list));
        (*list) = NULL;
        return val;
    }
    node* iter = *list;
    while (iter->next->next != NULL) {
        iter = iter->next;
    }
    node* element = iter->next;
    val = element->data;
    free(element);
    iter->next = NULL;
    return val;
}

void tests() {
    node* list = create_linked_list();
    add(&list,5);
    add(&list,4);
    add(&list,3);
    add(&list,2);
    add(&list,1);
    print_linked_list(list);
    int array[5] = {1,9,2,123,12};
    add_from_array(&list, array, sizeof(array) / INT_SIZE);
    print_linked_list(list);
    add(&list,1);
    print_linked_list(list);
    node* list2 = create_linked_list();
    add_from_array(&list2, array, sizeof(array) / INT_SIZE);
    print_linked_list(list2);
    add(&list2,55);
    print_linked_list(list2);
    pop(&list2);
    print_linked_list(list2);
    pop(&list2);
    print_linked_list(list2);
    pop(&list2);
    pop(&list2);
    pop(&list2);
    print_linked_list(list2);
    pop(&list2);
    print_linked_list(list2);
    add_from_array(&list2, array, sizeof(array) / INT_SIZE);
    print_linked_list(list2);
    add_from_array(&list2, array, sizeof(array) / INT_SIZE);
    print_linked_list(list2);
}


