//AVL tree is a self-balancing Binary Search Tree where the difference between heights of left and right subtrees cannot be more than one for all nodes.
//Using AVL tree implementation we make sure that the height of the tree never becomes more than O(LogN) in any case, so that traversal or insertion is always 
  maintained as O(logN).
//We can use three types of rotation to achieve it RR,LL,LR,RL depending on the balance factor(ht(left_child)-ht(right_child)) of the node.

#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
   int val;
   TreeNode *left=NULL;
   TreeNode *right=NULL;
};

int height(TreeNode* root){ //used to calculate the height of any node
    if(root==NULL)
    return 0;
    int l=height(root->left);
    int r=height(root->right);
    int h=1+max(l,r);
    return h;
}

int diff(TreeNode* root){ //it gives the balance factor of a node i.e ht(left_child)-ht(right_child)
    int d=height(root->left)-height(root->right);
    return d;
}

TreeNode* ll(TreeNode* root){
    TreeNode *t=root->left;
    root->left=t->right;  //whatever was right of t is braught to left of root
    t->right=root;        //and than root is made right of t
    return t;             //finally t is returned as new root after balancing
}
TreeNode* rr(TreeNode* root){
    TreeNode* t=root->right;
    root->right=t->left;
    t->left=root;
    return t;
}
TreeNode* lr(TreeNode* root){  
    TreeNode* t=root->left;
    root->left=rr(t);
    return ll(root);
}
TreeNode* rl(TreeNode* root){
    TreeNode* t=root->right;
    root->right=ll(t);
    return rr(root);
}

TreeNode* balance(TreeNode* root){ //in this we choose the needed rotation based on balance factor of node
    int d=diff(root);
    if(d>1){ //since diff is H(left-right) so positive means new node is added to left, i.e (ll or lr) movement
        if(diff(root->left)>0)  //this means ll rotation
        root=ll(root);
        else
        root=lr(root);
    }
    else if(d<-1){  //it means either rl or rr rotation
        if(diff(root->right)>0)
        root=rl(root);
        else
        root=rr(root);
    }
    return root;  //it will return the root after balancing it if required, by any one rotation i.e(d>1 || d<-1)
}

TreeNode* my_bst(TreeNode* root,int key){  //constructing bst
    if(root==NULL){ //when we reach NULL means the new node has to be inserted here
        TreeNode *new_node=new TreeNode;
        new_node->val=key;
        return new_node;
    }
    if(key<root->val){
        root->left=my_bst(root->left,key);
        root=balance(root);
    }
    else{
        root->right=my_bst(root->right,key);
        root=balance(root);
    }
    return root;
}
void preorder(TreeNode* root){  //inorder for a bst is sorted in ascending order
    if(root==NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main() {
    int n;
    cin>>n;
	int arr[n];
	TreeNode* root=NULL;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	    root=my_bst(root,arr[i]);
	}
	preorder(root);  //do a preorder traversal of bst
	return 0;
}
