//In this we search an element in a roatated sorted array in O(logn) time
//We make use of binary search technique and make use of two functions, one to get the pivot where rotation takes place(so that we can look wether
//we have to serach in right or left part) and on ea general binary serach function to get the index of key value in O(logN) time.


//this is simple O(logN) approach.

int beg=0,end=nums.size()-1,mid;
        while(beg<=end)
        {
            mid=(beg+end)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[beg]<=nums[mid])
            {
                if(target<=nums[mid] && target>=nums[beg])
                    end=mid-1;
                else
                    beg=mid+1;
            }
            
            else
            {
                if(target>=nums[mid] && target<=nums[end])
                   beg=mid+1;
                else
                    end=mid-1;
            }
            
        }
        return -1;
    }


//this is O(2logN) approach
class Solution {
public:
    //binary search function to get the pivot point i.e the point where rotation is done, O(logN) time
    int pvt = 0;
    void getPivot(vector<int>& nums,int i,int j){
        if(i>j)  return;
        int mid = (i+j)/2;
        if(mid>0 && nums[mid]<nums[mid-1]){  //here we have the answer
            pvt = mid;
            return;
        }
        else if(nums[mid]>nums[j])
            getPivot(nums,mid+1,j);
        else if(nums[mid]<nums[j])
            getPivot(nums,i,mid-1);
    }
    
    //binary search function to get the element from the correct part, in which target can be there, O(logN) time
    int ind;
    void search(vector<int>& nums,int i,int j,int target){
        if(i>j){
            ind = -1;
            return;
        }
        int mid = (i+j)/2;
        if(nums[mid]==target){
            ind = mid;
            return;
        }
        else if(nums[mid]>target)  search(nums,i,mid-1,target);
        else search(nums,mid+1,j,target);
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size()-1;
        getPivot(nums,0,n);
        if(target<=nums[n])  search(nums,pvt,n,target);  //to check the correct portion in which target is present
        else   search(nums,0,pvt-1,target);
        return ind;
    }
};