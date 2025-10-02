2. Add Two Numbers

class Solution {
public:
    // time o(max(n1 , n2))
    // space o(max(n1 , n2))
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int carry = 0;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        while(t1 || t2){
            int sum = 0; 
            sum += carry;
            if(t1) sum += t1->val;
            if(t2) sum += t2->val;

            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            temp -> next = newNode;
            temp = temp -> next;

            if(t1) t1 = t1->next;
            if(t2) t2 = t2->next;
        }

        // left over
        if(carry){
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
        }
        return dummy -> next; // dummy -> next = head;
    }
};