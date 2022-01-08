

//Using two pointers
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

Node* temp;  //temp here is globally declared
void recur(Node* cur){
    if(cur==NULL) //base condition to end looping
    return;
    temp=cur->prev;  //temp is set to previous node
    cur->prev=cur->next;   //prev will be next
    cur->next=temp; //and next will be prev
    cur=cur->prev;  //to reach the next node
    recur(cur);
}
Node* reverseDLL(Node * head)
{
    if(head->next==NULL) return head;
    recur(head);
    return temp->prev; //temp will be a node before end node so in reversed prev means next so
}