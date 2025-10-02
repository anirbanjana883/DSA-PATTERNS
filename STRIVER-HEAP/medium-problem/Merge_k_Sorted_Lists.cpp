23. Merge k Sorted Lists

broute force approach :

class Solution {
public:
    // time o( n * k + nlogn + n)
    // space o ( n )
    ListNode* convert(vector<int>&arr){
        if(arr.empty()) return NULL;

        ListNode* head = new ListNode(arr[0]);
        ListNode* curr = head;
        for(int i = 1 ; i < arr.size(); i++){
            curr -> next = new ListNode(arr[i]);
            curr = curr -> next;
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>arr;
        int n = lists.size();
        for(int i = 0 ;i < n ; i++){
            ListNode* temp = lists[i];
            while(temp){
                arr.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(arr.begin(),arr.end());
        ListNode* head = convert(arr);
        return head;
    }
};

optimised approach :

class Solution {
public:
    // o( n ^ 3)
    // Merges two sorted lists (reuses nodes, no new allocations)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(-1);
        ListNode* tail = &dummy;
        
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }

    // Normal iterative approach (O(NK²) time)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        ListNode* merged = nullptr;
        
        if (lists.empty()) return nullptr;
        
        merged = lists[0];
        
        // Sequentially merge each list
        for (int i = 1; i < lists.size(); i++) {
            merged = mergeTwoLists(merged, lists[i]);
        }
        
        return merged;
    }
};

most optimal solution 

class Solution {
public: 
    // time ( klgok + n*klogk)
    // space o(k)
    typedef pair<int, ListNode*> p;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<p, vector<p>, greater<p>> pq;
        for(int i = 0 ; i < n ;i++){
           if(lists[i]) {
            pq.push({lists[i]->val,lists[i]});
           }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        
        while(!pq.empty()){ // k * n
            auto [val,node] = pq.top();
            pq.pop();
            
            temp ->next = node;
            temp = temp->next;

            if(node->next){
                pq.push({node->next->val , node->next}); // log k
            }
        }
        return dummy->next;
    }
};