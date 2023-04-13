#include<stdio.h>
#include<stdlib.h>

typedef struct Student
{
    char email[100];
    char branch[50];
    char id[50];
} student;

void id(student *s1);

int main()
{
    student s1;
    fgets(s1.email, 100, stdin);
    fgets(s1.branch, 50, stdin);
    id(&s1);
}

void id(student *s1)
{
    char id_no[6];
    for(int i = 5; i<9; i++)
    {
        id_no[i-5] = s1 -> email[i];
    }
    id_no[6] = '\0';
    char year[6];
    for(int i = 1; i<5; i++)
    {
        year[i-1] = s1 -> email[i]; 
    }
    year[4] = 'A';
    year[5] = '\0';
    id_no[4] = 'H';
    id_no[5] = '\0';
    char s;
    if(s1 -> branch[1] == 'S') s = '7';
    else if(s1 -> branch[1] == 'C') s = 'A';
    else if(s1 -> branch[1] == 'E') s = '3';
    printf("%s%cPS%s", year, s, id_no);
}