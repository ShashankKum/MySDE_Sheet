//Based on DP on Binary Tree,where we store the base results to reach our final answer(Bottom Up Approach)
//diameter is the distance between two nodes
//Tip: Longest Diameter can be formed within any part of left or right or it may loop over from left connecting root to right(1+l+r)
//ans will not change till we find a longer diameter.
//Hypothesis and Base Condition are same for height or diameter or any DP approach but the Induction will change.

class Solution {
    int solve(TreeNode* root,int &ans){
        //Base Condition
        if(root==NULL) return 0;
        //Hypothesis
        int l=solve(root->left,ans);
        int r=solve(root->right,ans);
        //Induction
        int temp=(1+max(l,r)); //same as we did for height,it will give the height of current node
        int val=max(temp,(1+l+r));
        ans=max(ans,val); //just we are updating the ans
        return temp; //same as it was returned in height,we need height of left and right in each case so we need to paas it same as height
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        if(root==NULL) return 0;
        solve(root,ans);
        return ans-1; //ans will give no. of nodes so to get the edges in between we will do -1
    }
};