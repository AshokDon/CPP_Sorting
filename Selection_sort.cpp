#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void SelectionSort()
{
    int temp[n];
	for(int i=0;i<n;i++)
	{
	    int mid_ind=0;
	    for(int j=1;j<n;j++)
	    {
	        if(arr[j]<arr[mid_ind])
	        {
	            mid_ind=j;
	        }
	    }
	    temp[i]=arr[mid_ind];
	    arr[mid_ind]=INT_MAX;
	}
	for(int i=0;i<n;i++)
	{
	    cout<<temp[i]<<" ";
	}
}
void SelectionSortoptimization()
{
    for(int i=0;i<n;i++)
    {
        int mid_ind=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[mid_ind])
            {
                mid_ind=j;
            }
        }
        swap(arr[i],arr[mid_ind]);
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
	//selection shor 
	SelectionSort();
	
	return 0;
}