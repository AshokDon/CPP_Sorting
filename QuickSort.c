#include<stdio.h>
int Merge(int A[], int low , int high, int pivot){
    int key = A[pivot];
    int s = low;
    int e = high;
    while(s < e){
        while(A[s] <= key){
            s++;
        }
        while(A[e] > key){
            e--;
        }
        if(s < e){
            int temp = A[s];
            A[s] = A[e];
            A[e] = temp;
        }

    }
    int temp = A[e];
    A[e] = A[pivot];
    A[pivot] = temp;
    return e;
}
void QuickSort(int A[], int low, int high){
    if(low < high){
        int pivot = low;
        pivot = Merge(A, low, high, pivot);
        QuickSort(A, low, pivot - 1);
        QuickSort(A, pivot + 1, high);

    }
}
int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    
    QuickSort(A,0,n-1);
    for(int i = 0 ; i < n ; i++){
        printf("%d ", A[i]);
    }
}
