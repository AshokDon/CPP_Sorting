#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	//sort STL Function on array
	int arr[5]={100,20,10,50,60};
	//sort the array in acending order
	sort(arr,arr+5);
	//sort(arr(address of first element),arr+n(adress after last element ))
	//sort function takes O(n logn) time complexity 
	//The algorithm used by sort() is IntroSort
	// Introsort being a hybrid sorting algorithm uses three sorting algorithm to minimise the running time, Quicksort, Heapsort and Insertion Sort
	for(int i=0;i<5;i++)
	{
	    cout<<arr[i]<<" ";
	}
	cout<<"\n";
	//sort the array in decending order
	sort(arr,arr+5,greater<int>());
		for(int i=0;i<5;i++)
	{
	    cout<<arr[i]<<" ";
	}
	//sort STL function on vector
	vector<int>ve={100,20,10,50,60};
	//sort the vector in acending order
	sort(ve.begin(),ve.end());
	//sort the vector in decending order
	sort(ve.begin(),ve.end(),greater<int>());
	
	return 0;
}