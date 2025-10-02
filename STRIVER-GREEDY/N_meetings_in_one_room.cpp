N meetings in one room

class Solution {
    // time o(2*n + nlogn)
    // space o(3*n)
    // where n is the number of meetings
public:
    struct meeting {
       int start;
       int end;
       int id;
    };
    
    static bool comp(struct meeting m1, struct meeting m2) {
        if (m1.end < m2.end) return true;
        if (m1.end > m2.end) return false;
        if (m1.id < m2.id) return true; // if same end time
        return false;
    }
    
    int maxMeetings(vector<int>& s, vector<int>& e) {
        // here in the question not asking for order for 
        // meeting but it can be asked in an interview 
        int n = s.size();
        struct meeting meet[n];
        for(int i = 0; i < n; i++) {
            meet[i].start = s[i];
            meet[i].end = e[i];
            meet[i].id = i + 1;
        }
        // sorting on the basis of end time 
        vector<int> answer;
        sort(meet, meet + n, comp);
        
        int meeting_count = 1;
        int limit = meet[0].end;
        answer.push_back(meet[0].id);
        
        for(int i = 1; i < n; i++) {
            if(meet[i].start > limit) {
                meeting_count++;
                limit = meet[i].end;
                answer.push_back(meet[i].id);
            }
        }
        // if asked print the id in oder
        return meeting_count;
    }
};

class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<vector<int>> meetings;

        // Store each meeting as {start, end, id}
        for (int i = 0; i < n; i++) {
            meetings.push_back({start[i], end[i], i + 1});
        }

        // Sort meetings based on end time, then by ID if end times are equal
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) {
                return a[1] < b[1];
            }
            return a[2] < b[2];
        });

        int count = 0;
        int lastEnd = -1; // Initialize to an invalid time

        for (const auto& meeting : meetings) {
            if (meeting[0] > lastEnd) {
                count++;
                lastEnd = meeting[1];
            }
        }

        return count;
    }
};