//to check the maximum length palindrome in a string in O(N^2) time using dp.
//in this we check for palindrome of substrings from length 1 than 2 than 3 and so on and keep storing them.

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    int n=s.size(),ans=1,z;
    bool arr[n][n];
    memset(arr,false,sizeof(arr));
    for(int i=0;i<n;i++)  //for one length substring
    arr[i][i]=true;
    for(int i=0;i<n-1;i++){ //check for all two length substrings
    if(s[i]==s[i+1]){
    arr[i][i+1]=true;
    ans=2;
    }
    }
    for(int k=3;k<=n;k++){ //k being the length of substring
    for(int i=0;i<=n-k;i++){
        int j=i+k-1;
        if(s[i]==s[j] && arr[i+1][j-1]){
        arr[i][j]=true;
        z=j-i+1;
        if(z>ans)
        ans=z;
        }
    }
    }
    cout<<ans;
	return 0;
}
