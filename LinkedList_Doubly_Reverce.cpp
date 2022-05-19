

//Using two pointers
//IF WE HAVE TO REVERSE A LINKEDLIST MAKE A TEMP VARIABLE INITIALIZED WITH NULL WHICH WILL ALWAYS KEEP THE PREVIOUS NODE VALUE AND IN EACH STEP INITIALIZE NEWNODE TO HEAD->NEXT.
//IN EACH STEP/RECURSION TRY TO FIX ONE NODE.
//to check this we can make a double linked list of three nodes and check it

Node* reverseDLL(Node * head)
{
    if(head->next==NULL) return head;
    Node *cur=head,*temp;
    while(cur!=NULL){
       temp=cur->prev;  //temp is set to previous node
       cur->prev=cur->next;   //prev will be next
       cur->next=temp; //and next will be prev
       cur=cur->prev;  //to reach the next node
    }
    return temp->prev; //temp will be a node before end node so in reversed prev means next so
}

//Reverse a doubly linked list using recursion
//In recursion the changes made in configuration by recurring functions is permanent we dont need to paas by refrence.

Node* recur(Node* head,Node* temp){
    if(head==NULL)
        return temp;
    Node *new1 = head->next;
    head->prev = new1;
    head->next=temp;
    temp=head;
    head=new1;
    return recur(head,temp);
}
Node* reverseDLL(Node * head)
{
    //Your code here
    return recur(head,NULL);
}
