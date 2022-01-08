//In this we traverse simply in the linked list till we reach the desired value,now if the node has no childrens means simply 
//delte the node,if node has one child(left or right) delete the node and return the child,if it has both child(main case)
//get the inorder successor(leftmost of right subtree) copy its value to node,now traverse the node to find the 
//inorder successor whose value is copied and delete it.

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return NULL;
        else if(root->val>key)
            root->left=deleteNode(root->left,key);
        else if(root->val<key)
            root->right=deleteNode(root->right,key);
        else{  //if root value matches with key value
            if(root->left==NULL && root->right==NULL){ //if it is the leaf node
                delete(root);
                return NULL;
            }
            else if(root->left==NULL || root->right==NULL){ //any one of the child node is null
                TreeNode* temp;
                temp = root->left?root->left:root->right;
                return temp;  
            }
            else{  //if both childs are present we find the inorder successor to replace with root->val
                TreeNode *temp=root->right;
                while(temp->left){
                    temp=temp->left;
                }
                root->val=temp->val;
                delete(temp);
                root->right=deleteNode(root->right,root->val);
            }
        }
        return root;
    }
};