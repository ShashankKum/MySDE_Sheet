//In this we need to find the kth ancestor of the node.
//We do it in O(N) time using O(1) extra space, we make use of flag,when we get the node value while recurring we make flag as 1,
  and once the flag is one we keep on returning the root values recursively and decrementing k in each step till k becomes 0.
//If even at end k is not zero means we dont have a solution.


bool flag;
int ancestor(Node *root, int &k, int node){
    if(root==NULL)  return -1;
    if(root->data==node){
        flag=1;
        return root->data;
    }
    int l = ancestor(root->left,k,node);
    int r = ancestor(root->right,k,node);
    if(l==-1 && r==-1)  return -1;
    else if(flag==1){
        if(k==0)   return (l!=-1)?l:r;
        else if(k>0){
            k--;
            return root->data;
        }
    }
    return -1;
}

int kthAncestor(Node *root, int k, int node)
{
    flag=0;
    int ans = ancestor(root,k,node);
    if(k!=0)  return -1;
    return ans;
}

//We can also do it using vectors, by storing the ancestor of each node each time and than get the kth ancestor, but it will also take O(N)
  extra time.