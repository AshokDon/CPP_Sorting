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
void SelectionSort(int A[], int n){
    
    for(int i = 0 ; i < n - 1 ; i++){
        int min = i;//assume the first element is the minimum
        for(int j = i + 1 ; j < n ; j++){//start from the second element
            if(A[j] < A[min]){
                min = j;
            }
        }
        int temp = A[i];//swap the minimum element with the first element of the unsorted array
        A[i] = A[min];
        A[min] = temp;
    }
}
void Merge(int A[], int l , int m, int r){
    int i, j, k;
    i = l;
    j = m + 1;
    k = 0;
    int B[r+1];
    while(i <= m && j <= r){
        if(A[i] < A[j]){
            B[k++] = A[i++];
        }
        else{
            B[k++] = A[j++];
        }
    }
    while(i <= m){
        B[k++] = A[i++];
    }
    while(j <= r){
        B[k++] = A[j++];
    }
    for(int i = l, k = 0 ; i <= r ; i++, k++){
        A[i] = B[k];
    }

}
void MergeSort(int A[], int l, int r){
    if(l < r){// l = 0 and r = 1
        int m = (l + r) / 2;//m = 0
        //divide the array into two parts
        MergeSort(A, l , m); // 0 0
        MergeSort(A, m + 1, r);// 1 1
        Merge(A, l, m, r);// 

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

    //InsertionSort(A,n);

    //SelectionSort(A,n);
    //time complexity of bubble sort is O(n^2)

    //array will be sorted 
    MergeSort(A,0,n-1);
    for(int i = 0 ; i < n ; i++){
        printf("%d ", A[i]);
    }
}
