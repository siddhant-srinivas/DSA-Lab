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

node *currentSong(node *head, int n)
{
    node *temp = head;
    if(n == 0) return head;
    while(n>0)
    {
        temp = temp -> next;
        n--;
    }
    return temp;
}

node *nextSong(node *temp)
{
    if(temp -> next == NULL) return temp;
    temp = temp -> next;
    return temp;
}

node *prevSong(node *temp)
{
    if(temp -> prev = NULL) return temp;
    temp = temp -> prev;
    return temp;
}

node *operation(node *head, int val, int count)
{
    node *cur = head;
    node *temp = head;
    while(count>0)
    {
        temp = temp -> next;
        count --;
    }
    while(cur != NULL)
    {
        if(cur -> data == val) break;
        cur = cur -> next;
    }
    if(cur != NULL)
    {
        node *pre = cur -> prev;
        pre -> next = cur -> next;
        (cur -> next) -> prev = pre;
        cur -> next = temp -> next;
        (temp -> next) -> prev = cur;
        temp -> next = cur;
        cur -> prev = temp;
        return temp;
    }
    else if(cur == NULL)
    {
        node *newNode = addToList(head,val);// Here, if we are allowed to create nodes, use createNode and insert node directly
        node *pre = newNode -> prev;
        pre -> next = NULL;
        newNode -> next = temp -> next;
        (temp -> next) -> prev = newNode;
        newNode -> prev = temp;
        temp -> next = newNode;
        return temp;
    }
}

int main()
{
    node *head = readList();
    node *temp = head;
    int flag = 1, n;
    int count = 0;
    while(flag)
    {
        scanf("%d", &n);
        switch(n)
        {
            case 1: int x;
                    scanf("%d", &x);
                    addToList(head,x);
                    break;

            case 2: printf("%d", currentSong(head,count) -> data);
                    break;   

            case 3: nextSong(temp);
                    count ++;
                    break;

            case 4: prevSong(temp);
                    count--;
                    break;
                    
            case 5: return 0;

            case 6: int t;
                    scanf("%d", &t);
                    operation(head, t, count);
                    break;
        }
    }
}