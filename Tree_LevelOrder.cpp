//Level order traversal using queue.
//we pop element from first and push its left and right subtree at end...so the values are always popped level wise. 

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue <TreeNode*> q;
        int l=1,m=0;
        vector <int> a;
        vector <vector<int>> v;
        if(root==NULL) return v;
        TreeNode* cur=root;
        q.push(cur);
        while(!q.empty()){
            if(l==0) { //if l is 0 means the current level is completely traversed.
            l=m; m=0;
            v.push_back(a);
            a.clear();
            }
            cur=q.front();
            a.push_back(cur->val);
            q.pop();
            if(cur->left!=NULL) {q.push(cur->left); m++;}
            if(cur->right!=NULL) {q.push(cur->right); m++;}
            l--;
        }
        v.push_back(a); //as the last level is just traversed the stack will be empty so last vector will still remain to be inserted
        return v;
    }
};

//We could have also used the current size of stack and loop till that value to fill the inner vector, instead of using l and m to make it standard.
                         while(!q.empty()){
						 int n=q.size();   
						 for(int i=0;i<n;i++){
						    .....all general operations
						 }
						 }