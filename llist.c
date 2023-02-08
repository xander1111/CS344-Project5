#include "llist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node* node_alloc(int value) {
    struct node* new_node = malloc(sizeof (struct node));
    new_node->value = value;
    new_node->next = NULL;

    return new_node;
}


void node_free(struct node* n) {
    free(n);
}


int main(int argc, char* argv[])
{
    struct node* head = NULL;

    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "ih")) {
            if (i + 1 >= argc) printf("Command 'ih' missing requirement");
            i++;

            int value = atoi(argv[i]);

            struct node* new_node = node_alloc(value);
            llist_insert_head(&head, new_node);
            head = new_node;
        } else if (strcmp(argv[i], "it")) {
            if (i + 1 >= argc) printf("Command 'it' missing requirement");
            i++;

            int value = atoi(argv[i]);

            struct node* new_node = node_alloc(value);
            llist_insert_tail(&head, new_node);
        } else if (strcmp(argv[i], "dh")) {
            struct node* old_head = llist_delete_head(&head);
            node_free(old_head);
        } else if (strcmp(argv[i], "f")) {
            llist_free(&head);
        } else if (strcmp(argv[i], "p")) {
            llist_print(head);
        }
    }
}


