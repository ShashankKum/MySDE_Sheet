//we use memoization, we store the prvious calculated values so that we dont need to recur again
//time complexity is O(n^2)
//for simple recursion it becomes O(n!) -> O(N*(N-1)*(N-2)*(N-3)....1)

class Solution {
public:

    int dp(vector<int>& nums,int a,int l,vector<int>& v){
        int ans=99999;  //variable which will store the min jumps from an index to reach end
        //base condition
        if(a==(l-1))    //if reaches the end than no more jumps required
            return 0;
        if(v[a]!=-1)  return v[a];   //if we already have min jumps from a'th index than return the same
        
        for(int i=1;i<=nums[a];i++){
            if(a+i < l)
                ans = min(ans,1+dp(nums,a+i,l,v)); 
        }
        
        v[a]=ans;   //stores the min jumps required from a'th index to reach end
        return v[a];  //returns min jump for each index
    }
    int jump(vector<int>& nums) {
        int l=nums.size();
        vector<int> v(l,-1); //vector to store min jumps from all the index to reach end
        return dp(nums,0,l,v);
    }
};