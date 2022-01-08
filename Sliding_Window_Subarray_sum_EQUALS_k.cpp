//To get Number of Subarray having sum equal k when all numbers are positive in array we use variable size sliding window concept to get time complexity from O(N^2) to O(N).
//Initially we have i=0,and j=0, and we increase j till sum of subarray (i,j) becomes k,if sum exceeds k we now keep j as it is and increment i till sum is <= k.
//In this whenever we have sum k we know that adding elements in that subarray further will just increase the value, so we increment i till (sum<=k), than we increment j again till
//sum=k, and we repeat it in loop, and we get our result in O(N) time.

//But if values are negative also we need to use extra space using map to get our value.

//Using extra space of O(N) for hash table we can reduce time complexity from O(N^2) in brute force to O(N).
//We use a hash table to store frequencies of prefix sum in hash table.
//The number of times we have encountered (sum-k), that many more solutions we have till that index.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int> mp;  //hash table to store the frequencies of prefix sum
        int sum=0,ans=0;   //ans will count the number of continuous subarrays whose sum equals to k, sum will have prefix sum
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];      //calculating the prefix sum
            if(sum==k)         //if prefix sum has become k means we have a subarray from 0->i
                ans++;
            if(mp[sum-k]>0)   //if prefix sum has already encountered (sum-k) than we have sol from there till i'th index
                ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};