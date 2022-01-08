//Check if two binary tree are identical or not.
//Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
//Recursive solution,Iterative can be don eusing level order traversal.

class Solution {
public:
    void solve(TreeNode* p, TreeNode* q,bool &flag){
        if(p==NULL || q==NULL){
            if(p!=NULL || q!=NULL) flag=0; //if NULL occurs it must occur together in both nodes
            return;
        }
        if(p->val!=q->val) flag=0; //values must be same at each node
        solve(p->left,q->left,flag);
        solve(p->right,q->right,flag);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool flag=1;
        solve(p,q,flag); //send reference of flag
        return flag;
    }
};