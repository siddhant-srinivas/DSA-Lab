#include <stdio.h>
#include <stdlib.h>

int input;
int arr1[100];

void sumcheck(int arr[], int size)
{
    int i =0;
int ans = input;
while(ans>0){
if(ans==0){
break;
}
ans = ans - arr[i];
i++;
}
if(ans==0){
printf("POSSIBLE\n");
for(int k = 0;k<size;k++){
for(int l = 0;l<i;l++){
if(arr1[k]==arr[l]){
printf("%d ", k);
break;
}
}
}
exit(0);
}
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(int *arr, int start, int end)
{
    if(start==end)
    {
        sumcheck(arr, end+1);
        return;
    }
    int i;
    for(i=start;i<=end;i++)
    {
        swap((arr+i), (arr+start));
        permutation(arr, start+1, end);
        swap((arr+i), (arr+start));
    }
}

int main()
{
int n;

scanf("%d", &n);

int arr2[n];

for(int i = 0;i<n;i++)
{
    scanf("%d", &arr1[i]);
}

for(int i = 0;i<n;i++){
arr2[i]=arr1[i];
}

scanf("%d", &input);

permutation(arr2,0,n-1);

printf("NOT POSSIBLE");

return 0;
}

