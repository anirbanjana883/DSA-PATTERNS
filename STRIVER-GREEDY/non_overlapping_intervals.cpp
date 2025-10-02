435. Non-overlapping Intervals

class Solution {
public:
    // time o (n log n)
    // space o(1)
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        // Sort intervals based on the end time
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        
        int count_nonOverlapping = 1;
        int limit = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= limit) {
                count_nonOverlapping++;
                limit = intervals[i][1];
            }
        }
        
        return intervals.size() - count_nonOverlapping;
    }
};