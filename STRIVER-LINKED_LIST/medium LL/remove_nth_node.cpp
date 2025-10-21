19. Remove Nth Node From End of List


broute force approach :

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        
        // First while loop: count total nodes
        ListNode* temp = head;
        int cnt = 0;
        while(temp){
            temp = temp->next;
            cnt++;
        }
        
        // If we need to remove the head node
        if(cnt == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        // Second while loop: move to node before the one to delete
        ListNode* prev = head;
        int pos = cnt - n - 1; // we want to stop at node before deletion
        
        while(pos > 0) {
            prev = prev->next;
            pos--;
        }
        
        // Delete the node
        ListNode* delnode = prev->next;
        prev->next = prev->next->next;
        delete(delnode);
        
        return head;
    }
};


optimal approach : slow fast pointer approach ::

class Solution {
public:
    // time o( len )
    // space o(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        for(int i = 0; i < n ; i++) fast = fast -> next;
        if(fast == NULL) return head -> next;

        while(fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next;
        }
        ListNode* delNode = slow -> next;
        slow -> next = slow -> next -> next;
        delete (delNode);
        return head;
    }
};