//To check wether a tree is height balanced...It is ht balanced if abs(left-right)<=1.

class Solution {
    //slight modification in height code
    int solve(TreeNode* root,int &res){
        if(root==NULL) return 0;
        int l=solve(root->left,res);
        int r=solve(root->right,res);
        if(abs(l-r)>1) res=-1; //condition determining tree is not balanced
        return (1+max(l,r));
    }
public:
    bool isBalanced(TreeNode* root) {
        int res=0;
        solve(root,res);
        if(res==-1) return false;
        return true;
    }
};