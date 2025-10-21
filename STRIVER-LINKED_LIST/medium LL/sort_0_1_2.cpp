Sort a linked list of 0s, 1s and 2s

extreme broute force : using 3 veriable cnt0 cnt1 cnt2 like these [data assigning]


class Solution {
  public:
    // time o(2n) space o(1)
    Node* segregate(Node* head) {
        Node* temp = head;
        
        int cnt0 = 0,cnt1 = 0, cnt2 = 0;
        while(temp){
            if(temp -> data == 0) cnt0++;
            if(temp -> data == 1) cnt1++;
            if(temp -> data == 2) cnt2++;
            
            temp = temp -> next;
        }
        
        temp = head;
        while(temp){
            if(cnt0){
                temp -> data = 0;
                cnt0 --;
            }else if(cnt1){
                temp -> data = 1;
                cnt1 --;
            }else if(cnt2){
                temp -> data = 2;
                cnt2 --;
            }
            temp = temp -> next;
        }
        return head;
    }
};

optimised approach : 


class Solution {
public:
    // time o( n )
    // space o( 1 )
    Node* segregate(Node* head) {
        // Base case: empty list or single node
        if(!head || !head->next) return head;
        
        Node* dummy0 = new Node(-1);
        Node* dummy1 = new Node(-1);
        Node* dummy2 = new Node(-1);
        
        Node* temp0 = dummy0;
        Node* temp1 = dummy1;
        Node* temp2 = dummy2;
        
        Node* temp = head;
        
        while(temp){
            if(temp->data == 0) {
                temp0->next = temp;
                temp0 = temp0->next;
            } else if(temp->data == 1) {
                temp1->next = temp;
                temp1 = temp1->next;
            } else if(temp->data == 2) {
                temp2->next = temp;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        
        // Connect the three lists
        temp0->next = dummy1->next ? dummy1->next : dummy2->next;
        temp1->next = dummy2->next;
        temp2->next = nullptr;
        
        // Get the new head
        Node* newHead = dummy0->next;
        
        // Clean up dummy nodes
        delete dummy0;
        delete dummy1;
        delete dummy2;
        
        return newHead;
    }
};