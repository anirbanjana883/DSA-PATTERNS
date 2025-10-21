Flattening a Linked List

broute force approach :

class Solution {
  public:
    // time o(nlogn)
    // space o(n)
    Node* array_to_ll(vector<int>&ans){
        
        if(ans.empty()) return NULL;
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        
        for(int i = 0; i < ans.size() ;i++){
            Node* newNode = new Node(ans[i]);
            temp -> bottom = newNode;
            temp = newNode;
        }
        return dummy -> bottom;
    }
    Node *flatten(Node *root) {
        
        if(!root || !root -> next ) return root;
        vector<int>ans;
        
        Node* temp = root;
        
        while(temp){
            Node* t = temp;
            
            while(t){
                ans.push_back(t -> data);
                t = t-> bottom;
            }
            temp = temp -> next;
        }
        sort(ans.begin() , ans.end());
        
        return array_to_ll(ans);
    }
}; 

optimised approach :




class Solution {
public:
    // Time Complexity: O(n * n * m)
    // Auxiliary Space: O(n)
    Node* mergeTwoLists(Node* list1, Node* list2) {
        Node* dummy = new Node(-1);
        Node* temp = dummy;

        Node* t1 = list1;
        Node* t2 = list2;
        
        while(t1 && t2){
            if(t1 -> data < t2 -> data){
            temp -> bottom = t1;
            t1 = t1 -> bottom;
            } else {
            temp -> bottom = t2;
            t2 = t2 -> bottom;                
            }
            temp = temp -> bottom;
        }
        
        // Attach remaining elements
        if(t1){
            temp -> bottom = t1;
        } else {
            temp -> bottom = t2;
        }
        
        return dummy -> bottom;
    }
    Node *flatten(Node *head) {
        if(!head || !head->next) return head;
        
        Node* mergedHead = flatten(head -> next);
        head = mergeTwoLists(head, mergedHead);
        
        return head;
    }
};