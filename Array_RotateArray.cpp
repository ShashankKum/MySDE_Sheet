//we have to right shift the array by k places.
//In this we reverse the entire array than reverse start to k-1 and than k to end.
//time taken will be O(N) and O(1) extra space.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reverse(nums.begin(),nums.end()); //reverse the entire vector, it will take O(N/2) time
        reverse(nums.begin(),nums.begin()+k); //this will take other O(N/2) time
        reverse(nums.begin()+k,nums.end());
    }
};