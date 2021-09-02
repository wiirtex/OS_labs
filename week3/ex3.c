#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next_node;
} typedef node;

struct linked_list {
    node* head;
} typedef linked_list;

int init(linked_list* a) {
    if (a == NULL) {
        return 1;
    }
    a->head = (node*)malloc(sizeof(node));
    a->head->data = 0;
    a->head->next_node = NULL;
    return 0;
}

int print(linked_list* a)
{
    if (a == NULL || a->head == NULL) {
        return 1;
    }
    node* now = a->head->next_node;
    while (1)
    {
        if (now == NULL)
        {
            break;
        }
        printf("%d ", now->data);
        now = now->next_node;
    }
    printf("\n");
    return 0;
}

int insert_node(linked_list* a, int n)
{
    if (a == NULL || a->head == NULL) {
        return 1;
    }
    node* now = a->head;
    while (1) {
        if (now->next_node == NULL) {
            now->next_node = (node*)malloc(sizeof(node));
            now->next_node->data = n;
            now->next_node->next_node = NULL;
            return 0;
        }
        now = now->next_node;
    }
}

int delete_node(linked_list* a, int n)
{
    if (a == NULL || a->head == NULL) {
        return 1;
    }
    node* now = a->head;
    while (1)
    {
        if (now->next_node == NULL)
        {
            return 1;
        }
        if (now->next_node->data == n && now->next_node->next_node != NULL)
        {
            node * c = now->next_node->next_node;
            free(now->next_node);
            now->next_node = c;
            return 0;
        }
        now = now->next_node;
    }
    return 0;
}

int main()
{
    linked_list a;
    init(&a);
    print(&a);
    insert_node(&a, 2);
    print(&a);
    insert_node(&a, 1);
    print(&a);
    delete_node(&a, 1000);
    print(&a);
    delete_node(&a, 1);
    print(&a);
    delete_node(&a, 2);
    print(&a);
}

