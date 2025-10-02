703. Kth Largest Element in a Stream

Trick -> ->
kth largest - MINHEAP
kth smallest - MAXHEAP

class KthLargest {
public:
    // time o(logk)
    // space o(k)
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) { // o(logk)
        // minheap 
        this->k = k;
        for(auto &it:nums){
            pq.push(it);
            if(pq.size() > k) {
                pq.pop(); // min element will be popped 
            }
        }
    }
    
    int add(int val) {  // o(logk)
        pq.push(val);
        if(pq.size() > k) {
            pq.pop(); // min element will be popped 
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */