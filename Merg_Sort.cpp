#include <iostream>
#include<vector>
using namespace std;
void Merg(int a[],int low,int mid,int high)
{
    //left array is from[low...mid]
    //right array is from[mid+1...high]
    int left=low,right=mid+1;
    vector<int>temp;
    while(left<=mid && right<=high)
    {
        if(a[left]<a[right])
        {
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            right++;
        }
    }
    //if the left pointer crossed
    //push all the right elemnts 
    while(right<=high)
    {
        temp.push_back(a[right++]);
    }
    //if the right pointer crossed
    //push all the left elemnts
    while(left<=mid)
    {
        temp.push_back(a[left++]);
    }
    //everything from temp goes to [low..high]
    for(int i=low;i<=high;i++)
    {
        a[i]=temp[i-low];
    }
}

void MergSort(int a[],int low,int high)
{
    if(low==high){
        return;
    }
    int mid=(low+high)/2;
    MergSort(a,low,mid);
    MergSort(a,mid+1,high);
    //now this is the return step where we have to merg them 
    Merg(a,low,mid,high);
}
int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	MergSort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
	    cout<<a[i]<<" ";
	}
	return 0;
}