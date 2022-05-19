//Wherever sorted array is given we need to understand that we have to use binary search.

//In this we use binary search to get the leftmost and rightmost index of an element of an array
//Time complexity of this is O(logn)
//We can use this first and last positions of element to get the number of occurences of element.

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};      //if size of array is 0
        int i=0,j=nums.size()-1;
        int l,r,mid;
        while(i<=j){        //used to get the rightmost element
            mid=i+(j-1)/2;  //to avoid overflow
            if(nums[mid]<=target)  i=mid+1;
            else  j=mid-1;
        }
        r=i;
        i=0,j=nums.size()-1;
        while(i<=j){        //used to get the leftmost element
            mid=i+(j-1)/2;
            if(nums[mid]>=target)  j=mid-1;
            else  i=mid+1;
        }
        l=j;
        if((r-l)==1)  return{-1,-1};   //if element is not found in the array
        return {l+1,r-1}; //l+1 and r+1 will give us exact left and right most positions
    }
};