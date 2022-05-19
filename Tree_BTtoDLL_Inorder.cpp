
//In this we simply do a inorder traversal and keep trak of the list using two pointers head and prev.
//Head will be pointing to the first node of dll i.e first node in inOrder traversal.
//prev will be the just previous node.
//just need to do three simple modifications prev->right=root, prev->right->left=prev, prev=root.


class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    void inOrder(Node *root,Node* &head,Node* &prev){
        if(root==NULL)  return;
        
        inOrder(root->left,head,prev);
        
        if(head==NULL){
            head=root;  prev=root;
        }
        else{
            prev->right=root;
            prev->right->left=prev;
            prev=root;
        }
        
        inOrder(root->right,head,prev);
    }
    Node * bToDLL(Node *root)
    {
        Node *head=NULL,*prev=NULL;
        inOrder(root,head,prev);
        return head;
    }
};