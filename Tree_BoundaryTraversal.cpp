//It is the boundary traversal of a tree ,right or left boundary exists only when the root of tree has a left or right subtree.
//values needs to be printed in the order as left boundary, leaf nodes, right boundary.
//suppose the root node do not have a right subtree so the root node will be the only node in right boundary, but since it would already 
//be included in left boundary so we would not add it again.
//It will take O(N) time and O(N) space complexity. 

class Solution {
public:
    vector<int> ans;
    //for leaf nodes its a simple dfs traversal and print them when we encounter a leaf node
    void leaf(Node *root){
        if(root==NULL)  return;
        if(root->left)  leaf(root->left);
        if(root->right)  leaf(root->right);
        if(!root->left && !root->right) ans.push_back(root->data);
    }
    //reverse right boundary traversal
    void right(Node* root){
        if(root==NULL) return;
        if(root->right)  right(root->right);
        else if(root->left)  right(root->left);
        if(root->left || root->right)
        ans.push_back(root->data);
        //Here we exclude the case of leaf node to remove overlapping where both left and right 
    }
    //left boundary traversal
    void left(Node *root){  //sinnce in left boundary we need values in top down manner first print the data than recur
        if(root==NULL) return;
        if(root->left || root->right)
        ans.push_back(root->data);
        //we check if left is available we go left and if not left than we move to right
        if(root->left)  left(root->left);
        else if(root->right)  left(root->right);
        //Here we exclude the case of leaf node to remove overlapping where both left and right are null
    }
    vector <int> boundary(Node *root)
    {
        ans.clear();
        ans.push_back(root->data);
        //left boundary
        left(root->left);
        //leaf nodes
        leaf(root->left);
        leaf(root->right);
        //right boundary
        right(root->right);
        return ans;
    }
};