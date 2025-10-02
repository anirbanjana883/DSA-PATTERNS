
Longest Subarray Length [gfg]

Approach
Compute next greater index to the right for every position (nextGreater)

Traverse from right → left. Maintain a stack of indices whose values are in strictly decreasing order (top is the nearest greater to the right candidate).

For current index i, pop while top’s value ≤ nums[i]. After popping, if stack is not empty, the top is the index of the next greater element. If stack is empty, there is no greater to the right — use n as sentinel.

Compute previous greater index to the left for every position (prevGreater)

Traverse from left → right and use the same pattern: maintain indices of a strictly decreasing sequence. For current index i, pop while top’s value ≤ nums[i]. After popping, if stack not empty, top is prev greater; otherwise use -1 as sentinel.

For each index i, compute the largest window where nums[i] is maximum

windowLen = nextGreater[i] - prevGreater[i] - 1

If windowLen >= nums[i] then this window satisfies the requirement (since max in it is nums[i] and nums[i] ≤ windowLen).

Track the maximum windowLen that satisfies the condition.

Return the maximum found. If none qualify, final answer is 0.

Quick worked example
nums = [1,2,3]:

For index 2 (value 3): prevGreater = -1, nextGreater = 3 (sentinel), windowLen = 3 → 3 ≥ 3 so answer = 3. That’s the entire array.

nums = [6,4,2,5]:

For any index i the windowLen (max possible) is always < the element (e.g., for 6 there’s no window of length ≥6 because array length is 4). So answer = 0.

Complexity
Time complexity: O(n)
Space complexity: O(n) 

class Solution {
public:
    // Find index of next strictly greater element to the right for each position
    vector<int> computeNextGreaterIndices(const vector<int>& nums) {
        int lengthOfArray = nums.size();
        vector<int> nextGreaterIndex(lengthOfArray, lengthOfArray); // default sentinel: no greater → n
        stack<int> indexStack;

        for (int readPos = lengthOfArray - 1; readPos >= 0; --readPos) {
            // Pop all elements ≤ current, since they can't be "next greater"
            while (!indexStack.empty() && nums[indexStack.top()] <= nums[readPos]) {
                indexStack.pop();
            }
            if (!indexStack.empty()) {
                nextGreaterIndex[readPos] = indexStack.top();
            }
            indexStack.push(readPos);
        }
        return nextGreaterIndex;
    }

    // Find index of previous strictly greater element to the left for each position
    vector<int> computePrevGreaterIndices(const vector<int>& nums) {
        int lengthOfArray = nums.size();
        vector<int> prevGreaterIndex(lengthOfArray, -1); // default sentinel: no greater → -1
        stack<int> indexStack;

        for (int readPos = 0; readPos < lengthOfArray; ++readPos) {
            while (!indexStack.empty() && nums[indexStack.top()] <= nums[readPos]) {
                indexStack.pop();
            }
            if (!indexStack.empty()) {
                prevGreaterIndex[readPos] = indexStack.top();
            }
            indexStack.push(readPos);
        }
        return prevGreaterIndex;
    }

    int longestSubarray(vector<int>& nums) {
        int total = nums.size();
        vector<int> nextGreater = computeNextGreaterIndices(nums);
        vector<int> prevGreater = computePrevGreaterIndices(nums);

        int bestValidLength = 0;
        for (int position = 0; position < total; ++position) {
            int windowLength = nextGreater[position] - prevGreater[position] - 1;
            // Check if the maximum element of this window (nums[position]) fits the condition
            if (windowLength >= nums[position]) {
                bestValidLength = max(bestValidLength, windowLength);
            }
        }
        return bestValidLength;
    }
};