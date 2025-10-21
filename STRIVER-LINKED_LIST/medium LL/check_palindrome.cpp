234. Palindrome Linked List

approach 1 :

class Solution {
public:
    // time o( n )
    // space o( n )
    bool isPalindrome(ListNode* head) {
        // strore in a stack last element will be at the top then comapare with the first one 
        ListNode* temp = head;
        stack<int>st;

        while(temp){
            st.push(temp -> val);
            temp = temp -> next;
        }

        temp = head;
        int n = st.size() / 2; // to resuce no of comparisn

        while(n--){
            if(temp -> val != st.top()) return false;
            st.pop();
            temp = temp -> next;
        }
        return true;
    }
};

approach 2 :


class Solution {
public:
    ListNode* reverse_ll(ListNode* head){
        if(!head || !head -> next) return head;
        ListNode* newHead = reverse_ll(head -> next);

        ListNode* front = head -> next;
        front -> next = head;
        head -> next = NULL;
        return newHead;
    }
    // time o( n )
    // space o( 1 )
    bool isPalindrome(ListNode* head) {
        if(!head || !head -> next) return true;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast -> next != NULL && fast -> next -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        // if n == even slow will be at just before first middle element(as there is 2 middle)
        // if n == odd then slow will be just just before middle element

        ListNode* middleNode = reverse_ll(slow -> next);
        ListNode* p1 = head;
        ListNode* p2 = middleNode;

        while(p2 != NULL){
            if(p1 -> val != p2 -> val){
                reverse_ll(middleNode) ; // just to makle sure user data not tampered
                return false;
            }
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        reverse_ll(middleNode) ; // just to makle sure user data not tampered
        return true;
    }
};