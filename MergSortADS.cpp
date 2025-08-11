


#include<bits/stdc++.h>
using namespace std;
int Fact(int n){
    if(n == 1) return 1;
    return n * Fact(n-1);
}
int FirstOcc(int *array, int n, int key){
    //base case 
    if(n == 0) return -1;

    if(array[0] == key) return 0;
    int sub_prob = FirstOcc(array+1,n-1,key);
    if(sub_prob==-1)return -1;
    return sub_prob+1;
}
int LastOcc(int *array, int n, int key){
    if(n == 0) return -1;

    int sub_prob = LastOcc(array+1, n - 1 ,key);
    if(sub_prob == -1){
        if(array[0] == key)return 0;
        else return -1;
    }
    return sub_prob+1;
}
int DivideandConq(int low , int high , vector<int>&A){
    //base case 
    if(low == high) return A[low];
    //divide 
    int mid = (low + high)/2;
    int p1 = DivideandConq(low , mid , A);
    int p2 = DivideandConq(mid + 1, high , A);
    int cur_sum = p1 + p2;
    return cur_sum;
}
void Merg(int low, int mid, int high , vector<int>&A, int n){
    int i = low;
    int j = mid + 1;
    vector<int>B(n);
    int k = 0;
    while(i <= mid && j <= high){
        if(A[i] <= A[j]){
            B[k++] = A[i++];
        }
        else{
            B[k++] = A[j++];
        }
    }
    while (i <= mid)
    {
        B[k++] = A[i++];
    }
    while(j <= high){
        B[k++] = A[j++];
    }
    //copy all this B into A;
    for(int i = 0 ; i < high - low + 1 ; i++){
        A[i + low ] = B[i];
    }
    
}
void MergSort(int low, int high, vector<int>&A, int n){
    if(low >= high)return;
    int mid = (low + high) / 2;
    MergSort(low , mid , A, n);
    MergSort(mid + 1, high , A, n);

    Merg(low, mid, high , A, n);

}
int main(){
    int n;
    cin >> n;
    vector<int>A(n);
    for(int i = 0 ; i < n ; i++)cin >> A[i];

    MergSort(0, n-1 , A, n);
    for(int i = 0 ; i < n ; i++){
        cout << A[i] << " ";
    }
}
