//This is similar to unbounded knapsack where we can take multiple occurences of element,to get the desired sum.
//If the element is <= target we have two options either to take the value or to exculde,but if element is greater than target 
//than we can only exclude the element.
//we use a 2D vector to store the results hence to remove overlapping.

class Solution {
public:
    vector<vector<int>> a;
    int recur(vector<int>& coins,int i,int target){
        if(i<0 && target!=0) //if we have reached the start of array but target is still not 0,means no sol found
            return 0;
        if(target==0)  //if target becomes 0 it means we have found a solution
            return 1;
        if(a[i][target]!=-1)  //if the value is already stored we simply return it rather than recurring
            return a[i][target];
        if(coins[i]<=target)
            a[i][target]=recur(coins,i,target-coins[i])+recur(coins,i-1,target);
        else
            a[i][target]=recur(coins,i-1,target);
        return a[i][target];
    }
    int change(int amount, vector<int>& coins) {
        a.resize(coins.size()+1,vector<int>(amount+1,-1));
        return recur(coins,coins.size()-1,amount);
    }
};