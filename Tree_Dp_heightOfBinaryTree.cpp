//Height of a binary tree->recursion
//Whenever we will reach a node such that it has no more left of right node the l and r value for it will be 0 and so the entire function for that 
  terminal node will return (1+max(l,r)) that is 1,means the height of the terminal node considering it an individual tree will be 1, and so the same 
  will be return upwards and values will increase,for each node we will have the maximum of left and right subtree height +1.

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) //exit condition
            return 0;
        int l=maxDepth(root->left); 
        int r=maxDepth(root->right);
        return (1+max(l,r));
    }
};