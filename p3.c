//
//  main.c
//  p3
//
//  Created by Andrew Caldwell and Dan Stowe on 10/26/16.
//
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CMD_LENGTH 100

// void(print_list(NODE*);

struct node
{
    int val;
    struct node *next;
};

struct node *head = NULL;
struct node *curr = NULL;


struct node *create_list(int val)
{
    printf("Creating list with head as [%d]", val);
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    if (ptr == NULL)
        printf("Memory could not be allocated for node creation. Exit with error.\n"); exit(1);


    ptr->val = val;
    ptr->next = NULL;

    head = curr = ptr;
    return ptr;

}


int main(int argc, char *argv[])
{

    
    return 0;
}

/* void print_list(NODE *head)
{
    NODE *current = head;
    
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}
*/
