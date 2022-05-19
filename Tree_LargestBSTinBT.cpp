//This is how we can get the largest bst in a binary tree in O(N) time.
//In this we use bottom up recursion approach so that the bottom subtrees can return its finding and than using that the above root node
//can decide wether its a bst in O(1) time by seeing if its root->val > left_max and root->val < right_min.
//we use a pair of pair to retunr the values in {size of bst,{min,max}} format.

class Solution{
    public:
    pair<int,pair<int,int>> dfs(Node* root,int &ans){
        if(!root) return {0,{1e9,-1e9}};   //{size of bst,{min,max}}
        
        auto lv = dfs(root->left,ans);
        auto rv = dfs(root->right,ans);
        
        int ln = lv.first, ls = lv.second.first, lg = lv.second.second;
        int rn = rv.first, rs = rv.second.first, rg = rv.second.second;
        
        int curr_node, curr_mini, curr_maxi;
        
        if(root->data > lg and root->data < rs){  //if root val > left_max and < right_min
            curr_node = 1 + ln + rn;
            curr_mini = min(root->data,ls);    //min will be min of curr node and min val from left sub tree 
            curr_maxi = max(root->data,rg);    //max val from right subtree
            ans = max(ans,curr_node);
        }else{
            curr_node = 1 + ln + rn;
            curr_mini = -1e9;    //here we make min as INT_Min so further no cases for it is considered, as it is not a bst so even above it will not form a bst
            curr_maxi = 1e9;     //same goes for it
        }
        
        pair<int,pair<int,int>> res = {curr_node,{curr_mini,curr_maxi}};
        return res;
    }
    int largestBst(Node *root){
    	int ans = 1;
    	dfs(root,ans);
    	return ans;
    }
};