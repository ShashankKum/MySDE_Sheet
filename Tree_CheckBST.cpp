//Check if a binary tree is binary search tree or not.
//A Binary Search Tree has all left childs smaller than root node and all right child greater than root nodes,The left and right nodes of each node are
  also BST.
//We will have a limit for every node to check it is greater than its ancestor whose right it is and smaller than the ancestor whose left it is..
  if(root->val>=max || root->val<=min)  flag=0;
//max is updated when left subtree is traversed and min when right subtree is traversed.

class Solution {
public:
    void solve(TreeNode* root,long long max,long long min,bool &flag){
        if(root==NULL) return;
        if(root->val>=max || root->val<=min)  flag=0; //If it happens it is not a BST
        solve(root->left,root->val,min,flag);  //if left than it must be less than root->val(max) 
        solve(root->right,max,root->val,flag);  //if right than must be greater than root->val(min)
    }
    
    bool isValidBST(TreeNode* root) {
        long long max=99999999999,min=-99999999999;
        bool flag=1;
        solve(root,max,min,flag);
        return flag;
    }
};