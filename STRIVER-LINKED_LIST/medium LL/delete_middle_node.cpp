2095. Delete the Middle Node of a Linked List

broute force approach :


class Solution {
public:
    // time o(n + n / 2)
    // space o (1)
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head -> next ) return NULL;
        int n  = 0;
        ListNode* temp = head;

        while(temp){
            n++;
            temp = temp -> next;
        }
        int pos_before_middle = floor(n / 2) - 1 ;
        temp = head;
        while(pos_before_middle--){
            temp = temp -> next;
        }

        ListNode * middle = temp -> next;
        temp -> next = middle -> next;
        delete(middle);
        return head; 
    }
};

optimised approach :


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head -> next) return NULL;
        // our primary aim is to reach he node just before the middle
        ListNode * slow = head;
        ListNode * fast = head;
        // to reach the node before the middle we will 
        // skip one iteration of slow

        fast = fast -> next -> next;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode * middle = slow -> next;
        slow -> next = middle -> next;
        delete(middle);
        return head;
    }
};