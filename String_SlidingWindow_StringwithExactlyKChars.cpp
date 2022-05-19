//Substring with exactly k distinct characters = Substring with atmost k distinct characters - Substring with atmost (k-1) distinct characters.
//we move till the size of window just becomes greater than k ones that happens we loop over till it again get back to size k.
//it is an O(N) time efficient approach.


class Solution {
public:
    int atmost(vector<int>& nums, int k){
        unordered_map <int,int> mp;
        int i=0,j=0,n=nums.size();
        int cnt=0;
        while(i<n){
            mp[nums[i]]++;
            while(mp.size()>k){
                mp[nums[j]]--;
                if(mp[nums[j]]==0)
                    mp.erase(nums[j]);
                j++;
            }
            cnt += (i-j+1);
            i++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};