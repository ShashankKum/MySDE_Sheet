class Solution {
public:
    TreeNode* solve(vector<int> &in, vector<int> &post,int ps,int pe,int is,int ie,unordered_map <int,int> &mp){
        
        if(ps>pe || is>ie) return NULL; //Base condition
        
        int k=mp[post[pe]]; //get index of last element of postorder in inorder list(root node
        int l=k-is; //no. of nodes which come before root in inorder(left part)
        TreeNode* root=new TreeNode(post[pe]); //end of postorder list is root
        
        //We divide both inorder and postorder list in left part and right part based on root node position in inorder list
        //k is related to inorder and l will help for moving in postorder
        //left subtree range will be same for both inorder and postorder just arrangement will be different,but right for post will start just next to 
		  left and last node will be root but for inorder last part is right subtree
        
        root->left=solve(in,post,ps,ps+l-1,is,k-1,mp); 
        root->right=solve(in,post,ps+l,pe-1,k+1,ie,mp);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int l=postorder.size(),i=0;
        unordered_map <int,int> mp; //put inorder index in hash map for O(1) search time
        auto it=inorder.begin();
        while(it!=inorder.end()){
            mp[*it]=i;
            it++; i++;
        }
      return solve(inorder,postorder,0,l-1,0,l-1,mp); //return the root of tree formed
    }
};