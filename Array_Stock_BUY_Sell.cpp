//in stock buy and sell we need to get the maximum profit keeping in mind that we cant sell a stock unless it is bought first.
//so we need a pair of smallest value followed by largest value coming after it.
//so we keep on updating the min val and check for its consecutive profits.
//It will take O(N) time.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi=prices[0],n=prices.size(),ans=0;
        for(int i=1;i<n;i++){
            if(prices[i]>mi)
            ans=max(ans,prices[i]-mi);  //update the max profit till now
            else
            mi=prices[i]; //update mi to minimum value encountered till we reach current index
        }
        return ans;
    }
};