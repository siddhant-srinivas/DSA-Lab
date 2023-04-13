#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct Node_t{
    int data;
    struct Node_t *next;
    struct Node_t *prev;
} node;

node *createNode(int value){
    node *newNode = malloc(sizeof(node));
    assert(newNode != NULL);
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}

node *addToList(node *head, int val)
{
    node *newNode = createNode(val);
    if(head == NULL) return newNode;
    node *temp = head;
    head -> prev = NULL;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode ->prev = temp;
    return newNode;
}

node *readList(int n)
{
    node *head = NULL;
    for(int i = 0; i<n; i++)
    {  
        int x;
        scanf("%d", &x);
        if(head == NULL) head = addToList(head,x);
        else addToList(head,x);
    }
    return head;
}

void *printList(node *head)
{
    node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    node *head = readList(n);
    node *temp = head, *end = head;
    while(end -> next != NULL)
    {
        end = end -> next;
    }
    while(k>0)
    {
        node *store = end -> prev;
        store -> next = NULL;
        end -> next = temp;
        end -> prev = NULL;
        temp -> prev = end;
        temp = end;
        end = store;
        k--;
    }
    printList(temp);
}