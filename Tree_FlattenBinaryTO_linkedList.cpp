//Recursive solution to flatten binary tree to linked list.

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *cur,*temp,*l;
        
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) return; //we have to reach the node with no grand-children
        
        flatten(root->left);
        
        if(root->left!=NULL){
           l=root->left; //store the left subtree
           root->left=NULL;   //make left node as NULL 
           temp=root->right; //store the right node as temp
           root->right=l; //connect the left subtree to right
           cur=root;
           while(cur->right!=NULL) cur=cur->right;
           if(temp!=NULL){
               cur->right=temp; flatten(temp); } //we also have to flatten the new added left subtree
        }

        else  flatten(root->right); //if root->left is NULL than flatten the right subtree  
    }
};