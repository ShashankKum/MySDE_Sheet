//In this we have solved two sum problem in O(N) time complexity making use of hash table where average searching time is O(1).
//we stored value as key and index as value so that we can search(find) using required value.
//Other approach better than brute force is to sort the array and use two pointer by decrementing the right pointer if sum exceeds and incrementing
//left pointer if sum is less than total.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map <int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i])!=mp.end())   //if the value exists in hash table find will return the index or else mp.end()
            {
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
                break;
            }
            else
                mp[nums[i]]=i;
        }
        return ans;
    }
};