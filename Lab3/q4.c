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

node *readList()
{
    int n;
    scanf("%d", &n);
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

int main()
{
    node *head = readList(); // NOTE: USE LONG LATER INSTEAD OF INT
    node *temp = head;
    node *end = head;
    while(end -> next != NULL)
    {
        end = end -> next;
    }
    node *store = end;
    int sum1 = temp -> data;
    int sum2 = end -> data;
    int max, flag = 0;
    while(temp != NULL && end != NULL)
    {
        if(temp == end || temp -> prev == end) break;
        if(sum1>sum2)
        {
            end = end -> prev;
           if(end != NULL) sum2 = sum2 + end -> data;
        }
        if(sum1<sum2)
        {
            temp = temp -> next;
            if(temp != NULL) sum1 = sum1 + temp -> data;
        }
        if(sum1 == sum2)
        {
            if(flag == 0) {max = sum1; flag = 1;}
            if(sum1>max && flag == 1) max = sum1;
            temp = temp -> next;
            end = end -> prev;
            if(temp!= NULL) sum1 = sum1 + temp -> data;
            if(end != NULL) sum2 = sum2 + end -> data;
        }
    }
    temp = head; end = store;
    int sum = 0; int count1 = 1;
    while(temp != NULL)
    {
        sum = sum + temp-> data;
        if(sum == max) break;
        else {temp = temp -> next;
        count1 ++;
        }
    }
    sum = 0; int count2 = 1;
    while(end != NULL)
    {
        sum = sum + end -> data;
        if(sum == max) break;
        else {end = end -> prev;
        count2++;
        }
    }
    printf("%d %d", count1, count2);
}