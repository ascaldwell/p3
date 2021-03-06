//
//  Andrew Caldwell and Dan Stowe
//  Unix ID: ac289774
//  Discussion Session: Friday 1:40 PM
//



#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

// Program that inserts, deletes, and gets data on the linked list created.

#define MAX_CMD_LENGTH 4
#define MAX_STRING_LENGTH 11


// linked list node
struct listNode {
    int count;
    char data[10]; // each listNode contains a character
    struct listNode *nextPtr; // pointer to next node
};

typedef struct listNode ListNode; // synonym for struct listNode
typedef ListNode *ListNodePtr; // synonym for ListNode*

// prototypes
void insert(void);
char delete();
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);
void findpref(void);
void fdelete(void);
void pst(void);
void pcr(void);
void psu(void);
int EndsWith(char *, char *);

ListNodePtr head = NULL; // initially there are no nodes
int count;



// main function for driving the program
int main(void)
{
    //char *item[11]; // char entered by user
    char command[4];
    
    do {
        instructions(); // ask for a command
        scanf("%s", command);

        if (strcmp(command, "prl") == 0)
        {
            printList(head);
        }
        else if(strcmp(command, "ppr") == 0)
        {
            findpref();
        }
        else if(strcmp(command, "pst") == 0) {
            pst();
        }
        
        
        else if(strcmp(command, "psu") == 0) {
            psu();
        }
        
        else if(strcmp(command, "psu") == 0) {
            psu();
        }
        
        else if(strcmp(command, "fde") == 0)
        {

            fdelete();
           // printList(head);
        
        }
        else if(strcmp(command, "pcr") == 0)
        {
            pcr();
        }
        
        
        else if (strcmp(command, "ins") == 0) {
            insert(); // insert item in list
            count++;
           // printList(head);
        }
        else if (strcmp(command, "del") == 0) {
            // delete an element
            // if list is not empty
            if (!isEmpty(head)) {
                // if character is found, remove it
                delete();  // remove item
               // printList(head);
            }
        }
        
    } while (strcmp(command, "end") != 0);
}

// finds and prints out nodes with specified prefix
void findpref(void)
{
    char prefix[11];
    scanf("%s", prefix);    // scan for the prefix
    
    ListNodePtr curr = head;    // start at head of liked list
    if (curr == NULL)           // check if list is empty
    {
        printf("The list is empty");
        return;
    }
    while (curr != NULL)    // traverse the list
    {
        if(prefix[0] != curr->data[0])  // check if value is a prefix of current node
        {
            curr= curr->nextPtr;    // if not, continue
        }
        else {                                                  // otherwise, print to console
            if(strcmp(prefix,strstr(curr->data, prefix))){
                printf("\t%s\t%d\n" , curr->data, curr->count);
            }
            curr= curr->nextPtr;    // continue to end of the list
        }
    }
}

// deletes all nodes with specified count
void fdelete(){
    
    //Given a reference (pointer to pointer) to the head of a list and
    // a key, deletes all occurrence of the given key in linked list
    int key;
    scanf("%d", &key);
    
   ListNode *head_ref = head;
    
        // Store head node
        ListNode* temp = head_ref, *prev = NULL;
        
        // If head node itself holds the key or multiple occurrences of key
        while (temp != NULL && temp->count == key)
        {
            
            *head_ref = *temp->nextPtr;   // Changed head
            free(temp);               // free old head
            temp = head_ref;         // Change Temp
        }
        
        // Delete occurrences other than head
        while (temp != NULL)
        {
            // Search for the key to be deleted, keep track of the
            // previous node as we need to change 'prev->next'
            while (temp != NULL && temp->count != key)
            {
                prev = temp;
                temp = temp->nextPtr;
            }
            
            // If key was not present in linked list
            if (temp == NULL) return;
            
            // Unlink the node from linked list
            prev->nextPtr = temp->nextPtr;
            temp->count = 0;
            free(temp);  // Free memory
            
            //Update Temp for next iteration of outer loop
            temp = prev->nextPtr;
            
        }
    }
    


// display program instructions to user
void instructions(void)
{
    printf("Command? ");
}


// insert a new value into the list
void insert()
{
    ListNodePtr *sPtr = &head;
    char value[11];
    scanf ("%s", value);
    
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
                    if (strcmp(currentPtr->data, "maximum")){
                        currentPtr->count--;
                    }
                    previousPtr->nextPtr = currentPtr->nextPtr;
                    tmp = currentPtr;
                    tmp->nextPtr = previousPtr;
                    previousPtr = tmp;
                    
                    if (currentPtr->count == previousPtr->count)
                    {
                        char temp[11];
                        strcpy( temp, (*sPtr)->nextPtr->data);
                        strcpy((*sPtr)->nextPtr->data, (*sPtr)->data);
                        strcpy((*sPtr)->data, temp);
                    }
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




// delete a list element specified by user
char delete(void)
{
    ListNodePtr *sPtr = &head;
    char value[11];
    scanf("%s", value);
    // delete first node if a match is found
    if (strcmp(value, (*sPtr)->data) == 0) {
        if((*sPtr)->count > 1){
            (*sPtr)->count--;
            return '\0';
        }
        else{
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
            
            if (strcmp(value, currentPtr->data) == 0) {
                if(currentPtr->count > 1){
                    currentPtr->count--;
                }
                else{
                    
            //ListNodePtr tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(currentPtr);
                }
            
            
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

// print count range that is specified by the user
void pcr() {
    
    int count,temp, v1, v2; //temp count
    count = temp = 0;
    ListNodePtr curr = head;
    
    scanf("%d %d", &v1, &v2);
    
    if(curr->nextPtr == NULL) {
        printf("The list is empty.");
    }
    else {
        while(curr->nextPtr != NULL) {
            if((curr->count >= v1) && (curr->count <= v2)) {
                printf("%s\t%d\n", curr->data, curr->count);
            }
            curr = (curr->nextPtr);
        }
    }
} //end pcr

// print nodes that contain the suffix specified by the user.
void psu(void) {
    char suffix[11];
    scanf("%s", suffix);
    

    ListNodePtr curr = head;
    
    if(curr == NULL) {
        printf("The list is empty.");
        return;
    }
    else {
        while(curr != NULL) {
                                                  // otherwise, print to console
                if(EndsWith(curr->data, suffix)!= 0){
                    printf("\t%s\t%d\n" , curr->data, curr->count);
                    curr= curr->nextPtr;    // continue to end of the list

                }
                else{
                curr= curr->nextPtr;    // continue to end of the list
        }
        }
    }
} //end psu

// helper function for psu
int EndsWith(char *str, char *suffix)
{
    if (!str || !suffix)
        return 0;
    size_t lenstr = strlen(str);
    size_t lensuffix = strlen(suffix);
    if (lensuffix >  lenstr)
        return 0;
    return strncmp(str + lenstr - lensuffix, suffix, lensuffix) == 0;
}


// print statistics of the linked list
void pst() {
    
    int max, min = 1;
    int temp2 = 0; //count the counts
    int temp= 0;   // add the values
    ListNodePtr curr = head; //curr points to linked list struct head
    
    
    if(head == NULL) {
        printf("The list is empty");
    }
    else {
        while(curr != NULL) {
            if (curr->count >=1)
            temp += curr->count;
            temp2++;
            if(curr->count > max) {
                max = curr->count; //max count in list
            }
            if(curr->count <= min) {
                min = curr->count; //minimum count in list
                
            }
            curr = curr->nextPtr; //move to next node
        }
    }

    printf("\tNo. of nodes = %d\n", temp2);
    printf("\tMax. count = %d\n", max);
    printf("\tMin. count = %d\n", min);
    printf("\tAvg. count = %.1f\n", (float)temp/(float)temp2);

} //end pst function


