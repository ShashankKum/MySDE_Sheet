//In this we recursively devide the vector in left and right subtree, we will take k till the end of left subtree,so (k+1->j) will be 
//right subtree,and we will recursively devide it further.
//If we reach a condition such that left/right subtree consits only one node(i==j) we will return it, and if i>j that means there are no 
//further so we will return NULL.
class Solution {"
public:
    TreeNode* link(vector<int>& pre,int i,int j){
        if(i>j) 
        return NULL;
        TreeNode* root=new TreeNode(pre[i]);
        if(i==j)
        return root;
        int k=i;
        while(k<j && pre[i]>pre[k+1]) k++; //to check first if k do not crosses the boundry of j
        root->left=link(pre,i+1,k);  //link it with left of root node
        root->right=link(pre,k+1,j); //link it with right of root node
        return root;  //at last all will be connected and we will return the root address
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        return link(preorder,0,n-1);
    }
};