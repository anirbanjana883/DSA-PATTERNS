141. Linked List Cycle

broute force approach :

class Solution {
public:
    // time o( n + log n )
    // space complexity o( n)
    bool hasCycle(ListNode *head) {
        unordered_map < ListNode* , int> mp;

        ListNode * temp = head;
        while(temp){
            if(mp.find(temp) != mp.end()) return true;
            mp[temp]++;
            temp = temp -> next;
        }
        return false;
    }
};

approach 2:


class Solution {
public:
    // time o( n)
    // space o(1)
    bool hasCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
        // if(!head && !head -> next) return false;

        while(fast != NULL && fast -> next != NULL){

            
            fast = fast -> next -> next;
            slow = slow -> next;

            if(slow == fast) return true;
        }
        return false;
    }
};