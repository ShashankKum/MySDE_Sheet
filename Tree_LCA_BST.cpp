//if both nodes value is greater than current node than its sure that it cant be lca of both,so we mmove to its left subtree to check for 
//a smaller value and so on. whenever we reach a condition such that neither both are bigger neither both are smaller means either we 
//have reached one of the nodes(so obviously it will be lca for both values) or one lies to its left and other to its right.

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val>p->val && root->val>q->val)
            return lowestCommonAncestor(root->left,p,q);
        else if(root->val<p->val && root->val<q->val)
            return lowestCommonAncestor(root->right,p,q);
        else
            return root; //root will be returned recursively
    }
};