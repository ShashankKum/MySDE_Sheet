//Longest common substring is similar to longest common subsequence.
//In this whenever there is not a match arr[i][j] simply becomes 0.

class Solution{
    public:
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        vector<vector<int>> ans(n+1,vector<int>(m+1,0));
        int ma=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                ans[i][j]=1+ans[i-1][j-1];
                else
                ans[i][j]=0;
                ma=max(ma,ans[i][j]);
            }
        }
        return ma;
    }
};