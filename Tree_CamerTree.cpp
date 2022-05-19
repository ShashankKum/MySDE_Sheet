//In this we need to return the minimum camera needed to cover the entire tree, keeping in mind that camera at a node can cover its child
  nodes and its parent.
//-1 -> not covered, 1->camera placed here, 0->covered


class Solution {
public:
    int ans=0;
    int recur(TreeNode* root){
        if(root==NULL)  return 0;  //if node is null means we dont need to think of it so we keep it in covered(0) category
        
        int l = recur(root->left);
        int r = recur(root->right);
        
        if(l==-1 ||  r==-1){   //if any of its child is uncovered we need to place camera here
            ans++;
            return 1;
        }
        else if(l==0 && r==0)  //if both the child nodes are covered(but they dont have camera placed at them), means it is un covered
            return -1;
        return 0;              //it means none of the child nodes are un covered and either of them have a camera which will cover this node
    }
    int minCameraCover(TreeNode* root) {
        if(recur(root)==-1) ans++;   //if the root node remains -1
        return ans;
    }
};