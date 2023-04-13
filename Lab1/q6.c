#include<stdio.h>

int prime(int n);
void dig(int x);

int arr[100] ={0};

int main()
{   
    int index = 0;
    
    int a, b;
    scanf("%d %d", &a, &b);
    if(a>b)
    {
        int temp = b;
        b = a;
        a = temp;
    }
    
    for(int i = a; i<= b; i++)
    {
        if(prime(i) == 0) continue;
        
        else if(prime (i) == 1){dig(i);}
    }
    int max = 0;
    for(int i = 0; i < 10 ; i++)
    {
        if(i == 0) {max = arr[i];}
        if(arr[i] > max)
        {
            max = arr[i]; 
            index = i;
        }    
    }
    printf("%d %d", index, max);

}


int prime(int n)
{
    int flag;
    for(int i = 2; i < (n/2); i++)
    {
        if(n%i == 0)
        {
            flag = 0;
            break;
        }    
        else flag = 1;
    }
    return flag;
}

void dig(int x)
{
    int rem, q;
    int len;

while(x>0){
        rem = (x%10);
        arr[rem] = arr[rem] + 1;
        x /= 10;
    }
    
}