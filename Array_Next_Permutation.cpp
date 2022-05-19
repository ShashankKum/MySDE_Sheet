//In this we first find i(the position after which all elements are in descending order),than we again look for an index(i) where //nums[i]>nums[k], and than swap(nums[k],nums[i])..to swap k with the next greatest element.
//than we reverse k+1 till end.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int l=nums.size()-1,i=l;
        //Get the point till which values are increasing
        while(i>0 && nums[i]<=nums[i-1]){
            i--;
        }
        //if we reach the start means we need the min number now to start with the permutoations
        if(i==0){
            swap(nums[i],nums[l]);
            sort(nums.begin(),nums.end());
        }
        //else we swap i-1'th index with the just greater value available from [i->l]
        else{
            for(int j=l;j>=i;j--){
                if(nums[j]>nums[i-1]){
                    cout<<j<<" "<<i-1;
                    swap(nums[j],nums[i-1]);
                    sort(nums.begin()+i,nums.end());
                    break;
                }
            }
        }
    }
};