#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct Node_t {
    int data;
    struct Node_t *next;
}; 
typedef struct Node_t node;

node *createNode(int value)         // returns pointer to the new node
{
    node *newNode = malloc(sizeof(node));
    assert(newNode != NULL);
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}

node *addToList(node *head, int val)        // adds node to the back of the linked list and returning a pointer to that node
{
    node *newNode = createNode(val);
    if (head == NULL) {return newNode;}
    node *current = head;
    while(current -> next != NULL) {current  = current -> next;}
    current -> next = newNode;
    return newNode;
}

node *readList()        // creates singly linked list by reading input and returns a pointer to the head of the list
{
    int n;
    scanf("%d", &n);
    node *head = NULL;

    for(int i =0 ; i<n; i++) {
        int x;
        scanf("%d", &x);
        if(head == NULL) head = addToList(head, x);
        else addToList(head,x);
        }
    return head;    
}

void printList(node *head)  // prints the linked list
{
    node *ptr = head;
    while(ptr != NULL) {
        printf("%d", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
    return ;
}

void freeList(node *head)   //frees the memory dynanically allocated to the linked list
{
    node *current, *next;
    current = head;
    while(current != NULL) {
        next = current -> next;
        free(current);
        current = next;
    }
}

node *removeRepeatedNodes(node *head)
{
    node *temp = head;
    node *prev2 = NULL;
    while(temp != NULL)
    {
        node *prev = temp;
        int flag = 1;
        node *loop = temp -> next;
            while(loop != NULL)
            {
                if(temp -> data == loop -> data)
                {
                    flag = 0;
                    prev -> next = loop -> next;
                    free(loop);
                    loop = prev -> next;
                }
                else if(temp -> data != loop -> data)
                {
                    break;
                }
            }  
        if(flag == 0) 
        {
            if(temp == head)
            {
                head = temp -> next;
                free(temp);
                temp = head;
            }
            else
            {
                prev2 -> next = temp -> next;
                free(temp);
                temp = prev2 -> next;
            }
        }
        else if(flag == 1)
        {
            prev2 = temp;
            temp = temp -> next;
        }
    }
    return head;
}    

int main()
{
    node *head = readList();
    node *newList = removeRepeatedNodes(head);
    printList(newList);
    freeList(head);
}