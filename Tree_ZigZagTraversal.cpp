//To perform zig zag traversal we just need to do same as level order traversal just need to reverse the vector for alternate levels, since we need the result in zig zag form, no need of stack.
//If we want to reduce the time of reversing the node we can fix the size of vector at each level as l, and can fill the vector from back for alternate levels.


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        vector<int> v;
        vector<vector<int>> ans;
        int flag = 1;
        q.push(root);
        while(!q.empty()){
            int l = q.size();
            if(flag==1) flag=0;   //reverse the flags each time as we need zig zag
            else flag=1;
            v.clear();
            for(int i=0;i<l;i++){
                 TreeNode *n = q.front();
                 q.pop();
                 v.push_back(n->val);
                 if(n->left) q.push(n->left);
                 if(n->right) q.push(n->right);
            }
            if(flag==1)  reverse(v.begin(),v.end());
            ans.push_back(v);
        }
        return ans;
    }
};