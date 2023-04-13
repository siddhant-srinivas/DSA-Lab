#include<stdio.h>

int main()
{
    int n, arr[n];
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int count = 0;
        for(int i = 0; i<n; i++)
        {
            if(arr[i] < 0)
            {
                int x = arr[i];
                for(int j = i; j>count; j--)
                {
                    arr[j] = arr[j-1];
                }
                arr[count] = x;
                count ++;
            }     
        }    
        for(int k =0; k<n; k++)
        {
            printf("%d ", arr[k]);
        }
        

}