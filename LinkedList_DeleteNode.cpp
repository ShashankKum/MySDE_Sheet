//In this the head pointer is not given instead the pointer to the node to be deleted is given(keeping in mind that it is not the end node).
//Copy the node->next value to node and delete node->next, so it will look like the node is deleted as value is copied of next.

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *temp;
        node->val=node->next->val; //copy the value of next to that position as it is not possible to delete the first node to which 
		                           //pointer is given unless it is the first node
        temp=node->next;
        node->next=node->next->next;
        delete(temp); //delete the node
    }
};