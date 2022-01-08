//Recursive Solution

class Solution {
public:
    void solve(TreeNode* r1,TreeNode* r2,bool &flag){
        if(r1==NULL || r2==NULL){
            if(r1!=NULL || r2!=NULL) flag=0;
            return;
        }
        if(r1->val!=r2->val) {flag=0; return;} //if value different than not symmetric so need to traverse further for that node
        solve(r1->left,r2->right,flag); //traversing left in one half and right in another
        solve(r1->right,r2->left,flag);
    }
    bool isSymmetric(TreeNode* root) {
        bool flag=1;
        solve(root,root,flag);
        return flag; //if flag is 0 not symmetric and if 1 than symmetric
    }
};

//Iterative approach using level order traversal with on queue.
//The queue will store the nodes such that the symmetry nodes are adjacent to each other,for better understanding you can use two different queues too.
//Check if values of symmetry node are same or not and if NULL occurs than it occurs at both position or not.

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode *r1,*r2;
        queue <TreeNode*> q;
        if(root==NULL) return true;
        q.push(root); 
        q.push(root);
        while(!q.empty()){
            r1=q.front();
            q.pop();
            r2=q.front();
            q.pop();
            if(r1->val!=r2->val) return false;
            
            if(r1->left!=NULL && r2->right!=NULL){
            q.push(r1->left); 
            q.push(r2->right);
            }
            else if(r1->left!=NULL || r2->right!=NULL) return false;
            
            if(r1->right!=NULL && r2->left!=NULL){
            q.push(r1->right); 
            q.push(r2->left);
            }
            else if(r1->right!=NULL || r2->left!=NULL) return false;
            
        }
        return true;
    }
};