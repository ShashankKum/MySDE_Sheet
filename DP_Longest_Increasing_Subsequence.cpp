//Iterative code using dynamic programming, in this we check if there is any previous element which is smaller than current and if yes,we store the 
  value at that index + 1, we do it for all the elements before it, and take the maximum.
  
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int arr[n],l,ans=1;
        arr[0]=1;
        for(int i=1;i<n;i++){
            l=1;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    if(arr[j]+1>l)
                        l=arr[j]+1;
                }
            }
            arr[i]=l;
            ans=max(arr[i],ans);
        }
        return ans;
    }
};


//Recursion Code
//if value at j(0<=j<i) is less than value at i recur for (0->j).
//we will have ma which will store the maximum value obatained from any sub array.

class Solution {
public:
    int arr[2500][2500];
    int recur(int i,vector<int>& nums,int &ma){
        //Base case
        if(i==0)
         return 1;
        if(arr[0][i]!=-1)
            return arr[0][i];
        int l,ans=1;
        for(int j=i-1;j>=0;j--){
            arr[0][j]=recur(j,nums,ma);
            if(nums[j]<nums[i] && 1+arr[0][j]>ans)
            ans=1+arr[0][j]; //maximum answer including the i'th element
        }
        ma=max(ma,ans);
        return arr[0][i]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(arr,-1,sizeof(arr));
        int n=nums.size();
        if(n==1) return 1;
        int ma=0;
        recur(n-1,nums,ma);
        return ma;
    }
};