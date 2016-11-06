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
    char data[11]; // each listNode contains a character
    struct listNode *next; // pointer to next node
    struct listNode *prev;
};

struct listNode* GetNewNode(char x[]) {
    struct listNode* newNode
    = (struct listNode*)malloc(sizeof(struct listNode));
    strcpy(newNode->data, x);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct listNode *head;

//Inserts a Node at head of doubly linked list
void InsertAtHead(char x[]) {
    struct listNode* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

//Inserts a Node at tail of Doubly linked list
void InsertAtTail(char x[]) {
    struct listNode* temp = head;
    struct listNode* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        head->count++;
        return;
    }
    while(temp->next != NULL){
        if (strcmp(temp->data, newNode->data) == 0){
            temp->count++;
            return;
        }
        temp = temp->next; // Go To last Node
        if (strcmp(temp->data, newNode->data) == 0){
            temp->count++;
            return;
        }
    }
    newNode->count++;
    temp->next = newNode;
    newNode->prev = temp;
    
}

//Prints all the elements in linked list in forward traversal order
void Print() {
    struct listNode* temp = head;
    //printf("Forward: ");
    while(temp != NULL) {
        printf("%s\t %d\n",temp->data, temp->count);
        temp = temp->next;
    }
    printf("\n");
}



typedef struct listNode ListNode; // synonym for struct listNode
typedef ListNode *ListNodePtr; // synonym for ListNode*

// prototypes
void insert(ListNodePtr*, char[]);
char del(ListNodePtr*, char[]);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);
void ins(ListNodePtr *, char *);
void swap(ListNodePtr p1, ListNodePtr p2);
void SelectionSort(ListNodePtr head);
void reverseIterative(ListNodePtr head);
//void move(ListNodePtr, ListNodePtr);

int counter = 0;

int main(void)
{
    ListNodePtr startPtr = NULL; // initially there are no nodes
    char *item[11]; // char entered by user
    char command[5];
    
    do {
        instructions(); // ask for a command

        scanf("%s", command);
        
        if (strcmp(command, "prl") == 0)
            printList(startPtr);
       
        if ((strcmp(command, "ins") == 0) || strcmp(command, "del"))
            scanf(" %s", *item);
        
        
        if (strcmp(command, "ins") == 0) {
            InsertAtTail(*item); // insert item in list
            //SelectionSort(startPtr);
            Print();
            printf("Counter: %d\n", counter);
        }
        if (strcmp(command, "del") == 0) {
            // delete an element
            // if list is not empty
            
                // if character is found, remove it
                
            if (del(&startPtr, *item)) { // remove item
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
        newPtr->next = NULL; // node does not link to another node
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
                //reverseIterative(*sPtr);
                //SelectionSort(*sPtr);
                //reverseIterative(*sPtr);
                return;
            }
            else {
                previousPtr = currentPtr; // walk to ...
                currentPtr = currentPtr->next; // ... next node

            }
        }
        
        // insert new node at end of list
            newPtr->next= *sPtr;
            newPtr->prev = previousPtr;
            *sPtr = newPtr;
            
            newPtr->count++;
            counter++;
        
    }

}

// delete a list element
// delete a list element
char delete(ListNodePtr *sPtr, char value[])
{
    // delete first node if a match is found
    if (strcmp(value, (*sPtr)->data) == 0) {
        ListNodePtr tempPtr = *sPtr; // hold onto node being removed
        *sPtr = (*sPtr)->next; // de-thread the node
        free(tempPtr); // free the de-threaded node
        return *value;
    }
    else {
        ListNodePtr previousPtr = *sPtr;
        ListNodePtr currentPtr = (*sPtr)->next;
        
        // loop to find the correct location in the list
        while (currentPtr != NULL && strcmp(currentPtr->data, value) != 0) {
            previousPtr = currentPtr; // walk to ...
            currentPtr = currentPtr->next; // ... next node
            
        }
        
        // delete node at currentPtr
        if (currentPtr != NULL) {
            ListNodePtr tempPtr = currentPtr;
            previousPtr->next = currentPtr->next;
            free(tempPtr);
            return *value;
        }
    }
    
    return '\0';
}// print the list
void printList(ListNodePtr currentPtr)
{

        //reverseIterative(currentPtr);
    
        //SelectionSort(currentPtr);
        // while not the end of the list
        while (currentPtr != NULL)
        {
            printf("\t%s \t%d\n", currentPtr->data, currentPtr->count);
            currentPtr = currentPtr->next;
        }
    
    printf("\n");
    
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



void ins(ListNodePtr *head, char *input){
	ListNodePtr curr;
	if(head == NULL){
		head = (ListNodePtr *)malloc(sizeof(ListNodePtr));
		(*head)->count = 1;
		strcpy((*head)->data, input);
		(*head)->next = NULL;
        return;
	}
	else {
		curr = *head;
		while(curr->next != NULL)
        {
			if(!strcmp(curr->data, input)){
                curr->count++;
                break;
			}
			curr = curr->next;
			if(curr->next == NULL)
            {
				if(!strcmp(curr->data, input))
                {
                    curr->count++;
                }
            }
			else
            {
				curr->next = *(ListNodePtr *)malloc(sizeof(ListNodePtr));
				curr->next->count = 1;
				strcpy(curr->next->data, input);
				curr->next->next = NULL;
            }
        }
    } //end ins
}


/* To sort the linked list */
void SelectionSort(ListNodePtr head)
{
    //reverseIterative(head);
    
   // ListNodePtr currNode= head;
    ListNodePtr start = head;
    ListNodePtr traverse;
    ListNodePtr min;
    
    
    
    while(start->next)
    {
        min = start;
        traverse = start->next;
        
        for (int i = 0; i < counter; i++){
        while(traverse)
        {
            /* Find minimum element from array */
            if( min->data > traverse->data )
            {
                min = traverse;
            }
            
            traverse = traverse->next;
        }
        }

        swap(start,min); // Put minimum element on starting location
        start = start->next;
        
    }
}

/* swap data field of linked list */
void swap(ListNodePtr p1, ListNodePtr p2)
{
    int temp = p1->count;
    p1->count = p2->count;
    p2->count = temp;
    
    char tmp[11], tmp2[11];
    strcpy(tmp, p1->data);
    strcpy(tmp2, p2->data);
    strcpy(p1->data, tmp2);
    strcpy(p2->data, tmp);
}


void reverseIterative(ListNodePtr head){
    ListNodePtr currNode = NULL;
    ListNodePtr nextNode = NULL;
    ListNodePtr prevNode = NULL;
    
    while(currNode!=NULL){
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    head = prevNode;
    printf("\n Reverse Through Iteration\n");
    
}

