#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int binary_search(int arr[], int target, int l,int high);

int main(){
    int n;
    scanf("%d",&n);
    int iparr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&iparr[i]);
    }
    int count=0;
    int index = 0;
    while(index < n){
        index = binary_search(iparr,iparr[index],0,n);
        count++;
    }
    printf("%d",count);
}

int binary_search(int arr[], int target, int l,int high)
{
    int result = -1;
    int r = high - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) {
            result = mid;
            l = mid + 1;
        }
        else if (arr[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return result+1;
}