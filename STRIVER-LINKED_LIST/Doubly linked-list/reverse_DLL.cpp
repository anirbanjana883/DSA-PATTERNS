broute force approach : 
Time Complexity : O(2N)


// Funcion to reverse a doubly linked list
// Stack Brute Force Approach
Node* reverseDLL(Node* head){
    // if head is empty or there is only one element
    // we can directly just return the head
    if(head==NULL || head->next == NULL){
        return head;
    }
    
    // Initialise a stack st
    stack<int> st;
    
    // Initialise the node pointer temp at head
    Node* temp = head;
    
    // Traverse the doubly linked list via the temp pointer
    while(temp!=NULL){
        // insert the data of the current node into the stack
        st.push(temp->data);
        // traverse further
        temp = temp->next;
    }
    
    // Reinitialise temp to head
    temp = head;
    
    // Second iteration of the DLL to replace the values
    while(temp!=NULL){
        // Replace the value pointed via temp with
        // the value from the top of the stack
        temp->data = st.top();
        // Pop the value from the stack
        st.pop();
        // Traverse further
        temp = temp->next;
    }
    
    // Return the updated doubly linked 
    // where the values of nodes from both ends 
    // has been swapped
    return head;

}


optimised approach : 
Time Complexity : O(N)
Space Complexity : O(1),

 
// Function to reverse a doubly linked list
// In-place link exchange method
Node* reverseDLL(Node* head) {
    
    // Check if the list is empty
    // or has only one node
    if (head == NULL || head->next == NULL) {
        // No change is needed;
        // return the current head
        return head; 
    }
    
     // Initialize a pointer to
     // the previous node
    Node* prev = NULL;  
    
    // Initialize a pointer to
    // the current node
    Node* current = head;   

    // Traverse the linked list
    while (current != NULL) {
        // Store a reference to
        // the previous node
        prev = current->back; 
        
        // Swap the previous and
        // next pointers
        current->back = current->next; 
        
        // This step reverses the links
        current->next = prev;          
        
        // Move to the next node
        // in the original list
        current = current->back; 
    }
    
    // The final node in the original list
    // becomes the new head after reversal
    return prev->back;
}

