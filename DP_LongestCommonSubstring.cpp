//Longest common substring is similar to longest common subsequence.
//In this whenever there is not a match arr[i][j] simply becomes 0.
//O(N^2) time complexity

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


//recursive solution for the same
//If match do not occurs means the chain is broken so make the count as 0, in all cases we need to take three cases as we dont know wether the current match will go further or not

int lcs(int i, int j, int count)
{
 
    if (i == 0 || j == 0)
        return count;
 
    if (X[i - 1] == Y[j - 1]) {
        count = lcs(i - 1, j - 1, count + 1);
    }
    count = max(count,
                max(lcs(i, j - 1, 0),
                    lcs(i - 1, j, 0)));
    return count;
}