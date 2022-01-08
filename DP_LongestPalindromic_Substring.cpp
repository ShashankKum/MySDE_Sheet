//if a substring is palindrome make it 1 or else 0.
//based on idea that if a substring is palindrome than its both end letters must be same and the inner substring must also be a palindrome (arr[i+1][i+k-1]==1)&&(s[i]==s[i+k]).

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(),k,val=1;
        int arr[n][n];
        string ans=s.substr(0,1);
        for(int i=0;i<n;i++) arr[i][i]=1;
        k=1;
        for(int i=0;i<n-k;i++){
          if(s[i]==s[i+1]){ 
              arr[i][i+1]=1;
              ans=s.substr(i,2);
          }
            else arr[i][i+1]=0;
        }
        while(k<n){
        k++;
        for(int i=0;i<n-k;i++){
           if((arr[i+1][i+k-1]==1)&&(s[i]==s[i+k])){
            arr[i][i+k]=1;
            ans=s.substr(i,k+1);
           }
            else arr[i][i+k]=0;
        }
        }
      cout<<ans;
        return ans;
    }
};