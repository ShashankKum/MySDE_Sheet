//One way to get the sum of two lists is to either reverse both and than add or we can use recursion.
//In recursion we will add trailing nodes with zero for the shorter so that both becomes of same size and than we just add the lists.
//Time taken will be O(N) and space will also be O(N).

class Solution
{
    public:
    //Function to add preeceding node to head with given value
    Node* addNode(Node* head,int val){    
        Node *new_node = new Node(val);
        new_node->next = head;
        return new_node;
    }
    
    //Recursive function to generate the sum of numbers in new list
    //If we need to add values from back we need to use recursion and do the add part after recur
    Node* sum(Node *n1,Node *n2,int &bor){
        if(n1==NULL) return NULL;
        Node *n = sum(n1->next,n2->next,bor);
        int s = n1->data + n2->data;
        s = s+bor;
        bor  = s/10;
        s = s%10;
        Node *new_node = new Node(s);
        new_node->next = n;
        return new_node;
    }
    
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node *n1=first,*n2=second;
        while(n1 || n2){
            if(!n1){                //add preceeding zeroes to match the length
              first = addNode(first,0);
              n2=n2->next;
            }
            else if(!n2){           //add preceeding zeroes to match the length
              second = addNode(second,0);
              n1=n1->next;
            }
            else{
                n1 = n1->next;
                n2 = n2->next;
            }
        }
        int bor = 0;
        Node* head = sum(first,second,bor);
        if(bor!=0)          //if borrow is still not 0, add a node in front of head with bor val
            head = addNode(head,bor);
        return head;   //return the head of new list
    }
};