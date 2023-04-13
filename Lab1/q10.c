#include <stdio.h>
#include <string.h>
int anag(int n, char arr1[30], char arr2[30], int temp[n]); 
int main() {
    char s[30]; char a[30];
    for(int i = 0; i<30;i++){
    if(s[i] != '\n') scanf("%c", &s[i]); if(s[i] == '\n') break;} 
    int len = strlen(s);len = len-1; s[strlen(s) - 1] = '\0'; int temp[len]; 
    for(int i = 0; i<30;i++){
    if(a[i] != '\n') scanf("%c", &a[i]); if(a[i] == '\n') break;} a[strlen(s)] = '\0';
    if(anag(len,a,s,temp) == 1){ for(int i = 0; i<len; i++) {printf("%d ", (temp[i] + 1));} }
    else if(anag(len,a,s,temp) == 0) printf("NOT POSSIBLE");
}
int anag(int n, char arr1[30], char arr2[30], int temp[n])  { int flag;
    for(int i = 0; i<n; i++) {flag = 0;
    for(int j = 0; j<n; j++) {if(arr1[i] == arr2[j]){flag = 1; temp[i] = j; break;}} 
    if(flag == 0) return 0;}
    return flag; 
}    