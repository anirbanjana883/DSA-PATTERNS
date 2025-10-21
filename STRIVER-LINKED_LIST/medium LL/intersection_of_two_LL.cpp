160. Intersection of Two Linked Lists

approach 1:

class Solution {
public:
    // time o(n + logn(for map))
    // space o(n)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode * , int>mp;
        ListNode * tempa = headA;
        while(tempa){
            mp[tempa]++;
            tempa = tempa -> next;
        }
        ListNode * tempb = headB;
        while(tempb){
            if(mp.find(tempb) != mp.end()){
                return tempb;
            }
            tempb = tempb -> next;
        }
        return NULL;
    }
};

approach 2:

class Solution {
public:
    // time ~ o(4n)
    // space o(1))
    ListNode *giveIntersection(ListNode* longer, ListNode* shorter, int diff){
        // Move the longer list pointer forward by 'diff' nodes
        ListNode* tempLong = longer;
        while(diff > 0 && tempLong){
            tempLong = tempLong->next;
            diff--;
        }
        
        ListNode* tempShort = shorter;

        // Now both pointers are at the same level from the end
        while(tempLong && tempShort){
            if(tempLong == tempShort) return tempLong;
            tempLong = tempLong->next;
            tempShort = tempShort->next;
        } 
        return NULL;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;

        ListNode *tempA = headA;
        ListNode *tempB = headB;

        while(tempA){
            lenA++;
            tempA = tempA->next;
        }
        while(tempB){
            lenB++;
            tempB = tempB->next;
        }

        if(lenA > lenB){
            return giveIntersection(headA, headB, lenA - lenB);
        } else {
            return giveIntersection(headB, headA, lenB - lenA);
        }
    }
};

class Solution {
public:
        // time ~ o(2n)
    // space o(1))
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * t1 = headA;
        ListNode * t2 = headB;

        while(t1 != t2){
            t1 = t1->next;
            t2 = t2->next;

            if(t1 == t2) return t1;

            if(t1 == NULL) t1 = headB;
            if(t2 == NULL) t2 = headA;
        }
        return t1; // if only one linked list
    }
};