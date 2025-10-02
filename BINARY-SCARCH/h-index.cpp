274. H-Index


1. Brute Force Approach:
Sort the array of citations in descending order and iterate through the sorted array. For each paper, check if its citation count is greater than or equal to its position in the sorted array. Keep track of the maximum h-index encountered. This approach has a time complexity of O(n log n) due to the sorting step.

Time complexity: O(n log n)
space complexity: O(1)


class Solution {
public:

    int hIndexBruteForce(vector<int>& c) {
        sort(c.begin(), c.end());
        int n = c.size();
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            if(c[i] >= n - i) {
                maxi = max(maxi, n - i);
            }
        }
        return maxi;
    }

    int hIndex(vector<int>& citations) {
        return hIndexBruteForce(citations);
    }
};

2. Binary Search Approach:
Sort the array of citations and perform a binary search to find the h-index. Initialize a search range between 0 and the length of the citations array. In each iteration, calculate the mid-point and count the number of papers with citations greater than or equal to the mid-point. Adjust the search range based on this count. This approach has a time complexity of O(n log n) due to the sorting step.

Time complexity: O(n log n)
space complexity: O(1)

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int start = 0, end = n - 1;
        int ans = 0;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (citations[mid] >= n - mid)
            {
                ans = max(ans, n - mid);
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};