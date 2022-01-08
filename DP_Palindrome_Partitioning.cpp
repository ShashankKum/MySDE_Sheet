//It is a variation of MCM,in this also we break the string at different values of k and check if it is palindrome recursively and wherever we get we 
  return true.

class Solution {
public:
    int arr[2000][2000];
    int bo[2000][2000];
    int check(string s,int i,int j)t //palindrome is also checked using dp to reduce the time 
    {
        if(i>=j)
            return 1;
        if(bo[i][j]!=-1)
            return bo[i][j];
        if(s[i]!=s[j])
            return 0;
        return bo[i][j]=check(s,i+1,j-1);
    }
    int part(string s,int i,int j){
        if(arr[i][j]!=-1)
        return arr[i][j];
        if(check(s,i,j)) //check if palindrome
        return 0;
        int ans=99999999,l,r;
        for(int k=i;k<j;k++){ //since we also have to take k+1
        if(arr[i][k]!=-1)
        l=arr[i][k];
        else
        l=part(s,i,k);
        if(arr[k+1][j]!=-1)
        r=arr[k+1][j];
        else
        r=part(s,k+1,j);
        int mi= 1+l+r;
        ans=min(mi,ans);
        }
        arr[i][j]=ans;
        return arr[i][j];
    }
    int minCut(string s) {
        memset(arr,-1,sizeof(arr));
        memset(bo,-1,sizeof(bo));
        int n=s.size();
        return part(s,0,n-1);
    }
};