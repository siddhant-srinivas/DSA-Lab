#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    int arr[n][n];
    int i,j;
    j = (n-1)/2;
    i = n/2;
    int count = 1;
    int icount = 1;
    int jcount = 1;
    int isi = 0;
    int isj = 1;
    int addi = -1;
    int addj = 1;
    arr[i][j] = count*2;
    while(count<n*n){
        if(isj){
            for (int k = 0; k < jcount; ++k) {
                count++;
                j+=addj;
                arr[i][j] = count*2;
            }
            jcount++;
            addj=  addj*(-1);
            isi = 1;
            isj = 0;

        }
        else if(isi){
            for (int k = 0; k < icount; ++k) {
                count++;
                i+=addi;
                arr[i][j] = count*2;
            }
            icount++;
            addi=  addi*(-1);
            isj = 1;
            isi = 0;
        }
    }

    int k,l;
    for (k = 0; k < n; ++k) {
        for (l = 0; l < n; ++l) {
            if(l!=n-1 && (arr[k][l]-arr[k][l+1] == -2 || arr[k][l]-arr[k][l+1] == 2)){
                if(arr[k][l]<10){
                    printf("%d- ", arr[k][l]);
                }
                else printf("%d-", arr[k][l]);
            }
            else {if(arr[k][l] < 10)printf("%d  ",arr[k][l]); else printf("%d ", arr[k][l]);}

        }
        printf("\n");
        for (int m = 0; m < n; ++m) {
            if(k!=n-1 && (arr[k][m]-arr[k+1][m] == -2 || arr[k][m]-arr[k+1][m] == 2))
                printf("|  ");
            else printf("   ");
        }


        printf("\n");
    }
    return 0;
}