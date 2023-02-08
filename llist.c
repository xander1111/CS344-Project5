#include "llist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void llist_insert_head(struct node** head, struct node* n) {
    if (head == NULL) return;

    n->next = *head;
}


struct node* llist_delete_head(struct node** head) {
    if (*head == NULL) return NULL;
    struct node* new_head = (*head)->next;
    (*head)->next = NULL;
    return new_head;
}


void llist_insert_tail(struct node** head, struct node* n) {
    if (*head == NULL) {
        *head = n;
        return;
    }
    if ((*head)->next != NULL) llist_insert_tail(&(*head)->next, n);
    (*head)->next = n;
}


void llist_print(struct node* head) {
    if (head == NULL) {
        printf("[empty]\n");
        return;
    }

    printf("%d", head->value);
    if (head->next) {
        printf(" -> ");
        llist_print(head->next);
    } else
    {
        printf("\n");
    }
}


void llist_free(struct node** head) {
    if (*head == NULL) return;
    struct node* next_node = (*head)->next;
    node_free(*head);
    *head = NULL;
    if (next_node != NULL) llist_free(&next_node);
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
    printf("First node added:\n");
    llist_print(head);

    struct node* new_node = node_alloc(456);
    llist_insert_head(&head, new_node);
    head = new_node;
    printf("2nd node added:\n");
    llist_print(head);

    head = llist_delete_head(&head);
    printf("removed head:\n");
    llist_print(head);

    llist_insert_tail(&head, new_node);
    printf("added new tail:\n");
    llist_print(head);

    llist_free(&head);
    printf("freed list:\n");
    llist_print(head);

    head = NULL;
    new_node = node_alloc(123);

    llist_insert_head(&head, new_node);
    head = new_node;
    printf("added head to empty:\n");
    llist_print(head);

    llist_free(&head);

    head = NULL;
    new_node = node_alloc(123);

    llist_insert_tail(&head, new_node);
    printf("added tail to empty:\n");
    llist_print(head);

    llist_free(&head);
    printf("freed list:\n");
    llist_print(head);

    llist_free(&head);
    printf("freed list again:\n");
    llist_print(head);
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


