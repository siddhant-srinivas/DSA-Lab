#include <stdio.h>
int main()
{
    int num, size,y, t;
    scanf("%d", &num); scanf("%d", &size);
    int arr[size]; int count = 0;
        for(int i = 0; i<size; i++) {scanf("%d", &arr[i]);}
        for(int i = 0; i<size; i++)
        {
            if(arr[i] < (1+num)/2) {
                int x = arr[i];
                for(int j = i; j>count; j--){arr[j] = arr[j-1];}
                arr[count] = x; count ++; }
        }
    for(int i = 0; i<size; i++) { if(arr[i] == (1+num)/2) { y = i; t = arr[y]; break; }  }  
    for(int i = y; i>count; i--) {  arr[i] = arr[i-1]; } arr[count] = t;
    for(int i = 0; i<size;i++) { printf("%d ", arr[i]); }     
}