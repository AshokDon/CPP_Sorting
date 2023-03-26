#include<stdio.h>
#include<string.h>
//using namespace std;
typedef long long ll;
void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
void Reverse(int left, int right , int A[]){
    if(left > right)return;
    int temp = A[left];
    A[left] = A[right];
    A[right] = temp;
    Reverse(left+1,right-1,A);
}
int Fib(int n){
    if(n <= 1)return n;
    return Fib(n-1)+Fib(n-2);
}
int BinarySearchRe(int low , int high , int A[], int target){
    if(low > high)return -1;
    int mid = (low+high)>>1;
    if(A[mid] == target){
        return mid;
    }
    else if(A[mid] > target){
        return BinarySearchRe(low, mid - 1 ,A,target);

    }
    else{
        return BinarySearchRe(mid + 1, high , A, target);
    }
}
int BinarySearch(int n , int target , int A[]){
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = (low+high)>>1;
       
        if(A[mid]==target)return mid;
        else if(A[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}
int FirstOcurence(int *A, int n, int target){
    if(n==0)return -1;
    if(A[0]==target)return 0;
    //call by array
    int i = FirstOcurence(A+1,n-1,target);
    if(i==-1)return -1;
    return i+1;
}
int LastOcurrence(int *A, int n , int target){
    if(n==0)return -1;
    //make the call with out checking first
    int i = LastOcurrence(A+1,n-1,target);
    if(i==-1){
        if(A[0]==target)return 0;
        else return -1;
    }
    return i+1;
}

int Fun(int A[],int low , int high){//A,0,8,9
    int pivoti = A[low];//7
    int i = low;//0
    int j = high;//8
    while(i < j){
        while(A[i] <= pivoti && i <= high-1){
            i++;
        }
        while(A[j] > pivoti && j >= low + 1){
            j--;
        }
        if(i < j){
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    A[low]=A[j];
    A[j] = pivoti;
    return j;

}
void QuickSort(int A[],int low , int high){//0 6
    if(low > high)return;//(0 > 8)
    int P_index = Fun(A,low,high);//(A,0,8,9)// 7
    QuickSort(A,low,P_index-1);//0 to 6
    QuickSort(A,P_index+1,high);// 8 to 8
}
void Merge(int A[], int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int B[100];
    int x = 0;
    while(i <= mid  && j <= high){
        if(A[i] < A[j]){
            B[x++]=A[i++];   
        }
        else{
            B[x++]=A[j++];
        }
    }
    while(i <= mid){
        B[x++]=A[i++];
    }
    while(j <= high){
        B[x++]=A[j++];
    }
    for(i = low ; i <=high ; i++){
        A[i]=B[i-low];
    }
}
void MergeSort(int A[], int low, int high){
    if(low == high)return;
    int mid = (low+high)/2;
    MergeSort(A,low,mid);
    MergeSort(A,mid+1,high);
    Merge(A,low,mid,high);
    
}
int getMax(int A[], int n){
    int maxi = 0;
    for(int i = 0 ; i < n ; i++){
        if(A[i] > maxi)maxi = A[i];
    }
    return maxi;
}
void RadixSort(int A[], int n){
    int B[10][n];
    int maxi = getMax(A,n);
    int val = 1;
    while(maxi){
        int arr[10]={0};
        for(int i = 0 ; i < n ; i++){
            int  x = (A[i]/val)%10;
            if(x < 0) x = -x;
            B[x][arr[x]]=A[i];
            arr[x]++;
        }
        val = val*10;
        int cnt = 0;
        for(int i = 0 ; i < 10 ; i++){
            for(int j = 0 ; j < arr[i] ; j++){
                A[cnt++]=B[i][j];
            }
        }
        maxi = maxi/10;
    }
    int pos = 0, neg = 0;
    for(int i=0; i<n; i++) {
        if(A[i] < 0) {
            B[0][neg++] = A[i];
        }
        else {
            B[1][pos++] = A[i];
        }
    }
    for(int i=0; i<neg; i++) {
        A[i] = B[0][i];
    }
    for(int i=0; i<pos; i++) {
        A[neg+i] = B[1][i];
    }
}
int main(){
    TakeInput();
    int n ;
    scanf("%d",&n);
    int A[n];
    for(int i = 0; i < n ; i++){
        scanf("%d",&A[i]);
    }
    RadixSort(A,n);
    for(int i = 0 ; i < n ; i++){
        printf("%d ",A[i] );
    }
    
    
}






