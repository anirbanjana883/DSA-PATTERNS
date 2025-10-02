Shortest Job first

policy with leat execution time will executed first

bt = [4, 3, 7, 1, 2]
      p1 p2 p3 p4 p5
    
      0 - p4 - 1 - p5 - 3 - p2 - 6 - p1 - 10 - p3 -17
      total time = 20
      total policy = 5
      average = 20/5 = 4

class Solution {
  public:
    // time o(n + nlogn)
    // space o(1)
    long long solve(vector<int>& bt) {
        int n = bt.size();
        sort(bt.begin() , bt.end());
        int totalTime = 0;
        int t = 0;
        for(int i = 0;i < n ;i++){
            totalTime += t;
            t += bt[i];
        }
        return totalTime / n;
    }
};
