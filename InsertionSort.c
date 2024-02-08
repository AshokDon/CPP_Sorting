#include<stdio.h>

void InsertionSort(int A[], int n){
    //1 4  5 |  2 8
    //j     i
    for(int i = 1 ; i < n ; i++){
        int temp = A[i];//take the first element from the unsorted array
        int j = i - 1;//start from the last element of the sorted array
        while(j >= 0 && A[j] > temp){//shift the element to the right if they are greater than the temp
            A[j+1] = A[j];
            j--;//-1
        }
        A[j+1] = temp;//insert the temp to the right position
    }
}
int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    //BubbleSort(A,n);
    InsertionSort(A,n);
    //time complexity of bubble sort is O(n^2)

    //array will be sorted 
    for(int i = 0 ; i < n ; i++){
        printf("%d ", A[i]);
    }
}
