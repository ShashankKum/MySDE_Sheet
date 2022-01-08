//using tortoise method(fast and slow pointer,fast moving two and slow moving one) we can do it in O(N) time and O(1) extra space.
//if slow and fast pointers meet loop exists else no.
//another approach which uses O(N) extra space is storing the nodes in hash table and seeing if the same node comes again than loop exists.

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow,*fast;
        slow=fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                return true;
        }
        return false;
    }
};


bool detectLoop(struct Node* h)
{
    unordered_set<Node*> s;
    while (h != NULL) {
        // If this node is already present
        // in hashmap it means there is a cycle
   
        if (s.find(h) != s.end())
            return true;
 
        // If we are seeing the node for
        // the first time, insert it in hash
        s.insert(h);
 
        h = h->next;
    }
 
    return false;
}