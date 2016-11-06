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
typedef struct listNode ListNode; // synonym for struct listNode
typedef ListNode *ListNodePtr; // synonym for ListNode*
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
void InsertAtTail(ListNodePtr *head, char x[]) {
    
    ListNodePtr temp = *head;
    struct listNode* newNode = GetNewNode(x);
    if(*head == NULL) {

        (*head) = newNode;
        (*head)->count++;
        return;
    }
    if (((*head)->count > 0) && (strcmp((*head)->data, x) == 0))
    {
        (*head)->count++;
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





// prototypes
void insert(ListNodePtr*, char[]);
void del(char key[]);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);
void ins(ListNodePtr *, char *);
void swap(ListNodePtr p1, ListNodePtr p2);
void SelectionSort(ListNodePtr head);
void reverseIterative(ListNodePtr head);
void RemoveNode(char[], ListNodePtr* head);
//void move(ListNodePtr, ListNodePtr);

int counter = 0;

int main(void)
{
    //ListNodePtr startPtr = NULL; // initially there are no nodes
    char item[11]; // char entered by user
    char command[5];
    
    do {
        instructions(); // ask for a command

        scanf("%s", command);
        
        if (strcmp(command, "prl") == 0)
        {
            Print();
        }
        
        scanf("%s", item);
        
        
        if (strcmp(command, "ins") == 0) {
            InsertAtTail(&head, item); // insert item in list
            SelectionSort(head);
            Print();
            printf("Counter: %d\n", counter);
        }
        if (strcmp(command, "del") == 0) {
            del(item); // remove item
                printList(head);
        }

        
        }
        
while (strcmp(command, "end") != 0);
}
        // display program instructions to user
void instructions(void)
{
    printf("Command? ");
}


void printList(ListNodePtr currentPtr)
{

        //reverseIterative(currentPtr);
    
        //SelectionSort(currentPtr);
        // while not the end of the list
        while (currentPtr != NULL)
        {
            if (currentPtr == NULL)
            {
                printf("List is empty\n");
                return;
            }
            
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
void del(char input[]) { // function with character pointer to input array
    ListNodePtr curr = head;
    if(head == NULL) {
        printf("List is empty.\n");
    }
    
    if(strcmp(curr->data, head->data) == 0)
    {
        if (curr->count > 1)
        {
            curr->count--;
            return;
        }
        
        else
        {
            ListNodePtr tmp = head->next;
            free(curr);
            head = tmp;
            return;
        }
    }
        
    while(curr !=NULL && strcmp(curr->data, input)!= 0)
    {
        curr = curr->next;
    }
    
    if (curr->count > 1)
    {
        curr->count--;
        return;
    }
    else
    {
        curr->prev->next= curr->next;
        free(curr);
    }

    
} //end del

/* To sort the linked list */
void SelectionSort(ListNodePtr head)
{
    bool swapped = false;
    ListNodePtr temp = head;
    if(head == NULL || head->next==NULL){
        return;
    }
 // empty list, exit
    // Going to last Node
    while(swapped == false)
    {
        temp->prev = temp;
        temp = temp->next;
        if (temp->count > temp->prev->count)
        {
            int tmpNum = temp->count;
            temp->count = temp->prev->count;
            temp->prev->count = tmpNum;
            
            char tmpString[11];
            strcpy(tmpString, temp->data);
            strcpy(temp->data, temp->prev->data);
            strcpy(temp->prev->data, tmpString);
            swapped = true;
        }
        
        if (swapped)
        {
            swapped = false;
        }
        else{
            break;
        }
        
    }
    // Traversing backward using prev pointer
    temp = temp->prev;
    while(temp != NULL) {
        
        if (temp->count > temp->prev->count)
        {
            int tmpNum = temp->count;
            temp->count = temp->prev->count;
            temp->prev->count = tmpNum;
            
            char tmpString[11];
            strcpy(tmpString, temp->data);
            strcpy(temp->data, temp->prev->data);
            strcpy(temp->prev->data, tmpString);
            
        }
        
        temp = temp->prev;
        
    }
}


