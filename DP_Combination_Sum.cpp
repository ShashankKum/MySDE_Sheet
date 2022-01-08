//It is same as coin change problem where we have to get the maximum combinations,but in this we also print those combinations.
//In order to do so we use backtracking idea of do,recur,undo.
//we push the element in vector call the function and again pop the current added element.
class Solution {
public:
    vector<vector<int>> ans;
    void sum(vector<int>& nums,int i,int target,vector <int>& v){
        if(i<0 && target!=0)
        return;
        if(target==0){ //if this happens means we have got a set
            ans.push_back(v);
            return;
        }
        if(nums[i]<=target){
            //do
            v.push_back(nums[i]);
            //recur
            sum(nums,i,target-nums[i],v);
            //undo
            v.pop_back();
            sum(nums,i-1,target,v);
            }
        else
            sum(nums,i-1,target,v);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector <int> v;
        sum(candidates,n-1,target,v);
        return ans;
    }
};