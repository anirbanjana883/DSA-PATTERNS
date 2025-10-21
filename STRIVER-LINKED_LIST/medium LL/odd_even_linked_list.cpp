328. Odd Even Linked List

broute force approach :
 travarse onece store all add idx number in a List
 travarse second time store all even idx number in the same list 
 make a linked list


optimised approach :

class Solution {
public:
    // time o(n / 2) = o( n / 2) ~ o(n)
    // space o ( 1 )
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummy1 = new ListNode(-1); // odd
        ListNode* dummy2 = new ListNode(-1); // even

        int idx = 0;
        ListNode* odd = dummy1;
        ListNode* even = dummy2;
        ListNode* temp = head;
        while(temp){
            if(idx % 2 != 0){ // even
                ListNode* newNode = new ListNode(temp->val);
                even->next = newNode;
                even = even->next;
            }else{ // odd
                ListNode* newNode = new ListNode(temp->val);
                odd->next = newNode;
                odd = odd->next;
            }
            temp = temp->next;
            idx++;
        }
        // merging
        //           even
        odd->next = dummy2->next;
        dummy2->next = NULL;

        return dummy1->next;
    }
};


class Solution {
public:
    // modifying the same list without any extra spaces
    // time o(n / 2) = o( n / 2) ~ o(n)
    // space o ( 1 )
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* odd = head; // 1 based indexing
        ListNode* even = head -> next;
        ListNode* evenHead = head -> next;

        while(even && even->next){
            odd -> next = odd -> next -> next;
            even -> next = even -> next -> next;

            odd = odd -> next;
            even = even -> next;
        } 
        odd -> next = evenHead;
        return head;
    }
};