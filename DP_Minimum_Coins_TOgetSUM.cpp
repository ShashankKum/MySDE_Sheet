//Variation of 0-1 Knapsack
//In each case we can either take the last element or not depending it is less than equal to sum or not.
//We keep storing these values so if we look for the same value again we can use the earlier calculated value.

class Solution {
public:
    int arr[13][10002];
    int mi(vector<int>& coins,int sum,int i){
        //Base case
        if(i<0 && sum!=0) //if sum remains greater than zero even when we have reached the end means no answer found
        return 99999;
        if(sum==0)
        return 0;
        if(arr[i][sum]!=-1)
            return arr[i][sum];
        if(coins[i]<=sum) //try both the possibility of inclusion and exclusion
        return arr[i][sum]=min(1+mi(coins,sum-coins[i],i),mi(coins,sum,i-1));
        else //coin is not considered
        return arr[i][sum]=mi(coins,sum,i-1);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        memset(arr,-1,sizeof(arr));
        int ans = mi(coins,amount,n-1);
        if(ans==99999)  return -1;
        else  return ans;
    }
};