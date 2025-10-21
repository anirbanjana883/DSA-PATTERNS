Remove duplicates from a sorted doubly linked list


class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        if(!head || !head -> next) return head;
        
        Node* curr = head;
        
        while(curr && curr -> next){
            if(curr -> data == curr -> next -> data){
                Node* duplicate = curr -> next;
                
                curr -> next = duplicate -> next;
                if(duplicate -> next){
                    duplicate -> next -> prev = curr;
                }
                
                delete(duplicate);
            }else{
                curr = curr -> next;
            }
        }
        return head;
    }
};