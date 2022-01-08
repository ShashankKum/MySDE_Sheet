//For Pre-Order Traversal we first print the root than left than right.
//In this the value stored in stack are the root nodes so the values are simultaneously printed and we move to left subtree,when no left subtree exists
  we than pop the top value of stack and use it to traverse the respected right subtree.

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack <TreeNode*> s;
        vector <int> v;
        TreeNode* cur=root;
        while(cur!=NULL || !s.empty()){
        while(cur!=NULL){
            v.push_back(cur->val); //root nodes are pushed in vector
            s.push(cur);           //and also in stack
            cur=cur->left;
        }
        //there is no left node to cur existing now
        cur=s.top();
        s.pop();
        cur=cur->right;
        }
        return v;
    }
};

//Recursive solution
class Solution { 
    void solve(TreeNode* root,vector <int> &v){
        if(root==NULL) return;
        v.push_back(root->val);
        solve(root->left,v);
        solve(root->right,v);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> v;
        solve(root,v);
        return v;
    }
};