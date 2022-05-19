//FLOYD CYCLE DETECTION ALGORITHM
//In this there are n element array and values are between (1-n-1)...only one term is repeating.
//When there are duplicate elements the array will form a cycle and one element before the cyle point will be the duplicate element.
//since using floyd cyle dtection we used to get the cycle point in linkedlist, it is somewhat similar we just need to stop when slow and fast matches.
//array is immutable(cant be modified)
//If array would not be immutable we would have simply marked the indexes for the values visited as negative and get the work done.
//it is also known as hare and tortoise method.


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n],slow,fast;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    slow=arr[0];
    fast=arr[0];
    do{                   //fast pointer moves two steps and slow by one step
        slow=arr[slow];   //both inintially initialized to the zeroth index value
        fast=arr[arr[fast]];
    }while(slow!=fast);
    
    fast=arr[0]; //when they finally meet fast is again inititalized to zeroth array element while slow being at its position
    while(slow!=fast)  //than they move one step and now where they meet is the repeating element
    {
        slow=arr[slow];
        fast=arr[fast];
    }
    cout<<fast;
    return 0;
}