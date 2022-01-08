//it can also be solved using normal combination sum by using vector of hash set to remove the duplicates but it will increase the space and time so we use this method of recursion+
  iteration.

//In this we use bactracking to generate all posiible combinations,as we push than recur and again pop.
//since we need all combinations such that no duplicates are found, so we use the idea that if a particular element 
//is taken at a particular index than we will not try to place the same value again at the same position.
//Tme taken will be O((2^n)*k) where we know that any array of length n can generate 2^n subsequences at max,so recursion time 
//will be O(2^n) but we are again pushing each combo in ans so assuming average length of each combo as k,total time becomes
//O((2^n)*k).
//Space is O(k*x) where k is the avg length of combos and x as number of combo ignoring the space taken by recursion.


class Solution {
public:
    vector<vector<int>> ans;
    void combo(int i,int sum,vector<int>& nums,vector<int> v){
        int n=nums.size();
        if(sum==0){             //if sum becomes zero means we have successful combo
            ans.push_back(v);
            return;
        }
        if(i>=n)      //this means we were unsuccessful so return
            return;
        for(int j=i;j<n;j++){     //trying for all possible values that can fit for a particular position
          if(j>i && nums[j]==nums[j-1]) //done to avoid duplicates,if we have x as our first element than again taking x as 1st
                continue;                 //element will result in duplicate so we avoid it
            
            if(sum<nums[j]) //if nums[j] is greater than sum than nums[j+1] will obviously be greater than sum as it is sorted
                return;     //so just return
            
            else{
                v.push_back(nums[j]);              //do
                combo(j+1,sum-nums[j],nums,v);     //recur
                v.pop_back();                      //undo
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int> v;
        sort(candidates.begin(),candidates.end());  //since we need to get combinations in sorted manner
        combo(0,target,candidates,v);
        return ans;
    }
};