#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void BubbleSort()
{
    //Bubble short 
    //always bubble up the highest element to last index
	for(int i=0;i<n-1;i++)
	{
	    for(int j=0;j<n-1;j++)
	    {
	        if(arr[j]>arr[j+1])
	        {
	            swap(arr[j],arr[j+1]);
	        }
	    }
	}
	for(auto i:arr)
	{
	    cout<<i<<" ";
	}
}
void BubbleSortoptimization()
{
    //Bubble Sort with better optimization
    for(int i=0;i<n-1;i++)
    {
        int swaped=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swaped=1;
            }
        }
        if(swaped==0)
        {
            break;
        }
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
	BubbleSort();
	//Bubble Sort with optimization
	BubbleSortoptimization();
	return 0;
}