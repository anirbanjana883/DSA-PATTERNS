Find length of Loop [gfg]

approach 1 : using unordered_map

class Solution {
  public:
    // time o( n log n)
    // space o( n)
    int lengthOfLoop(Node *head) {
        // code here
        unordered_map<Node* , int> mp;
        Node * temp = head;
        int len = 0;
        while(temp){
            if(mp.find(temp) != mp.end()){
                return len - mp[temp];
            }
            mp[temp] = len;
            len++;
            temp = temp -> next;
        }
        return 0;
    }
};

approach 2 : using slow fast pointer


class Solution {
  public:
    // time o( n)
    // space o(1)
    int findLength(Node *slow ,Node *fast){
        int cnt = 0;
        while(fast){
            fast = fast -> next;
            cnt ++;
            if(fast == slow ) return cnt;
        }
        return 0;
    }
    int lengthOfLoop(Node *head) {
        // code here
         Node* slow = head;
         Node* fast = head;
         while(fast != NULL && fast -> next != NULL){
             fast = fast -> next -> next;
             slow = slow -> next;
             if(slow == fast){
                 return findLength(slow,fast);
             }
         }
         return 0;
    }
};