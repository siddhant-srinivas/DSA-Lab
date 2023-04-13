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

int isPalindrome(node *head)
{
    node *temp = head;
    node *end = NULL;
    node *prev = NULL;
    node *trav = NULL;
    int flag = 1;
    int len = 0;
    while(temp != NULL)
    {
        if((temp -> next -> next) == NULL)
        {
            prev = temp;
            break;
        }    
        temp = temp -> next;
        len ++;
    } 
    end = prev -> next;
    temp = head;
    while(temp != NULL)
    {
        if(temp == end) break;
        if(temp -> data == end -> data)
        {
            if(len % 2 == 0) 
            {
                if(temp -> next == end) break;
            }
            trav = temp;
            while(trav != NULL)
            {
                if(trav -> next == prev) break; 
                trav = trav -> next;
            }
            
            end = prev;
            prev = trav;
            temp = temp -> next;
        }
        else if(temp -> data != end -> data)
        {
            flag = 0;
            break;
        }
    } 
    return flag;
}

int main()
{
    node *head =readList();
    int palin = isPalindrome(head);
    printf("%d", palin);
    freeList(head);
} 



    
