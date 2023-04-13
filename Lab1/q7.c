#include <stdio.h>
#include <string.h>

int sum(int arr[125]);
int main()
{
    char str[1000];
    char word[50];
    int temp1[125] = {0};
    int temp2[125] = {0};
    int num = 0;
    int num1, num2;
    for(int i = 0; i<1000; i++)
    {
        if(str[i] != '\n') {scanf("%c", &str[i]); num++; }
        if(str[i] == '\n') break;
    }
    num = num -1;
    int min = num;
    for(int i = 0; i<50; i++)
    {
        if(word[i] != '\n') scanf("%c", &word[i]); 
        if(word[i] == '\n') break;
    }
    word[strlen(word)-1] = '\0';
    int len = strlen(word);
    for(int i = 0; i<len; i++)
    {
        int ascii = word[i];
        temp1[ascii] ++;
    }

    for(int i = 0; i<num; i++)
    {
        char ans[100] = {'\0'};
        for(int w = 0; w<125; w++)
        {
            temp2[w] = temp1[w];
        }
        int count = sum(temp2);

        int k = i;
        int flag = 0;
        for(int j = 0; j<len; j++)
        {
            if(str[i] == word[j]){flag = 1; break;}
        }
        if(flag == 0) continue;
        for(int j = 0; j<num && k<num; j++)
        {
            ans[j] = str[k];
            int asc = str[k];
                if(temp2[asc] > 0) 
                {
                    temp2[asc] --;
                    count --;
                }    
            k++;
            if(count == 0) break;
        }
        if(count == 0) 
        {
            if(strlen(ans) < min)
            {
                min = strlen(ans);
                num1 = i;
                num2 = i + min -1 ;
            }   
        }
    }

    printf("%d %d\n", num1, num2);
    for(int i = num1; i<=num2; i++)
    {
        printf("%c", str[i]);
    }
    
}
int sum(int arr[125])
{
    int s = 0;
    for(int i = 0; i<125; i++)
    {
        s = s + arr[i];
    }
    return s;
}