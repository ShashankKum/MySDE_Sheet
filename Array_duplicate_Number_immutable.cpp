//FLOYD CYCLE DETECTION ALGORITHM
//array is immutable(cant be modified)
//values are between (1-n-1)...only one term is repeating
//it is also known as hare and tortoise method

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