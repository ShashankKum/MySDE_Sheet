//Iterative approach using queue(level order traversal) to get the right view.
//Left view can also be done iteratively using queue, just print when i=0,in place of i=n-1(right view).

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue <TreeNode*> q;
        TreeNode* cur=root;
        vector<int> v;
        if(root==NULL) return v;
        q.push(cur);
        while(!q.empty()){
            int n=q.size(); //gives number of nodes in coming level
            for(int i=0;i<n;i++){
                cur=q.front();
                q.pop();
                if(i==n-1) v.push_back(cur->val); //for left use i=0
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return v;
    }
};

//Recursive solution for Right view. For left view use preorder traversal and a bool to mark the visited levels.
//In this maxlevel will contain the max level that has been touched now,and level will have the current level and obviously when we shift right or left
  level will increase,whenever level becomes greater than mexlevel value is added.

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        int maxlevel=-1;
        int level=0;
        vector<int>v;
        rview(root,level,maxlevel,v);
        return v;
    }
    void rview(TreeNode* root,int level,int &maxlevel,vector<int>&v){
        if(root==NULL){
            return ;
        }
        if(maxlevel<level){
            v.push_back(root->val);
            maxlevel=level;
        }
        rview(root->right,level+1,maxlevel,v);
        rview(root->left,level+1,maxlevel,v);
    }
};