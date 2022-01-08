//In this we merge the sorted arrays without using extra space.
//Time complexity is O(n*m) and space complexity is O(1).
//In this we keep on iterating through one array while keeping the pointer always at starting index in another array(but rearranging the second
//array always whenever there is a swap to help it always stay in sorted position.


#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,m,i,j,l;
	cin>>n>>m;
	int a[n],b[m];
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<m;i++)
	cin>>b[i];
	i=0,j=0;
	while(i<n)
	{
	    if(a[i]<b[j])
	    i++;
	    else
	   {
	    swap(a[i],b[j]);
	    i++;
	    l=b[j];
	    for(int k=j+1;k<m;k++)
	    {
	        if(b[k]<l)
	        {
	            b[k-1]=b[k];
	            if(k==m-1)
	            b[k]=l;
	        }
	        else
	        {
	        b[k-1]=l;
	        break;
	        }
	    }
	   }
	}
	for(int k=0;k<n;k++)
    cout<<a[k]<<" ";
	for(int k=0;k<m;k++)
	cout<<b[k]<<" ";
	return 0;
}
