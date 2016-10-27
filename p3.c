//
//  main.c
//  p3
//
//  Created by Andrew Caldwell and Dan Stowe on 10/26/16.
//
//

#include <stdio.h>
#include <stdlib.h>
int main()
{
    typedef struct node         // define structure node -Andrew
    {
        int value;
        struct node  *next;     // recursion for the pointer value -Andrew
    } NODE;
    
    NODE *head;      // define and initialize the head of the linked list -Andrew
    if ((head = (NODE*) malloc(sizeof(NODE)) == NULL))
        printf("Could not allocate memory for head of list."); exit(1);
        
    
    
    return 0;
}
