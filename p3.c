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
#include <ctype.h>

#define MAX_CMD_LENGTH 4

// void(print_list(NODE*);

typedef struct node
{
    int count;
    char symbol;
    //int *val = 0;
    struct node *next;
} Node;

typedef struct ListTag
{
    struct NodeTag *first;
} List;

Node *head = NULL;
Node *curr = NULL;


/* Prototypes for functions of a linked list */
Node *create_list(char[]);      // prototype for create_list function
Node *insert(int*, char*);
Node *search(char*, struct node**);
List *List_create();
void List_append(List*, char*);
Node *Node_create(void);


int main(int argc, char *argv[])
{
    List *list = List_create();
    char commandString[MAX_CMD_LENGTH];
    int numValue;
    char dataString[10];
    printf("Command? ");
    scanf("%s %s", commandString, dataString);
    
    if (isdigit(dataString[0]))
        numValue = atoi(dataString);
    else
        create_list(dataString);
    while (1)
    {
    if (strcmp(commandString, "ins") == 0)
    {
        List_append(list, dataString);
        printf("[%s] has been added to the list!", dataString);
        
    }
    else if (strcmp(commandString, "end") == 0)
             break;
    }
    
    return 0;
}


/* Creates a list if none exist. */

List *List_create(void) {
    List *list = malloc(sizeof(List));
    if (list != NULL)
        printf("Memory Allocation Failed."); exit(1);
    
    
    Node *node = Node_create();
    list->first = node;
    
    return list;
    
}


/* Inserts a new node into the list the linked list. If the value already exists     */
/* within the linked list the count will be incremented for the node with            */
/* said value. The list is then sorted in descending order from highest count value. */


void List_append(List *list, char *str)
{
    assert(list != NULL);
    assert(str != NULL);
        
    Node *node = list->first;
    while (node->next != NULL)
    {
        node = node->next;
    }
        
    node->symbol = *str;
    node->next = Node_create();
}


Node *Node_create(void) {
    Node *node = malloc(sizeof(Node));
    assert(node != NULL);
    
    node->data = "";
    node->next = NULL;
    
    return node;
}



/* Search function to traverse the linked list to find a node with a specified */
/* value and return it.                                                        */
/*Node *search(char val[], Node **prev)
{
    struct node *ptr = head;
    struct node *tmp = NULL;
    int found = 0;
    
    printf("\nSearching for the list for value [%s] \n", val);
    
    while(ptr != NULL)
    {
        if (strcmp(&ptr->symbol, val) == 0)
            {
        found = 1;
            break;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
    }
    
    if (found == 1)
    {
        if(prev)
            *prev = tmp;
        return ptr;
    }
    else
        return NULL;
}
*/

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
