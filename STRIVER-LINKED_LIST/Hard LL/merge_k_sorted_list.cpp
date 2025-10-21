23. Merge k Sorted Lists

approach 1 :

class Solution {
public:
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

approach 2:

class Solution {
public:
    // Merges two lists in O(n+m) time, O(1) space (reuses nodes)
    ListNode* merge_two_sorted_list(ListNode* list1, ListNode* list2) {
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

    // Optimal O(nk log k) solution using divide and conquer
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        if (lists.empty()) return nullptr;
        
        int n = lists.size();
        int interval = 1;
        
        while (interval < n) {
            for (int i = 0; i < n - interval; i += interval * 2) {
                lists[i] = merge_two_sorted_list(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        
        return lists[0];
    }
};

approach 3 :


class Solution {
public:
    // time o(klogk + nklogk)
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
        
        while(!pq.empty()){
            auto [val,node] = pq.top();
            pq.pop();
            
            temp ->next = node;
            temp = temp->next;

            if(node->next){
                pq.push({node->next->val , node->next});
            }
        }
        return dummy->next;
    }
};