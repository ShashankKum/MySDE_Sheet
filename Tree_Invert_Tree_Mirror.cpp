//Invert a binary tree is same as mirror of binary tree in this we have to swap childrens of each node respectively.
//So we do this work recursively in bottom up fashion.

class Solution {
public:
    void invert(TreeNode* root){
        if(root==NULL)  return;  //return if we reach NULL
        //recur
        invert(root->left);
        invert(root->right);
        //swap the child nodes
        TreeNode* l=root->left;
        TreeNode* r=root->right;
        root->left=r;
        root->right=l;
    }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};