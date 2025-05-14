#include<stdio.h>
void merge(int arr[],int low,int mid,int high) {
    int B[10];
    int i=low,j=mid+1,k=low;
    while(i<=mid && j<=high) {
        if (arr[i]<=arr[j]) {
          B[k]=arr[i];
          i=i+1;
        }
        else {
            B[k]=arr[j];
            j=j+1;
        }
        k=k+1;
    }
    while (i <= mid) {
        B[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high) {
        B[k] = arr[j];
        j++;
        k++;
    }

    for (int l = low; l <= high; l++) {
        arr[l] = B[l];
    }
}
void mergeSort(int arr[], int low, int high) {
    if (low<high) {
        int mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main() {
    int arr[10],n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    printf("Sorted array: ");
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}