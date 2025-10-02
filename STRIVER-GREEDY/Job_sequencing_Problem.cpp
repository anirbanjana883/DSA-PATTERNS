Job sequencing Problem

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
        // time nlogn
        // space O(n)
public:
    // Custom comparator to sort jobs in descending order of profit
    static bool compareProfit(const pair<int, int>& job1, const pair<int, int>& job2) {
        return job1.first > job2.first; // Higher profit comes first
    }

    vector<int> jobSequencing(vector<int>& deadlines, vector<int>& profits) {
        int numJobs = deadlines.size();
        vector<pair<int, int>> jobs; // Stores {profit, deadline} pairs

        // Step 1: Pair each job's profit with its deadline
        for (int i = 0; i < numJobs; i++) {
            jobs.push_back({profits[i], deadlines[i]});
        }

        // Step 2: Sort jobs in descending order of profit (most profitable first)
        sort(jobs.begin(), jobs.end(), compareProfit);

        // Find the maximum deadline to determine the required slots
        int maxDeadline = *max_element(deadlines.begin(), deadlines.end());

        // Step 3: Initialize a schedule to track filled job slots
        vector<int> schedule(maxDeadline + 1, -1); // -1 means slot is empty

        int totalProfit = 0;
        int jobsScheduled = 0;

        // Step 4: Schedule jobs greedily
        for (const auto& job : jobs) {
            int currentProfit = job.first;
            int currentDeadline = job.second;

            // Try to place the job in the latest possible slot before its deadline
            for (int day = currentDeadline; day > 0; day--) {
                if (schedule[day] == -1) { // If slot is available
                    schedule[day] = 1;     // Mark slot as filled
                    totalProfit += currentProfit;
                    jobsScheduled++;
                    break; // Move to the next job
                }
            }
        }

        return {jobsScheduled, totalProfit};
    }
};