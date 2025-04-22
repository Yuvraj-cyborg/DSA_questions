#include<stdio.h>
#include<string.h>
char A[100], B[100];
int max(int,int);
int lcs(int x,int y) {
    if(A[x]=='\0' ||  B[y]=='\0') 
    return 0;
    else if(A[x]==B[y]) {
        return 1+lcs(x+1,y+1);
    } 
    else {
        return max(lcs(x+1,y),lcs(x,y+1));
    }
}

int max(int a,int b) {
    return (a>b) ? a : b;
}

void main() {
    printf("Enter the first string: ");
    gets(A);
    printf("Enter the second string: ");
    gets(B);
    int length = lcs(0,0);
    printf("Length of LCS is %d\n",length);
}
