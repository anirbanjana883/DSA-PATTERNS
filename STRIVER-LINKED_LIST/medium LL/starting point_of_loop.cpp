142. Linked List Cycle II

broute force approach :

trvarsing through LL and keep track of map --

class Solution {
public:
    // time o(n)
    // space o( n)
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode* , int>mp;
        ListNode* temp = head;

        while(temp){
            if(mp.find(temp) != mp.end()){
                return temp;
            }
            mp[temp]++;
            temp = temp -> next;
        }    

        return NULL;
    }
};

approach 2 : tortoise here algorithm 



class Solution {
public:
    // o(n) time 
    // o(n) space 
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // first find the point where slow and first pointer meet
        while (fast && fast->next) {

            slow = slow->next;
            fast = fast->next->next;
        // move slow to head and agin move slow and first simultaniously
        // the point where they will meet is the starting point of loop
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow ; // means they meet
            }
        }
        return NULL;
    }
};