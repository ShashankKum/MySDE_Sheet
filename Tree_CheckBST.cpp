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

//Another bottom up approach

//In this we basically move bottom up and in each case return the max and min pair of each subtree.
//We than check for each root of subtree wether it is greater than max value of left subtree and smaller than min value of right subtree
//This just requires a single postorder traversal so we can do it in O(N) time.

class Solution {
public:
    #define pi pair<long long int,long long int>  //max,min
    #define ll long long int
    bool flag=true;
    
    pi recur(TreeNode* root){
        if(root==NULL)  return {-9999999999,9999999999};  //Base condition if root beacomes NULL
        pi l = recur(root->left);
        pi r = recur(root->right);
        ll ma = max(r.first,(ll)root->val);
        ll mi = min(l.second,(ll)root->val);
        if(root->val<=l.first || root->val>=r.second)  flag=false;   //if for any subtree bst condition not fulfilled than entire tree is not a BST
        return {ma,mi};               //max of right subtree, min of left subtree being returned
    }
    
    bool isValidBST(TreeNode* root) {
        recur(root);
        return flag;
    }
};