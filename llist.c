#include "llist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void llist_insert_head(struct node** head, struct node* n) {
    n->next = *head;
}


void llist_print(struct node* head) {
    printf("%d", head->value);
    if (head->next) {
        printf(" -> ");
        llist_print(head->next);
    } else
    {
        printf("\n");
    }
}


struct node* node_alloc(int value) {
    struct node* new_node = malloc(sizeof (struct node));
    new_node->value = value;
    new_node->next = NULL;

    return new_node;
}


void node_free(struct node* n) {
    free(n);
}


void test(void) {
    struct node* head = node_alloc(123);
    llist_print(head);

    struct node* new_head = node_alloc(456);
    llist_insert_head(&head, new_head);
    llist_print(new_head);
}


int main(int argc, char* argv[])
{
    struct node* head = NULL;

    test();
    exit(0);

    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "ih")) {
            if (i + 1 >= argc) printf("Command 'ih' missing requirement");
            i++;

            int value = atoi(argv[i]);

            struct node* new_node = node_alloc(value);
            // llist_insert_head(&head, new_node);
            head = new_node;
        } else if (strcmp(argv[i], "it")) {
            if (i + 1 >= argc) printf("Command 'it' missing requirement");
            i++;

            int value = atoi(argv[i]);

            struct node* new_node = node_alloc(value);
            // llist_insert_tail(&head, new_node);
        } else if (strcmp(argv[i], "dh")) {
            // struct node* old_head = llist_delete_head(&head);
            // node_free(old_head);
        } else if (strcmp(argv[i], "f")) {
            // llist_free(&head);
        } else if (strcmp(argv[i], "p")) {
            llist_print(head);
        }
    }
}


