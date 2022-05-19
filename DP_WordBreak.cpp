//In this we have to see if the string can be constructed using the words in the dictionary.
//So we first insert all the words in an unordered set where avg insertion,deletion,retrieval time complexity is O(1).
//In this problem we can have repeating subproblems so we make use of dp.
//In simple recursion(backtracking) the time complexity will be O(2^N) since at each position we can have a division or not.
//Using dp the time complexity reduces to O(N^3)...i.e O(N^2) for subproblems and O(N) for substring complexity.


class Solution
{
public:
    int dp[1101];     //here we use the approach of dp by storing the sub problems.
    int recur(string s,unordered_set<string> dict,int i,int n){
        if(i>n)  return 1;
        if(dp[i]!=-1)  return dp[i];
        for(int k=i;k<=n;k++){
            if(dict.find(s.substr(i,k-i+1))!=dict.end())
                 if(recur(s,dict,k+1,n))
                    return dp[i]=1;
        }
        return dp[i]=0;
    }
    int wordBreak(string A, vector<string> &B) {
        memset(dp,-1,sizeof(dp));
        unordered_set <string> dict;
        for(int i=0;i<B.size();i++)
            dict.insert(B[i]);
        return recur(A,dict,0,A.size()-1);
    }
};