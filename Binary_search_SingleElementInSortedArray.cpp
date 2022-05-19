//In this there is a sorted array in which all the elements occur twice leaving one element which occurs only once we need to find it.
//This is solution using binary search in O(logn) time and O(1) space.
//In this the main logic to be used is that if in a half numberof elements are even and also not matching with mid than no need to look in that half as in that all elements would be occuring twice.


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)  return nums[0];
        int i=0,j=nums.size()-1,ans;
        while(i<=j){
            if(i==j)  return nums[i];
            int mid = (i+j)/2;
            bool even_length = (j-mid)%2==0;   //to chcek if the other half is of even length or not
            if(nums[mid]==nums[mid-1]){
                if(even_length)   //it means the second part is even so it must only have pairs no need to check it
                    j = mid-2;
                else  i = mid+1;  //if it is odd length than single occurring integer lies there only
            }
            else if(nums[mid]==nums[mid+1]){   
                if(even_length)
                    i = mid+2;
                else  j=mid-1;
            }
            else{
                ans =  nums[mid];
                break; 
            }
        }
        return ans;
    }
};