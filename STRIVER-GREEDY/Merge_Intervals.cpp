56. Merge Intervals

broute force approach :

class Solution {
public:
    // time o(nlogn + 2*n)
    // space o(n)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};
        
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            // Skip if this interval is already merged
            if (!ans.empty() && start <= ans.back()[1]) {
                continue;
            }
            
            // Check for overlapping intervals
            for (int j = i + 1; j < n; j++) {
                if (intervals[j][0] <= end) {  // There's overlap
                    end = max(end, intervals[j][1]);
                } else {
                    break;
                }
            }
            
            ans.push_back({start, end});
        }
        
        return ans;
    }
};
optimised approach :

class Solution {
public:
    // time o ( nlog n + n)
    // space o( n)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin() , intervals.end());
        for(int i = 0 ;i < n; i ++){
            // non overlapping interval
            if(ans.empty() || ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }else{ // overlapping interval
                ans.back()[1] = max( ans.back()[1] , intervals[i][1]);
            }
        }
        return ans;
    }
};