#include<stdio.h>
int palindrome(int n, char arr[n+1]); int x = 0;
int main(){
    char str[1000] = {0};     char temp[1000] = {0};    char palin[1000] = {0};
    int count = 0; int len = 0; int num = 0; int z = 0;
    for(int i = 0; i<1000; i++)
    {
           if(str[i] != '\n') {scanf("%c", &str[i]); num++; }
           if(str[i] == '\n') break;
    }
    str[num-1] = ' ';
    for(int i = 0; i<num; i++)
    {   
        if(str[i] == ' ')
        {
            for(int j = i-1 ; (j>= count ); j--)
            {
                printf("%c", str[j]);
            }
            printf(" ");    count = i+1;
            if(palindrome(len, temp) == 1)
            {
                int boo = 0;
                if(z == 0)
                {
                    boo = 1; 
                    for(int r = z; r< len; r++)
                    {
                        palin[r] = temp[r]; z++; 
                    }
                }
                else if(boo == 0 && z != 0)
                {   
                    int q = 0;
                    for(int r = z+1; r< z+1+len; r++)
                    {
                        palin[r] = temp[q];
                        q++;
                    }
                    z = z+1+len;
                }
                palin[z] = ' ';
            } 
            for(int k = 0; k<=len; k++) {temp[k] = ' ';}
            len = 0;
            continue;          
        }
        else {temp[len] = str[i];   len++;}         
    }
    printf("\n");
    if(x == 0) printf("NO PALINDROMES");
    else if(x!=0) {for(int a = 0; a<z ; a++) {printf("%c", palin[a]);}}   
}
int palindrome(int n, char arr[n]) {
    int u=1;
    if(n == 1) return 0;
    for(int i = 0; i<n; i++) {if(arr[i] != arr[n-i-1]) {u = 0; break;}}
    if(u == 1) x++;
    return u;
}
