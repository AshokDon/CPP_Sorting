#include <iostream>
using namespace std;
void insertionSort(int n,int arr[])
{
    for(int i=1;i<n;i++)
	{
	    int key=arr[i];
	    int j=i-1;
	    while(j>=0 && arr[j]>key)
	    {
	        arr[j+1]=arr[j];
	        j--;
	    }
	    arr[j+1]=key;
	}
	
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	insertionSort(n,arr);
	for(int i=0;i<n;i++)
	{
	    cout<<arr[i]<<" ";
	}

	return 0;
}