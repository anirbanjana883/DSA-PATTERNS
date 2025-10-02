1004. Max Consecutive Ones III

approach 1: broute force 
t.c O(N^2)
s.c O(1)

class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int n=nums.size();
            int maxLen=0;
            for(int i=0;i<n;i++){
                int noOfZeros=0;
                for(int j=i;j<n;j++){
                    if(nums[j]==0) noOfZeros++;
                    if(noOfZeros>k){
                        break;
                    }
                    maxLen=max(maxLen,j-i+1);
                }
            }
            return maxLen;
        }
    };


approach 2: better approach [2 pointer and sliding window]

t.c O(2*N)
s.c O(1)


class Solution {
    public:
        // t.c O(2*N)
        // s.c O(1)
        int longestOnes(vector<int>& nums, int k) {
            int n=nums.size();
            int maxLen=0;
            int l=0; //left
            int r=0; //right
            int zeros=0;
    
            while(r<n){
                // if it is zero then increment no of zero 
                if(nums[r]==0) zeros ++;
    
                // if no if zero is greater then k 
                // then trim down no of zeros 
                // nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
                //                 l r
                while(zeros>k){
                    if(nums[l]==0){
                        zeros--;                 
                    }
                     l++;
                }
                maxLen=max(maxLen,r-l+1);
                r++;
            }
            return maxLen;
        }
    };

approach 3 optimising the time complexity to O(N)

class Solution {
    public:
        int longestOnes(vector<int>& arr, int k) {
            // t.c O( N) s.c O(1)
                // when we are getting the zeros > k
                // we are not updating the length
                // and we trim of from left by [1 place]
                // and the process will repeat untill we get zeros = k
                // remeber once you get the max length you will not trim
                // the array less then the max length untill
                // untill you got length greatre then maxlength and zeros = k
                int n = arr.size();
            int l = 0;
            int r = 0;
            int maxlen = 0;
            int zeros = 0;
            while (r < arr.size()) {
                if (arr[r] == 0)
                    zeros++;
                if (zeros > k) {
                    if (arr[l] == 0) {
                        zeros--;
                    }
                    l++; // we should always move the pointer
                    //  regardless it is zero ot not
                }
                if (zeros <= k) {
                    maxlen = max(maxlen, r - l + 1);
                }
                r++;
            }
            return maxlen;
        }
    };