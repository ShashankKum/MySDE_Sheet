//To detect the next greatest element using stack to decrease time complexity from O(N^2) to O(N).
//In this case the array is circular.

//It takes O(n) extra space and and O(2N) time

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> ans;
        int l=nums.size();
        for(int i=l-2;i>=0;i--)  //push all elements in stack in reverse manner so that we can check for greater element in circular cycle
            s.push(nums[i]);
        for(int i=l-1;i>=0;i--){
            while(!s.empty() && nums[i]>=s.top()){
                s.pop();
            }
            if(!s.empty())
                ans.push_back(s.top());
            else ans.push_back(-1);
            s.push(nums[i]);  //in each case the current value will be pushed
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};