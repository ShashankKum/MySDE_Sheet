//Iterative solution using two stacks.
//In the first stack(s1) we initially push the root node and than we move in a while loop which runs till s1 is not empty, now we push the top element
  of s1 in s2 and pop it from s1,and push the left and right nodes if available of that element in s1, and s2 is the list to be printed.
//Trick: Whatever which comes first in stack will be printed last.

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack <TreeNode*> s1;
        stack <TreeNode*> s2;
        vector <int> v;
        if(root==NULL) return v;
        TreeNode* cur;
        s1.push(root);
        while(!s1.empty()){
            cur=s1.top();
            s1.pop();
            s2.push(cur);
            if(cur->left!=NULL)
                s1.push(cur->left);
            if(cur->right!=NULL)
                s1.push(cur->right);
        }
        while(!s2.empty()){
            cur=s2.top();
            s2.pop();
            v.push_back(cur->val);
        }
        return v;
    }
};

//Recursive Solution
class Solution {
    void solve(TreeNode *root,vector <int> &v){
        if(root==NULL) return;
        solve(root->left,v);
        solve(root->right,v);
        v.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
       vector <int> v;
        solve(root,v);
        return v;
    }
};