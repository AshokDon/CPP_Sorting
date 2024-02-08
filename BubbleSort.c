#include<stdio.h>
void BubbleSort(int A[], int n){
    int cnt = 0;
    for(int i = 0 ; i < n - 1 ; i++){
        int flage = 0;
        for(int j = 0 ; j < n- i -1 ; j++){
            cnt++;
            if(A[j] > A[j+1]){
                int temp = A[j+1];
                A[j+1] = A[j];
                A[j] = temp;
                flage = 1;//
            }
        }
        if(flage == 0){
            break;
        }
    }
    printf("%d\n",cnt);
}
int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    BubbleSort(A,n);
    //time complexity of bubble sort is O(n^2)

    //array will be sorted 
    for(int i = 0 ; i < n ; i++){
        printf("%d ", A[i]);
    }
}
