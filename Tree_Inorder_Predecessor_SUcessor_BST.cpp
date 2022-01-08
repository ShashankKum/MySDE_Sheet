//We can create a binary search tree by finding the position to place the node and than adding the node there..Node* n1=new Node;

//Simple way to get inorder successor and predecessor is by making a inorder traversal and storing it in an array and than get the arr[i-1] and arr[i+1]
 element this will take O(N) time and O(N) extra space.(space for recursion call aswell).

//successor means we need a node value which is just greater than the current node value so we need
//to keep the previous node value whose left we are traversing,or if right subtree is present,
//get the leftmost node of right subtree.
//In this also time complexity will be same in case of skewed binary search tree but in average case it will reduce.
//if there is a case that the val is not necesarily a node value we just need to add [if(root==NULL) return prev;]
Node* front(Node *root,int val,Node *prev){
    if(root->key>val)
    return front(root->left,val,root);
    else if(root->key<val)
    return front(root->right,val,prev);
    else{ //this means we have reached our value
        if(root->right==NULL)
        return prev;
        else{
            root=root->right;
            while(root->left!=NULL){ //we will reach leftmost of right subtree to get just smaller value
                root=root->left;
            }
            return root;
        }
    }
}
//predecessor is a just smaller value than the key value,so if we move right of any node means 
//the previous value was smaller than it,this will be used if there is no left subtree of the key.
Node* back(Node *root,int val,Node *prev){
    if(root->key>val)
    return back(root->left,val,prev);
    else if(root->key<val)
    return back(root->right,val,root);
    else{ //this means we have reached our value
        if(root->left==NULL)
        return prev;
        else{
            root=root->left;
            while(root->right!=NULL){ //we will reach rightmost of left subtree to get just smaller value
                root=root->right;
            }
            return root;
        }
    }
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
   pre=back(root,key,NULL);
   suc=front(root,key,NULL);
}