1353. Maximum Number of Events That Can Be Attended

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        /*
        > for any day is i have choice to select among event 
          i will choose the event that ends earlier

        > and skips the event whose endDay < day
        */

        int n = events.size();
        // sorting base don starting day 
        sort(events.begin(),events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int day = events[0][0];
        int i = 0;
        int count = 0; // max event that can be attended 

        while(!pq.empty() || i < n){
            while( i < n && events[i][0] == day ){
                // pushing the end day on min heap
                pq.push(events[i][1]);
                i++;
            }

            if(!pq.empty()){
                pq.pop();
                count ++; // event attended 
            }

            day++;
            // skip those event whose end day is less then day 
            while(!pq.empty() && pq.top() < day){
                pq.pop();
            }
        }
        return count ;
    }
};