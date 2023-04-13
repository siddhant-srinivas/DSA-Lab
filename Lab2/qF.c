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

node *rearrangeList(node *head)
{
    node *temp = head -> next;
    node *prev = head;
    node *nex = head -> next;
    int n = 1;
    while(temp != NULL)
    {
        n++;
        if(n % 2 == 1)
        {
            node *store = temp -> next;
            nex-> next = store;
            temp -> next = prev -> next;
            prev -> next = temp;
            prev = temp;
            nex = store;
            temp = nex;
        }
        else temp = temp -> next;
    }
    return head;    
}

int main()
{
    node *head = readList();
    node *newList = rearrangeList(head);
    printList(newList);
    freeList(head);
}