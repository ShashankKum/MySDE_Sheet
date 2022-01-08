//The brute force way is to get the entire inorder traversal and dtore it in array and get the (k-1)th index ..it will take O(N) time for traversal and
  O(1) time to get the result , and will take O(N) space for array.
//Time and space will be same in this approach also in worst case but in average case time will decrease.
//The best way is to store the number of left childs in a node so that if left childs are less than given number of nodes we simply decrease the value
  of k by that much and dont travel its left subtree.
//In this as we need k'th smallest element so we keep on decresing k in Inorder traversal and we know that inorder
//traversal prints in increasing order for BST. so when k becomes 0 we save it as answer.
  
   class Solution {
public:
    int ans;
    void recur(TreeNode* root, int &k){  //here changes made in k reflects in each new function call
        if(root==NULL)
        return;
        recur(root->left,k);
        k--;
        if(k==0)
        ans=root->val;
        recur(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
      recur(root,k);
      return ans;
    }
};

//if we want to give the answer recursively
class Solution {
public:
    int recur(TreeNode* root, int &k){
        if(root==NULL)
        return 0;
        int l=recur(root->left,k); //if a non zero value is returned means no need to travel further we can just return the value recursively
        if(l!=0) return l;
        k--;
        if(k==0)
        return root->val;
        int r=recur(root->right,k);
        if(r!=0) return r;
        return 0;
    }
    int kthSmallest(TreeNode* root, int k) {
      return recur(root,k);
    }
};