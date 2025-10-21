138. Copy List with Random Pointer

approach 1 :

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // since we are making a deep copy s we should keep a track 
        // of each node in original LL 
        // and also corresponding copy node 
        if(head==NULL) return NULL;

        unordered_map<Node*,Node*>mp;
        // head= of org ll
        Node* curr=head;
        Node* prev=NULL;
        // head of copy LL
        Node* newHead=NULL;

        while(curr){
            // creating a new node 
            Node* temp=new Node(curr->val);

            mp[curr]=temp; // updating node
            if(newHead==NULL){ // no node formed yet
                newHead=temp;
                prev=newHead;
            }else{
                // pointing the new node 
                prev->next=temp;
                // making the nue node as prev
                prev=temp;
            }
            curr=curr->next;
        }
        // now its time to fill the random pointer 
        curr         =head;
        Node* newCurr=newHead;
        while(curr){
            if(curr->random==NULL){ // if current nodes random points to null
                newCurr->random=NULL;
            }else{
                newCurr->random=mp[curr->random];
            }
            curr=curr->next;
            newCurr=newCurr->next;
        }
        return newHead;
    }
};


approach 2 :

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        
        Node* curr = head;
        
        while(curr) {
            Node* currNext = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = currNext;
            curr = currNext;
        }
        
        //Deep copy of random pointers
        curr = head;
        while(curr && curr->next) {
            if(curr->random == NULL) {
                curr->next->random = NULL;
            } else {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        //Deep copy of next pointers and recovering old linked list
        Node* newHead = head->next;
        Node* newCurr = newHead;
        curr          = head;
        while(curr && newCurr) {
            curr->next    = curr->next ? curr->next->next : NULL;
            
            newCurr->next = newCurr->next ? newCurr->next->next : NULL;
            
            curr = curr->next;
            newCurr = newCurr->next;
        }
       
        return newHead;        
    }
};

