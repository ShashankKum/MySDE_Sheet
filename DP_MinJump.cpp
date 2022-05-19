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


//The best solution is O(N) solution, in this we make use of three variables, 
  1. maxReach -> it will contain the max index we can reach from current index, it will updated at each step -> maxReach = max(maxReach, i + arr[i]);
  2. step -> It will hold the steps in our hand,how much we can move from now, it will be updated once the steps becomes 0(means we have traversed through all element possible to reach
             from the last element where we updated.
              
             if (step == 0) {
             jump++;
             if(i>=maxReach)
               return -1;
             step = maxReach - i;
             } 

  3. jump -> it will increase once step becomes zero, since it means atleast one jump is utilised


class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)  return 0;
        int step=nums[0],max_ind=nums[0],n=nums.size(),jump=1;
        for(int i=1;i<n;i++){
            if(step==0){
                step =  max_ind-i+1;
                jump++;
            }
            step--;
            max_ind = max(max_ind,i+nums[i]);
        }
        return jump;
    }
};