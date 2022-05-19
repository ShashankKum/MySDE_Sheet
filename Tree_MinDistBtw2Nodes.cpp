//To get the minimum distance between two nodes find the lowest common ancestor of the nodes first.
//Now seaparately get distance of both the nodes from ancestor and sum up them.
//It takes O(N) time and uses 3 dfs traversal.

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* lca(Node* root,int a,int b){
        if(root==NULL)  return NULL;
        if(root->data==a || root->data==b)  return root;
        Node *l = lca(root->left,a,b);
        Node *r = lca(root->right,a,b);
        if(l && r)  return root;
        return (l==NULL)?r:l;
    }
    int dist(Node *root,int x){
        if(root==NULL)  return 0;
        if(root->data==x)  return 1;
        int l = dist(root->left,x);
        int r = dist(root->right,x);
        if(l==0 && r==0)  return 0;
        return 1+l+r;
    }
    int findDist(Node* root, int a, int b) {
        Node* parent = lca(root,a,b);
        int l = dist(parent,a);
        int r = dist(parent,b);
        return l+r-2;
    }
};