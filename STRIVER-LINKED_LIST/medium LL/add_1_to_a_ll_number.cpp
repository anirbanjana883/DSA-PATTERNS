Add 1 to a Linked List Number

approach 1 : 

class Solution {
  public:
//   time o( 3 * n)
// space o( 1 )
    Node* reverse_ll(Node* head){
        if(!head || !head -> next) return head;
        Node* newHead = reverse_ll(head -> next);

        Node* front = head -> next;
        front -> next = head;
        head -> next = NULL;
        return newHead;
    }
    Node* addOne(Node* head) {
        head = reverse_ll(head);
        
        int carry = 1;
        Node* temp = head;
        
        while(carry > 0 && temp != NULL){
            int dig = temp -> data + carry;
            temp -> data = dig % 10;
            carry = dig / 10;
            temp = temp -> next;
        }
        head = reverse_ll(head);
        
        if(carry > 0){
            Node* newNode = new Node(carry);
            newNode -> next = head;
            head = newNode;
        }
        
        return head;
    }
};

approach 2 :



class Solution {
  public:
    // time o(n)
    // space o(n)
    int helper(Node* temp){
        // bc 
        if(temp == NULL){
            return 1;
        }
        
        int carry = helper(temp -> next);
        int dig = temp -> data + carry ;
        temp -> data = dig % 10;
        carry = dig / 10;
        
        return carry;
    }
    Node* addOne(Node* head) {
        int carry = helper(head);
        if(carry > 0){
            Node* newNode = new Node(carry);
            newNode -> next = head;
            head = newNode;
        }
        
        return head;
    }
};