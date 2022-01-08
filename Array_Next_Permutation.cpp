//In this we first find k(the position after which all elements are in descending order),than we again look for an index(i) where //nums[i]>nums[k], and than swap(nums[k],nums[i])..to swap k with the next greatest element.
//than we reverse k+1 till end.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),k=n-1;
        if(n==1) return;
        int a=-1;  //a initialized to minimum value
        while(k>=0 && nums[k]>=a){  //k will finally reach the index after which all elements are sorted in descending order
            if(k==0){  //means we have reached the last permutation so next one will be the first permutation
               reverse(nums.begin(),nums.end()); 
               return; 
            }
            a=nums[k];
            k--;
        }
        int i=n-1;
        while(nums[i]<=nums[k]) i--; //first element from last where nums[i]>nums[k]
        swap(nums[k],nums[i]);
        reverse(nums.begin()+(k+1),nums.end()); //reverse the part after k
    }
};