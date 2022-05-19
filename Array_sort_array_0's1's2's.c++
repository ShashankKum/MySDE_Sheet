//Brute force approach is to sort the array but it will take nlogn time.
//next optimised approach is counting sort of counting the number of 0's,1's,2's and printing them in order it will take 2n time.
//most optimised approach is of Dutch national flag algo to use three pointers low mid and high. move wrt to mid till 
//here we move mid, if we are swapping for zero since we are moving from left so any 2 encountered would already be arranged but in right side zero is not necessary that it is arranged

#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n],l=0,mid=0,h=n-1;
	for(int i=0;i<n;i++)
	cin>>arr[i];
	while(mid<=h)
	{
	    if(arr[mid]==0)
	    {
	        swap(arr[mid],arr[l]);
	        mid++;
	        l++;
	    }
	    else if(arr[mid]==1)
	    mid++;
	    else
	    {
	        swap(arr[mid],arr[h]);
	        h--;
	    }
	}
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	return 0;
}
