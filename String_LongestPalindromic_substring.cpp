//We use DP to make the solutions in order of O(n^2), by checking the previous smaller substring and just matching the first and last indice values of 
  new substring (arr[i+1][i+k-1]==1)&&(s[i]==s[i+k])

class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.size(),k,val=1;
        int arr[n][n];  //we make a n*n matrix the upper half of it representing the string with respective indices
        string ans=s.substr(0,1);       //initialize ans to the first element
     for(int i=0;i<n;i++) arr[i][i]=1;  //make all single elements 1 as they all are palindrome
        k=1;    //k represents the differnce between first and last indice of substring taken
        
        for(int i=0;i<n-k;i++){
          if(s[i]==s[i+1]){  //check for 2 length substring for palindrome
              arr[i][i+1]=1;
              ans=s.substr(i,2);
          }
            else arr[i][i+1]=0;
        }
        
        while(k<n){ //till the size is complete that of string
        k++;
        for(int i=0;i<n-k;i++){
         if((arr[i+1][i+k-1]==1)&&(s[i]==s[i+k])){ //generalised condition for furthersubstring
        arr[i][i+k]=1;
        ans=s.substr(i,k+1);
        }
        else arr[i][i+k]=0;
        }
        }

        return ans;
    }
};