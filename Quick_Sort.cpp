#include <iostream>
using namespace std;
int position(int a[],int lb,int ub)
{
    int key=a[lb];
    int start=lb,end=ub;
    while(start<end)
    {
        while(a[start]<=key)
        {
            start++;
        }
        while(a[end]>key)
        {
            end--;
        }
        if(start<end)
        {
            swap(a[start],a[end]);
        }
    }
    swap(a[lb],a[end]);
    return end;
}


void QuickSort(int a[],int low,int high)
{
    if(low<high)
    {
        int loc=position(a,low,high);
        QuickSort(a,low,loc-1);
        QuickSort(a,loc+1,high);
    }
}

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	QuickSort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
	    cout<<a[i]<<" ";
	}
	return 0;
}