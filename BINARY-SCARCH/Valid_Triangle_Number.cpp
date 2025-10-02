611. Valid Triangle Number

approach 1 :

class Solution {
public:
    // time o ( n ^ 3)
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;
        for(int i = 0; i < n - 2 ; i++){
            for(int j = i + 1; j < n - 1; j++){
                for(int k = j + 1; k < n ;k ++){
                    if((nums[i]+nums[j] > nums[k])
                    && (nums[i]+nums[k] > nums[j])
                    && (nums[j]+nums[k] > nums[i])) cnt ++;
                }
            }
        }
        return cnt ;
    }
};

approach 2 :

nums = [4,2,3,4] if we sort it - 2 3 4 4

then we just need to check if 2 + 3 > 4 or not ? ather condition will automaticly get checked


class Solution {
public:
    // time = {(n ^ 2) log n}
    int BS(vector<int>& nums,int left ,int right,int target){
        int k = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;

            if(nums[mid] < target) {
                k = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return k;
    }
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if( n < 3) return 0;
        sort(nums.begin(),nums.end());
        int count = 0;
        for(int i = 0; i < n - 2 ; i++){
            if(nums[i] == 0) continue;
            for(int j = i + 1 ; j < n - 1; j++){
                int sm = nums[i] + nums[j];
                int k = BS(nums , j + 1, n - 1, sm);
                if( k != -1) count += k - j;
            }
        }
        return count ;
    }
};

approach 3 :

class Solution {
public:
    // time = {(n ^ 2) }

    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int k = n - 1; k >= 2; k--) {
            int i = 0;
            int j = k - 1;

            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    count += j - i;
                    j--;
                } else {
                    i++;
                }
            }
        }
        return count;
    }
};