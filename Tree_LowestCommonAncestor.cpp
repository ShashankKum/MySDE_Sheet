//Lowest Ancestor in a tree is the nearest node connecting the given two nodes.
//Hypothesis still remains the same as we travel through the tree in bottom up fashion.
//In Base we add one more step that if we get any of the p or q, we return that node, as there might me a condition that both nodes are connected
  in this case the first traversed node will be the answer...4->3->5...where p is 4 and q is 5, so 4 will be the answer.
//If both left and right are not null than that is our answer.
//Time complexity is O(N).


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	    //Base Condition
        if(root==NULL) return NULL;
        if(root==p || root==q) return root; //if any of the nodes is found than lca can be above it but not below so return it
		//Hypothesis
        TreeNode *l = lowestCommonAncestor(root->left,p,q);
        TreeNode *r = lowestCommonAncestor(root->right,p,q);
		//Induction
        if(l==NULL && r==NULL) return NULL;
        if(l!=NULL && r!=NULL) return root;
        else{
            return (r!=NULL)?r:l; //return whichever is not null
        }
    }
};