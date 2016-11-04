//
//  main.c
//  p3
//
//  Created by Andrew Caldwell and Dan Stowe on 10/26/16.
//
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CMD_LENGTH 4
#define MAX_STRING_LENGTH 11

// self-referential structure
struct listNode {
    int count;
    char data[10]; // each listNode contains a character
    struct listNode *nextPtr; // pointer to next node
    struct listNode *lastPtr;
};

typedef struct listNode ListNode; // synonym for struct listNode
typedef ListNode *ListNodePtr; // synonym for ListNode*

// prototypes
void insert(ListNodePtr*, char[]);
char delete(ListNodePtr*, char[]);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);
//void move(ListNodePtr, ListNodePtr);

int counter = 0;

int main(void)
{
    ListNodePtr startPtr = NULL; // initially there are no nodes
    char *item[11]; // char entered by user
    char command[5];
    
    do {
        instructions(); // ask for a command

        
        
        if (strcmp(command, "prl") == 0)
            printList(startPtr);
       
        if ((strcmp(command, "ins") == 0) || strcmp(command, "del"))
            scanf(" %s", *item);
        
        
        if (strcmp(command, "ins") == 0) {
            insert(&startPtr, *item); // insert item in list
            printList(startPtr);
            printf("Counter: %d\n", counter);
        }
        if (strcmp(command, "del") == 0) {
            // delete an element
            // if list is not empty
            
                // if character is found, remove it
                
            if (delete(&startPtr, *item)) { // remove item
                printf("%s deleted.\n", *item);
                printList(startPtr);
            }

        }
    } while (strcmp(command, "end") != 0);
    
    puts("End of run.");
}

// display program instructions to user
void instructions(void)
{
    printf("Command? ");
}

// insert a new value into the list
void insert(ListNodePtr *sPtr, char value[])
{
    ListNodePtr newPtr = malloc(sizeof(ListNode)); // create node

    if (newPtr != NULL) { // is space available
        strcpy(newPtr->data, value); // place string value in node
        newPtr->nextPtr = NULL; // node does not link to another node
        //counter++;
        ListNodePtr previousPtr = NULL;
        ListNodePtr currentPtr = *sPtr;
       // ListNodePtr tmp = NULL;
       
        
        // loop to get to the end of the list
        while (currentPtr != NULL) {
            if(strcmp(currentPtr->data, value) == 0)
            {
                counter++;
                currentPtr->count++;
                if (previousPtr == NULL)
                    return;
                
                
                if ((currentPtr->count > (*sPtr)->count))
                {
                    
                    
                    ListNodePtr tem = currentPtr;
                    previousPtr->nextPtr = currentPtr->nextPtr;
                    tem->nextPtr = *sPtr;
                    *sPtr = tem;
                }
                
                else if (currentPtr->count > (*sPtr)->nextPtr->count)
                {
                    ListNodePtr tem = currentPtr;
                    previousPtr->nextPtr = currentPtr->nextPtr;
                    tem->nextPtr = (*sPtr)->nextPtr;
                    (*sPtr)->nextPtr = tem;
                    
                    
                }
                else //(currentPtr->count == (*sPtr)->nextPtr->count)
                {
                    ListNodePtr tem = currentPtr;
                    previousPtr->nextPtr = currentPtr->nextPtr;
                    tem->nextPtr = (*sPtr)->nextPtr->nextPtr;
                    (*sPtr)->nextPtr->nextPtr = tem;
                    
                }
                
                return;
            }
            else {
                previousPtr = currentPtr; // walk to ...
                currentPtr = currentPtr->nextPtr; // ... next node

            }
        }
        
        // insert new node at end of list
        if (previousPtr == NULL) {
            newPtr->nextPtr = *sPtr;
            newPtr->lastPtr = previousPtr;
            *sPtr = newPtr;
            
            newPtr->count++;
            counter++;
            
        }
        else { // insert new node between previousPtr and currentPtr
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
            newPtr->lastPtr = previousPtr;
            newPtr->count++;
            counter++;
            
        }
    }

}

// delete a list element
char delete(ListNodePtr *sPtr, char value[])
{
    // delete first node if a match is found
    if (strcmp(value, (*sPtr)->data) == 0)
    {
        if ((*sPtr)->count > 1)
        {
            (*sPtr)->count--;
            counter--;
            return '\0';
        }
        else
        {
            ListNodePtr tempPtr = *sPtr; // hold onto node being removed
            *sPtr = (*sPtr)->nextPtr; // de-thread the node
            free(tempPtr); // free the de-threaded node
            return *value;
        }
    }
    else {
        ListNodePtr previousPtr = *sPtr;
        ListNodePtr currentPtr = (*sPtr)->nextPtr;
        
        // loop to find the correct location in the list
        while (currentPtr != NULL && strcmp(currentPtr->data, value) != 0) {
            previousPtr = currentPtr; // walk to ...
            currentPtr = currentPtr->nextPtr; // ... next node
            
        }
        
        // delete node at currentPtr
        if (currentPtr != NULL) {
            ListNodePtr tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return *value;
        }
    }
    counter--;
    return '\0';
}

// return 1 if the list is empty, 0 otherwise
int isEmpty(ListNodePtr sPtr)
{
    return sPtr == NULL;
}

// print the list
void printList(ListNodePtr currentPtr)
{

    
        // while not the end of the list
        while (currentPtr != NULL)
        {
            printf("\t%s \t%d\n", currentPtr->data, currentPtr->count);
            currentPtr = currentPtr->nextPtr;
        }
    
    printf("\n");
    return;
}

/*void sort (ListNodePtr curr, ListNodePtr prev)
{
    while (currentPtr->count > previousPtr->count && prev !=)
    {
        
        int temp = currentPtr->count;
        currentPtr->count = previousPtr->count;
        previousPtr->count = temp;
        
        
    }
}*/




