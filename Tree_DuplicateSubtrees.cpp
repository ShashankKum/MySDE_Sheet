//In this we basically we try to get all possible subtrees making use of string and than using map we check if the string already exists
//means we get a duplicate subtree and if it is the first duplicate of similar type we store its root node in ans vector.
//Here time complexity is O(N) since we are having simple preorder traversal(Depth-first-search) and space complexity is also O(N) as it uses map.


class Solution {
public:
    vector<TreeNode*> ans;
    unordered_map<string,int> mp;
    string recur(TreeNode* root){
        if(root==NULL) return " ";
        string s="";
        s += to_string(root->val) + ",";  //to seperate left and right subtree we use , otherwise can create ambiguity in case of [11,1] 
        s += recur(root->left) + ",";
        s += recur(root->right);
        if(mp.find(s)!=mp.end())
            if(mp[s]==1)  ans.push_back(root);
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        recur(root);
        return ans;
    }
};