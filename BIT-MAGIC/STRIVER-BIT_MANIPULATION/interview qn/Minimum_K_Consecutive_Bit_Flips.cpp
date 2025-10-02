995. Minimum Number of K Consecutive Bit Flips

similar problem -- 319. Bulb Switcher
3191. Minimum Operations to Make Binary Array Elements Equal to One I


broute force approach :

class Solution {
public:
    // time o( n * k)
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                // Check if we have enough elements to flip
                if(i + k > n) return -1;
                
                for(int j = 0; j < k; j++){
                    nums[i + j] = !nums[i + j];
                }
                cnt++;
            }
        }
        
        // Verify if all elements are 1
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) return -1;
        }
        return cnt;
    }
};

optimed approach 1 : see explanation
class Solution {
public:
    // time o(n)
    // space o(n)
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int flips = 0;
        int flipCountForPastI = 0;
        vector<bool>isFliped(n, false); // insted of this array we can modify the same input
        // then space compelxity will be o(1)

        for(int i = 0; i < n ; i++){
            if(i >= k && isFliped[i-k]){
                flipCountForPastI--;
            }

            /*
                if(flipCount[i] = odd && nums[i] = 1) = flip
                if(flipCount[i] = odd && nums[i] = 0) = no flip
                if(flipCount[i] = even && nums[i] = 1) = no flip
                if(flipCount[i] = even && nums[i] = 0) = flip
                this can be written in one word 
                if(flipCountForPastI % 2 == nums[i]) flip
            */
            if(flipCountForPastI % 2 == nums[i]){
                if(i + k > n) return -1;

                flipCountForPastI ++;
                flips ++;
                isFliped[i] = true;
            }
        }
        return flips;
    }
};

optimised approach 2 : using dequeue

class Solution {
public:
    // time o(n)
    // space o(1)
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int flips = 0;
        int flipCountForPastI = 0;
        deque<int>dq;

        for(int i = 0; i < n ; i++){
            if(i >= k){
                flipCountForPastI -= dq.front();
                dq.pop_front();
            }

            /*
                if(flipCount[i] = odd && nums[i] = 1) = flip
                if(flipCount[i] = odd && nums[i] = 0) = no flip
                if(flipCount[i] = even && nums[i] = 1) = no flip
                if(flipCount[i] = even && nums[i] = 0) = flip
                this can be written in one word 
                if(flipCountForPastI % 2 == nums[i]) flip
            */
            if(flipCountForPastI % 2 == nums[i]){
                if(i + k > n) return -1;

                flipCountForPastI ++;
                flips ++;
                dq.push_back(1) ;// 1 means we have made flip 
            }else{
                dq.push_back(0) ;// 0 means we dont made flip 
            }
        }
        return flips;
    }
};