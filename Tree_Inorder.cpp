//Iterative solution,using O(N+h) space and O(N) time.
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack <TreeNode*> s;
        vector <int> v;
        TreeNode* t=root;
        while(t!=NULL || !s.empty()){ //if any one is true loop will run, it will break only when both t and stack becomes NULL
            while(t!=NULL){
                s.push(t); //first push than shift left,as shifting left can make it NULL
                t=t->left;
            }
            //till here t would have become NULL so assign it to the ltop element(or the last visited element to traverse its right part now)
            t=s.top();
            s.pop();
            v.push_back(t->val);
            t=t->right;
        }
        return v;
    }
};

//the space complexity of a recursive in order traversal is O(h) and not O(n) as h = tree height and n = number of nodes in the tree. We   are pushing n memory addresses to the call stack, therefore, the space complexity should be O(n).
//recursive solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) { //we need to create other function or else vector will be declared again and again
        vector<int> v;
        solve(root,v);
        return v;
    }
    void solve(TreeNode* node, vector<int> &v){
    if(node==NULL) return;
        solve(node->left, v);
         v.push_back(node->val);
            solve(node->right, v);
    }
};