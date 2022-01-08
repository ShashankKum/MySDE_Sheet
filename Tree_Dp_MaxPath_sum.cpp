//In this we have to find the max path sum from any node to any node, given that node values can be negative too.
//The main logic used is if any of the right or left subtree max path sum comes to -ve make it 0 for further operations, as its
//better to only take root->val than adding negative childrens.
//we have a ans which keeps on updating the max path sum till current node.(traversed from bottom to up).
//Logic is somewhat similar to that of diameter of tree.
//Time taken is O(N) and O(1) extra space taken if we avoid the space due to recursion.

class Solution {
public:
    int ans=-10005;  //initialized to INT_MIN
    int travel(TreeNode* root){
        if(root==NULL)
            return 0;
        int l=max(travel(root->left),0);  //if left part adds up to negative value its better to avoid it and take 0 inplace of it
        int r=max(travel(root->right),0); //same logic
        int k=max(l,r);
     int z=root->val+l+r; //we add up root+left+right, as we know that if any of left or right was -ve it must have been changed to 0
        ans=max(ans,z);  //we keep on updating ans to max path sum found till now
        return (root->val)+k; //we will return the best of left and right + root->val each time
    }
    int maxPathSum(TreeNode* root) {
        travel(root);
        return ans;  //return ans
    }
};