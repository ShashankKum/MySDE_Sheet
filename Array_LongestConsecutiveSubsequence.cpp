//We get the longest consecutive subsequence of positive integers in O(N) time and O(N) extra space.
//Here we first mark all the elements as true, than mark all the elements as false for which we have just smaller number in array,
  using this the only elements from which a consecutive sequence can begin will be left as true.
//Now loop again to get the max length of consecutive subsequence from all the subsequence available.


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mp;
        int ans=0,m,val;
        //marks all the element as true
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]=true;
        //if a just smaller element than current element exists it means it is not the begin of sequence so mark as false
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]-1)!=mp.end())
                mp[nums[i]]=false;
        }
        //checks the length of all consecutive subsequence
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==true){
                m=1; val=nums[i];
                while(true){
                    if(mp.find(val+1)!=mp.end()){
                        m++;
                        val++;
                    }
                    else break;
                }
                 ans=max(ans,m);
            }
        }
        return ans;
    }
};