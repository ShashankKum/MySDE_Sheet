//Reverse a linked list in group of size k.
//Whenever we need to perform the similar looking task again and again we can make use of recursion.
//In this we find the pos k+1 and at that place the pointer n which will be the head of next group and reverse the first k and recur for
  next part. We connect the head of one subpart with tail of other subpart.
  

class Solution
{
    public:
    node* rev(node* head,int k){
        if(head==NULL)  return NULL;
        node *a=head,*b=head->next,*n;
        int cnt=0;
        while(a!=NULL && cnt<k){
            cnt++;  a=a->next;
        }
        n=a;  //It will have the head of next k group, and if NULL it is the last group
        a=head;
        a->next=NULL;
        while(b!=n){
            node *c=b->next;
            b->next=a;
            a=b;
            b=c;
        }
        head->next = rev(n,k);
        return a;
    }
    struct node *reverse (struct node *head, int k)
    { 
        return rev(head,k);
    }
};