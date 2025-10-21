Find pairs with given sum in doubly linked list

approach 1 : two pointer approach (nested for loop)
time o(n ^ 2)
space o(1)

approach 2 : two pointer but one at first one at last



class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // two pointer approach 
        // o(n) time 
        // o(1) space
        vector<pair<int, int>>ans;
        
        Node* t1 = head;
        Node* t2 = head;
        
        // move t2 to last
        while(t2 -> next){
            t2 = t2 -> next;
        }
        while(t1 != t2 && t2 -> next != t1){
            if(t1 -> data + t2 -> data == target){
                ans.push_back({t1 -> data , t2 -> data});
                if(t1) t1 = t1 -> next;
                if(t2) t2 = t2 -> prev;
            }
            else if(t1 -> data + t2 -> data < target){
                if(t1) t1 = t1 -> next;
            }else{
                if(t2) t2 = t2 -> prev;
            }
        }
        return ans;
    }
};