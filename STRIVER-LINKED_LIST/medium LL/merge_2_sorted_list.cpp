

broute force approach :

put all element in an array and sort it ;

better approach :

concept of dummy Node


class Solution {
public:
    // time o(n1 + n2)
    // space o(1)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        ListNode* t1 = list1;
        ListNode* t2 = list2;
        while(t1 && t2){
            if(t1 -> val < t2 -> val){
               temp -> next = t1;
               temp = t1;
               t1 = t1 -> next;
            }else{
               temp -> next = t2;
               temp = t2;
               t2 = t2 -> next;                
            }
        }
        if(t1){
            temp -> next = t1;
        }
        if(t2){
            temp -> next = t2;;
        }
        return dummy -> next;
    }
};

optimised approach :

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;

        ListNode*result;
        if(l1->val < l2->val){
            result=l1;
            result->next=mergeTwoLists(result->next,l2);
        }else{
            result=l2;
            result->next=mergeTwoLists(l1,result->next);
        }
        return result;
    }
};