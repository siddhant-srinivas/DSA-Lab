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
        printf("%d ", ptr -> data);
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

node *mergeLists(node *head1, node *head2)
{
    node *head;
    node *temp = head1;
    while(temp->next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = head2;
    int flag = 0;
    while(head2 != NULL)
    {
        if(((head2 -> data)<(head1->data)) && (flag == 0))
        {
            node *store = head2 -> next;
            temp -> next = store;
            head2 -> next = head1;
            head1 = head2;
            head = head2;
            head2 = store;
            flag = 1;     
        }
        
        if(((head2->data) >= (head1 -> data)) && ((head2 -> data) <= ((head1 -> next) -> data)))
        {
            if(flag == 0) {head = head1; flag = 1;}
            node *store = head2 -> next;
            temp -> next = store;
            head2 -> next = head1 -> next;
            head1 -> next = head2;
            head1 = head2;
            head2 = store;
        }

        else
        {
            head1 = head1 -> next;
        }
        
    }
    return head;
}

int main()
{
    node *head1 = readList();
    node *head2 = readList();
    node *merged = mergeLists(head1, head2);
    printList(merged);
    freeList(merged);
}