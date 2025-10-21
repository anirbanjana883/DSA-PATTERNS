148. Sort List

broute force approach :

first move all node val to an array -> sort the array -> again coder the array to LL

time o(n + nlogn + n)
space o(n)


optimised approach : using merge sort 


class Solution {
public:
    // time o(nlogn) // different from array merge sort
    // space o(1) because we are not taking any extra space to merge 
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head; 
        ListNode* fast = head -> next; // this modification is to get
        // the first middle of  a linked list  
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next; 
            fast = fast->next->next; 
        }

        return slow; 
    }
    ListNode* mergeTwoSortedLinkedLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node
        ListNode* dummyNode = new ListNode(-1);
        
        // Temp pointer to build merged list
        ListNode* temp = dummyNode;

        // Traverse both lists
        while (list1 != nullptr && list2 != nullptr) {
            // Choose smaller node
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            // Move temp pointer
            temp = temp->next;
        }

        // Attach remaining nodes
        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        // Return head of merged list
        return dummyNode->next;
    }

    // we will be implementing the merge sort in th LL 
    ListNode* sortList(ListNode* head) {
        // BC
        if(!head || !head -> next) return head;

        ListNode* middle = findMiddle(head);

        ListNode* leftHead = head;
        ListNode* rightHead = middle -> next;

        middle -> next = NULL;

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return mergeTwoSortedLinkedLists(leftHead , rightHead);
    }
};