//finding out the two odd times occuring elements in the array in O(N) time and O(1) extra space.
//hashing also does the same in O(N) time but it takes O(N) extra space to.


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n],xo=0,k;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        xo=xo^arr[i];
    }
    for(int i=0;i<=32;i++)
    {
        if((xo&(1<<i))>0)       //finding the first set bit in complete xor of array...to find the position where one bit is '0' and other is '1'
        {                      // of the two odd occuring elements
            k=1<<i;
            break;
        }
    }
    int num1=0,num2=0;
    for(int i=0;i<n;i++)  //on the basis of above categorizing them in two different sets so in each set there will be only one odd occurring
	                      //element as both will be in other set so the complete xor of both the sets will give us the number.
    {
        if((arr[i]&k)>0)
        num1 = num1^arr[i];
        else
        num2 = num2^arr[i];
    }
    cout<<num1<<" "<<num2; //printing both numbers
    return 0;
}