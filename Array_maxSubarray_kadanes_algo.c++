//first give brute force approach which involves three loops of i,j,k.
//than optimise it by using two loops by adding simultaneaously which will decrease time complexity to 0(n^2).
//finally use kadanes algo to get it in done in linear time using two variables sum and max.

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n],sum=0,max;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    max=arr[0];
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum<0)   //if till that point sum is coming as 0 means there is no need of taking that subarray forward
        sum=0;
        if(sum>max) //update max if we get any subarray greater than max
        max=sum;
    }
    cout<<max;
	return 0;
}
