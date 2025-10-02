Replace elements by its rank in the array


#include<bits/stdc++.h>
class Solution {
  public:
    // time o(nlogn)
    // space o (n)
    typedef pair<int,int> p;

    vector<int> replaceWithRank(vector<int> &arr, int n) {
        priority_queue<p, vector<p>, greater<p>> pq;

        for(int i = 0; i < n; i++){
            pq.push({arr[i], i});
        }

        int rank = 1;
        unordered_map<int, int> valueToRank; // to handle duplicate elemnt 

        while (!pq.empty()) { 
            auto p= pq.top();
            pq.pop();

            if (valueToRank.count(p.first) == 0) {
                valueToRank[p.first] = rank;
                rank++;
            }

            arr[p.second] = valueToRank[p.first];
        }

        return arr;
    }
};
