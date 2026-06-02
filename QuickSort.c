#include<stdlib.h>
#include <stdio.h>
#include <time.h>

void swap(int a[], int i,int j){
    int t=a[i];
    a[i]=a[j];
    a[j]=t;
}

int sort(int a[],int st,int end){
    int p=a[st],i=st,j=end;
    while (1) {
        while (i <= end && a[i] <= p) i++;
        while (j >= st && a[j] > p) j--;

        if (i >= j) break;
        swap(a, i, j);
    }
    swap(a,st,j);
    return j;
}

void quickSort(int a[],int st,int end ){
    if(st >= end) return;

    int mid = sort(a,st,end);
    quickSort(a,st,mid-1);
    quickSort(a,mid+1,end);
}

int main(){
    int n;
    printf("Enter size :");
    scanf("%d",&n);
    int a[n];
    // printf("Enter %d items :\n", n);
    for(int i=0; i<n;i++)
        a[i]=rand();
        // scanf("%d",&a[i]);

    double stTime =clock();
    quickSort(a,0,n-1);
    double endTime =clock();
    double t= (endTime -stTime)/CLOCKS_PER_SEC;
    // printf("Sorted Array :\n");
    // for(int i=0;i<n;i++)    
        // printf("%d\t",a[i]);
    printf("\nTime Taken: %.4f ms",t*1000);
    return 0;
}
