//Longest Consecutive Integer Sequence
//take all elements in vector than insert all in unordered_set(where all operations average time is O(1)), so that all unique elements occur and 
  there searching time(find) is O(1).
//look for all consequtive elements when an element occurs such that no smaller than it is present in the vector...
//time complexity will be  O(N)..insert in set + O(N)..move through vector + O(N)..loop through consecutive elements.
//it takes O(N) time complexity and O(N)..set space complexity.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> s;
        int n = nums.size();
        int count,ans=0,x;
        for(int i=0;i<n;i++)
            s.insert(nums[i]);
        for(int i=0;i<n;i++)
	   {
	    count=1;
	    if(s.find(nums[i]-1)==s.end())
	    {
	        x=nums[i];
	        while(s.find(x+1)!=s.end())
	        {
	            count++;
	            x=x+1;
	        }
	    }
	    ans=max(ans,count);
	   }
	return ans;
    }
};