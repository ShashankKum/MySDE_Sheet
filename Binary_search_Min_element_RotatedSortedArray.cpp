//Code to get the minimum element in roatted sorted array, it can also be used to get the number of rotations.

//In this we check if first element is smaller than the last element means there was no rotation hence we return the first element.
//Else we know that there is rotation and we store last element as min element and than compare it with mid value,
//if mid value is greater than last we know that smallest element can be present in right half and we ignore left half.
//else if mid value is smaller than we store mid element as min and check for the left half by ignoring right and so on.
//It will be done in O(logn) time.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0,j=nums.size()-1,mi=nums[j],mid;
        if(nums[i]<=nums[j])  //no rotations have been made
            return nums[i];
        while(i<j){
            mid=i+(j-i)/2;
            if(nums[mid]>mi)  //check for right half
                i=mid+1;
            else if(nums[mid]<mi){  //check for left half
                j=mid;
                mi=nums[j];
            }
        }
        return mi;
    }
};