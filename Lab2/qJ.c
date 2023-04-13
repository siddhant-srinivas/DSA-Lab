#include <stdio.h>

typedef struct Country
{
    char name[20];
    int gold;
    int silver;
    int bronze;
} country;

void maximum(int n, country array[n], country array2[n]);

int main()
{
    int n;
    scanf("%d", &n);
    country arr[n];
    for(int i = 0; i< n; i++)
    {
        scanf("%s", &arr[i].name);
        scanf("%d %d %d", &arr[i].gold, &arr[i].silver, &arr[i].bronze);
    }

    country arr2[n];
    for(int i = n; i>0; i--)
    {
        maximum(i,arr,arr2);
    }
    for(int i = n-1; i>=0; i--)
    {
        printf("%s\n", arr2[i].name);
    }
}
void maximum(int n, country array[n], country array2[n])
{
    int max = array[0].gold;
    int index = 0;
    for(int i = 0; i<n; i++)
    {
        if(array[i].gold > max)
        {
            max = array[i].gold;
            index = i;
        }
        if(array[i].gold == max)
        {
            if(array[i].silver > array[index].silver){
                max = array[i].gold;
                index = i;
            }
            if(array[i].silver == array[index].silver)
            {
                if(array[i].bronze > array[index].bronze)
                {
                    max = array[i].gold;
                    index = i;
                }
            }
        }
    }
    array2[n-1] = array[index];
    for(int i = index; i<n-1; i++)
    {
        array[i] = array[i+1];
    }
}