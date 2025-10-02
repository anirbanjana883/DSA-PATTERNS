Nearly sorted

Given an array arr[], where each element is at most k away from its target position, you need to sort the array optimally.

class Solution {
  public:
    // time o(n log k)
    // space o( k )
    void nearlySorted(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int , vector<int> , greater<int> >pq;
        int ind = 0;
        for(int i = 0; i < n ; i++){
            if(pq.size() > k){
                arr[ind] = pq.top();
                pq.pop();
                ind ++;
            }
            pq.push(arr[i]);
        }
        // if heap still have element 
        while(!pq.empty()){
            arr[ind] = pq.top();
            pq.pop();
            ind ++;
        }
    }
};