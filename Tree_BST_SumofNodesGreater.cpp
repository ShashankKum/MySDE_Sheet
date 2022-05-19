//In this we have to fix the value of each node as the sum of all nodes greater than or equal to it., given a bst.
//To do in O(N) time we do a reverse inorder traversal.
//We use sum by reference and keep on adding the values.



void Getsum(Node* root,int &sum){
    if(root==NULL)   return;
    Getsum(root->right,sum);
    sum = sum + root->data;
    root->data =  sum;
    Getsum(root->left,sum);
}
Node* modify(Node *root)
{
    int sum=0;
    Getsum(root,sum);
    return root;
}