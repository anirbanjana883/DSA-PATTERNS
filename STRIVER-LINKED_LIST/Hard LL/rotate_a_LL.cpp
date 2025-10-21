61. Rotate List


class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int countNode(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* RotateList(ListNode* head, int k, int count) {
        k = k % count;
        //  if k become zero then no rotation needed
        if(k==0) return head;
        count = count - k;
        ListNode* curr=head;
        ListNode* prev=NULL;
        while (count--) {
            prev=curr;
            curr=curr->next;
        }
        // 1 -> 2 -> 3 -> 4 -> 5 -> 6 k=2
        //              prev  curr
        // 1 -> 2 -> 3 -> 4 ->NULL [newHead]->5 -> 6 k=2
        //               prev               curr
        prev->next=NULL;
        // curr is the new head
        ListNode* tail=curr;
        while(tail->next){
            tail=tail->next;
        }
        tail->next=head;
        return curr;
    }
    ListNode* rotateRight(ListNode* head, int k) {
         if(head==NULL||head->next==NULL){
            return head;
        }
        // counting the number of node in the linked list
        int count = countNode(head);
        // for larger value of k we
        // are shortening the value of k
        return RotateList(head, k, count);
    }
};