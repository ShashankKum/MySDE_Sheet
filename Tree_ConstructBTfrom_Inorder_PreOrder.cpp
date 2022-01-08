//Recursive using map

class Solution {
public:
    TreeNode* solve(vector<int> &pre, vector<int> &in, int ps, int pe, int is, int ie, unordered_map <int,int> &mp){
        if(ps>pe || is>ie) return NULL; //Base condition
        int k=mp[pre[ps]]; //will give index of root node in inorder list
        TreeNode* root=new TreeNode(pre[ps]);
        int l=k-is;  //distance of node from left in inorder
        root->left=solve(pre,in,ps+1,ps+l,is,k-1,mp);
        root->right=solve(pre,in,ps+l+1,pe,k+1,ie,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map <int,int> mp;
        int l=inorder.size(),i=0;
        auto it=inorder.begin();
        while(it!=inorder.end()){
            mp[*it]=i;
            i++; it++;
        }
        return solve(preorder,inorder,0,l-1,0,l-1,mp);
    }
};