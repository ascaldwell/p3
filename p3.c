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
};

typedef struct listNode ListNode; // synonym for struct listNode
typedef ListNode *ListNodePtr; // synonym for ListNode*

// prototypes
void insert(ListNodePtr *sPtr, char value[]);
char delete(ListNodePtr *sPtr, char value[]);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);
void findpref(ListNodePtr head, char s[]);
void fdelete(int*);


ListNodePtr head = NULL; // initially there are no nodes
int count;



void pst(void);
void pcr(void);
void psu(void);


int main(void)
{
    char *item[11]; // char entered by user
    char command[4];
    
    do {
        instructions(); // ask for a command
        scanf("%s", command);

        if(strcmp(command, "ppr") == 0)
        {
            findpref(head, *item);
        }
        if(strcmp(command, "pst") == 0) {
            pst();
        }
        
        
        if(strcmp(command, "psu") == 0) {
            psu();
        }
        
        if(strcmp(command, "psu") == 0) {
            psu();
        }
        
        
        scanf("%s", *item);
        
        
        if (strcmp(command, "ins") == 0) {
            insert(&head, *item); // insert item in list
            count++;
            printList(head);
        }
        if (strcmp(command, "del") == 0) {
            // delete an element
            // if list is not empty
            if (!isEmpty(head)) {
                // if character is found, remove it
                
                if (delete(&head, *item)) { // remove item
                    printf("%s deleted.\n", *item);
                    printList(head);
                    count--;
                }
                else {
                    printf("%s not found.\n\n", *item);
                }
            }
            else
                puts("List is empty.\n");
        }
        
        if(strcmp(command, "fde") == 0)
        {
            int *someInt;
            scanf("%d", someInt);
            fdelete(someInt);
        
        }
        

        
    } while (strcmp(command, "end") != 0);
    


}

// finds an prints out nodes with specified prefix
void findpref(ListNodePtr head, char s[])
{

    ListNodePtr curr = head;
    if (curr == NULL)
    {
        printf("The list is empty");
        return;
    }
    while (curr ->nextPtr!= NULL)
    {
        printf("\t%s\t%d\n" , (strstr(curr->data, s)), curr->count);
        curr= curr->nextPtr;
    }

}

void fdelete(int *a){

  ListNodePtr curr = head;
    
    while (curr != NULL){
        if(curr->count == *a){
            ListNodePtr temp = curr;
            curr = curr->nextPtr;
            free(temp);
            curr= curr->nextPtr;
        }
            
    }
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
    
    int highCount = 1;
    
    if (newPtr != NULL) { // is space available
        strcpy(newPtr->data, value); // place string value in node
        newPtr->nextPtr = NULL; // node does not link to another node
        
        ListNodePtr previousPtr = NULL;
        ListNodePtr currentPtr = *sPtr;
        ListNodePtr tmp = NULL;
        
        
        // loop to get to the end of the list
        while (currentPtr != NULL) {
            if(strcmp(currentPtr->data, value) == 0){
                
                
                if (currentPtr->count >= highCount) { // swap and restart at head
                    currentPtr->count++;
                    highCount = currentPtr->count;
                    if (currentPtr == *sPtr){
                        return;
                    }
                    previousPtr->nextPtr = currentPtr->nextPtr;
                    tmp = currentPtr;
                    tmp->nextPtr = *sPtr;
                    *sPtr = tmp;
                    highCount = (*sPtr)->count;
                    
                    if ((*sPtr)->nextPtr->count > (*sPtr)->count )
                    {
                        int tmp = (*sPtr)->nextPtr->count;
                        (*sPtr)->nextPtr->count = (*sPtr)->count;
                        (*sPtr)->count = tmp;
                        
                        char temp[11];
                        strcpy( temp, (*sPtr)->nextPtr->data);
                        strcpy((*sPtr)->nextPtr->data, (*sPtr)->data);
                        strcpy((*sPtr)->data, temp);
                        
                    }
                }
                else if (currentPtr->count > previousPtr->count) {
                    currentPtr->count++;
                    if (currentPtr == *sPtr){
                        return;
                    }
                    previousPtr->nextPtr = currentPtr->nextPtr;
                    tmp = currentPtr;
                    tmp->nextPtr = previousPtr;
                    previousPtr = tmp;
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
            *sPtr = newPtr;
            newPtr->count++;
        }
        else { // insert new node between previousPtr and currentPtr
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
            newPtr->count++;
            
        }
    }
}




// delete a list element
char delete(ListNodePtr *sPtr, char value[])
{
    // delete first node if a match is found
    if (strcmp(value, (*sPtr)->data) == 0) {
        ListNodePtr tempPtr = *sPtr; // hold onto node being removed
        *sPtr = (*sPtr)->nextPtr; // de-thread the node
        free(tempPtr); // free the de-threaded node
        return *value;
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
            //ListNodePtr tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(currentPtr);
            
            
            if (currentPtr->count > previousPtr->count)
            {

                ListNodePtr tmp = currentPtr;
                tmp->nextPtr = previousPtr;
                previousPtr = tmp;

            }
            return *value;
        }
    }
    
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
    // if list is empty
    if (isEmpty(currentPtr)) {
        puts("List is empty.\n");
    }
    else {
        // while not the end of the list
        while (currentPtr != NULL) {
            printf("\t%s \t%d\n", currentPtr->data, currentPtr->count);
            currentPtr = currentPtr->nextPtr;
        }
    }
    printf("\n");
}

void pcr() {
    
    int count,temp, v1, v2; //temp count
    count = temp = 0;
    ListNodePtr curr = head;
    
    scanf("%d %d", &v1, &v2);
    
    if(curr->nextPtr == NULL) {
        printf("The list is empty.");
    }
    else {
        while((curr->nextPtr) != NULL) {
            if((count <= v1) && (count >= v2)) {
                printf("%s:\t%d\n", curr->data, curr->count);
            }
            curr = (curr->nextPtr);
        }
    }
} //end pcr

void psu(void) {
    
    char input[10];
    ListNodePtr curr = head;
    scanf("%s", input);
    
    if(curr->nextPtr == NULL) {
        printf("The list is empty.");
    }
    else {
        while(curr->nextPtr != NULL) {
            
            if(strrchr(curr->data, atoi(input)) != NULL) {
                printf("%s\t%d\n", curr->data, curr->count);
            }
            curr = curr->nextPtr;	
        }
    }
} //end psu

void pst() {
    
    int max = 0, min = 1;
    int temp = 0; //count the counts
    ListNodePtr curr = head; //curr points to linked list struct head
    ListNodePtr curr2 = head;
    
    if(head == NULL) {
        printf("The list is empty");
    }
    else {
        while(curr != NULL) {
            //if (curr->count ==1)
            temp++;
            if(curr->count > max) {
                max = curr->count; //max count in list
            }
            if(curr->count < min) {
                min = curr->count; //minimum count in list
                
            }
            curr = curr->nextPtr; //move to next node
        }
    }
    int avgCount;
    while(curr2->nextPtr !=NULL)
    {
        avgCount += curr2->count; // broken af
    }
    
    avgCount = avgCount/count;
    
    printf("Number of nodes in list: %d\n", temp);
    printf("Maximum count in list: %d\n", max);
    printf("Minimum count in list: %d\n", min);
    printf("The average count is %d\n", avgCount);
    return;
} //end pst function

