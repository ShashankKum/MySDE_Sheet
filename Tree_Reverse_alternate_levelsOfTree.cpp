//Code to invert alternate levels of a perfect binary tree(all levels are filled)
//In this we do level order traversal, when an odd level comes we store the pointers of nodes in queue and values of nodes at that level are pushed in stack and after the level ends
//using queue we retrive the nodes and reverse the values using stack.


void reverseAlternate(Node *root)
{
    stack<int> s;  //stack used to invert the order
    queue<Node*> q;  //it is used for performing level order traversal
    queue<Node*> level;  //used for storing nodes in a level so that they can be reversed once level is traversed
    q.push(root);
    bool l=0;
    while(!q.empty()){     //doing level order traversal
        int k=q.size();
        while(k--){
        Node* n=q.front();
        q.pop();
        if(l==1) {     //if level is odd push the nodes in queue to retrive them later
        level.push(n);
        s.push(n->data);
        }
        if(n->left!=NULL) q.push(n->left);
        if(n->right!=NULL) q.push(n->right);
        }
        if(l==1){   //reverse the elements of odd level
            while(!level.empty()){
                Node *a=level.front();  //get pointer to leftmost node
                a->data=s.top();        //set its value to s.top()
                level.pop();            //pop the front of queue
                s.pop();                //and pop the top of stack
            }
        }
        if(l==0)  //change even level to odd and odd to even
        l=1;
        else l=0;
    }
}