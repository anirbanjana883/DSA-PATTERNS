135. Candy

broute force approach 

class Solution {
public:
    // time  o ( 3 * n)
    // time  o ( 2 * n)
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>leftToRight(n);
        vector<int>rightToLeft(n);
        int lToR = 1;
        int rToL = 1;
        leftToRight[0] = 1;
        rightToLeft[n-1] = 1;
        // going left to right 
        for(int i = 1 ;i < n ; i++){
            if(ratings[i] > ratings[i - 1]){
                lToR ++;
            }else{
                lToR = 1;
            }
            leftToRight[i] = lToR;
        }
        // going right to left 
        for(int i = n-2 ;i >= 0 ; i--){
            if(ratings[i] > ratings[i + 1]){
                rToL ++;
            }else{
                rToL = 1;
            }
            rightToLeft[i] = rToL;
        }
        int MinCandy = 0;
        // finding the max from left and right 
        for(int i = 0 ; i < n ; i++){
            int tmp = max (leftToRight[i] , rightToLeft[i]);
            MinCandy += tmp;
        }
        return MinCandy;
    }
};

optimised approach :

class Solution {
public:
    // time o( 2 * n)
    // space o(n)
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;
        
        vector<int> leftToRight(n, 1);
        
        // Left to right pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                leftToRight[i] = leftToRight[i - 1] + 1;
            }
        }
        
        // Right to left pass and calculate sum
        int total = leftToRight[n - 1]; // Start with the last element
        int curr = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                curr = curr + 1;
            } else {
                curr = 1;
            }
            total += max(leftToRight[i], curr);
        }
        
        return total;
    }
};

optimal approach :

class Solution {
public:
    // time o(n)
    // space o(1)
    int candy(vector<int>& ratings) {
        // slope concept 
        int n = ratings.size();
        int sum = 1;
        int i = 1;
        while( i < n){
            if( ratings[i] == ratings[i-1]){
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            // increasing slope 
            while(i < n && ratings[i] > ratings[i-1]){
                peak += 1;
                sum += peak;
                i++;
            }
            int down = 1;
            // decreasing slope
            while( i < n && ratings[i] < ratings[i-1]){
                sum += down;
                i++;
                down ++;
            }
            if(down > peak) sum += down - peak;
        }
        return sum;
    }
};