//if root recahes null means the val do not exists,as in BST we travel by checking all the required nodes where val might be present.
//whenevr it returns NULL or root we recursively return the same.
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)
            return NULL;
        if(root->val==val)
            return root;
        else if(root->val>val)
        return searchBST(root->left,val);
        else
        return searchBST(root->right,val);
    }
};