//given sorted array convert it into preorder traversal of a Balanced BST.
//we can do it by placing the mid element as root node each time and making its left part as left children and right part as right children of BST.

class Solution {
public:
    void bst(vector<int> nums,vector<int>& v,int i,int j){
        if(i>j)
        return;
        int mid=(i+j)/2;
        v.push_back(nums[mid]);
        bst(nums,v,i,mid-1);
        bst(nums,v,mid+1,j);
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();
        bst(nums,v,0,n-1);
        return v;
    }
};