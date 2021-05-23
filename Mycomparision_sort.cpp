#include <iostream>
#include<algorithm>
using namespace std;
struct point{
    int x,y;
};
//my own comparision 
bool mycom(point p1, point p2)
{
    //sort based on x value mean first value
    return (p1.x<p2.x);
    //if you want to sort based on y value mean second value
    //change x with y in the statement as --> return (p1.y<p2.y)
}

int main() {
    point arr[]={{3,10},{2,8},{5,4}};
    sort(arr,arr+3,mycom);
    for(auto i:arr)
    {
        cout<<i.x<<" "<<i.y<<" "; 
    }
	
	return 0;
}