//We have an vector where 1<=nums[i]<=n, we need to find all the duplicates.
//In this we basically mark the element as negative ones its visited,so if we encounter negative again means its already visited.
//It will take O(N) time and O(1) extra space.

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        int n=nums.size(),k;
        for(int i=0;i<n;i++){
            k=abs(nums[i]); 
            if(nums[k-1]<0) //if value at index nums[i] is negative means its visited, and we are again visiting it
                v.push_back(abs(nums[i])); //so push its value
            else
                nums[k-1]=nums[k-1]*-1; //if not negative means its visited first time so make it negative
        }
        return v;
    }
};