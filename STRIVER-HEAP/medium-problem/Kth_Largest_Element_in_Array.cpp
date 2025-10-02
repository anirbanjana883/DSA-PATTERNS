215. Kth Largest Element in an Array

priority_queue<int> pq; // max-heap (returns largest element first)
priority_queue<int, vector<int>, greater<int>> pq; // min-heap (returns smallest first)

approach 1 : sortng in decending order
sort(nums.begin() , nums.end() , greater<int>);
time o( nlogn)

approach 2 : using priority_queue
class Solution {
public:
    // time o ( n logk)
    // space o (k)
    int findKthLargest(vector<int>& nums, int k) {
        // we will always keep the size of heap k
        // by default max heap 
        priority_queue<int , vector<int> , greater<int>>pq; // min heap
        for(auto &it:nums){
            pq.push(it);
            if( pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};

approach 3 : using quick select [HOARS PARTITION ALGORITHM]

class Solution {
public:
    // time o ( n ^ 2) worst
    // time o ( n) avg
    // space o (k)
    int findPivot(vector<int>& nums ,int l, int r){
        int pivotEl = nums[l]; // taking as a temp pivot elemrntt
        int i = l + 1;
        int j = r;
        while( i <= j){
            // (a ,b ,c) > d > (e, f)
            if(nums[i] < pivotEl && pivotEl < nums[j]){
                swap(nums[i] , nums[j]);
                i++;
                j--;
            }else if(nums[i] >= pivotEl){ // ok element
                i++;
            }else if(nums[j] <= pivotEl){
                j--;
            }
        }
        swap(nums[l] , nums[j]);
        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {
        // (a ,b ,c) > d > (e, f)
        // so it si sure that d will be the 4th largest
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int pivot_idx = 0;
        while(l <= r){
            pivot_idx = findPivot(nums, l ,r );
            if(pivot_idx == k-1){
                break;
            }else if( pivot_idx < k - 1){
                l = pivot_idx + 1;
            }else{
                r = pivot_idx - 1;
            }
        }
        return nums[pivot_idx];
    }
};

