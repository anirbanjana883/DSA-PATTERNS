Delete all occurrences of a given key in a doubly linked list

class Solution {
  public:
//   time o( n)
// soace o(1)
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        struct Node* curr=*head_ref;
        while(curr){
            struct Node* temp=curr->next;
            if(curr->data==x){
                if(curr==*head_ref){
                    *head_ref=temp;
                }
                struct Node* prevNode = curr->prev;
                 
                if(prevNode) prevNode->next=curr->next;
                
                struct Node* nextNode = curr->next;
  
                if(nextNode) nextNode->prev=curr->prev;
            }
            curr=temp;
        }
    }
};