//Iterative code using dynamic programming, in this we check if there is any previous element which is smaller than current and if yes,we store the 
  value at that index + 1, we do it for all the elements before it, and take the maximum.
//O(N^2)
  
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


//To get it in O(NlogN) time we use lower_bound(it takes logN time but works for sorted vector/array only).
//if element just greater than nums[i] is not found that means it is the max element and adding it will increase the sequence length so we simply push it in our sorted vector
//if element just greater than nums[i] is found we replace it with nums[i], since length of sequence will remain the same but will have smaller element.

int lengthOfLIS(vector<int>& nums) {
    vector<int> res;
    for(int i=0; i<nums.size(); i++) {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if(it==res.end()) res.push_back(nums[i]);
        else *it = nums[i];
    }
    return res.size();
}

//Explanation

[1,2,7,8,3,4,5,9,0]
1 -> [1]
2 -> [1,2]
7 -> [1,2,7]
8 -> [1,2,7,8]
3 -> [1,2,3,8]  // we replaced 7 with 3, since for the longest sequence we need only the last number and 1,2,3 is our new shorter sequence
4 -> [1,2,3,4] // we replaced 8 with 4, since the max len is the same but 4 has more chances for longer sequence
5 -> [1,2,3,4,5]
9 -> [1,2,3,4,5,9]
0 -> [0,2,3,4,5,9] // we replaced 1 with 0, so that it can become a new sequence



//Recursion Code, O(N^2)
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