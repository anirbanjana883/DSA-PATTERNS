1423. Maximum Points You Can Obtain from Cards

approach :
cardPoints = [1,2,3,4,5,6,1], k = 3

lsum 1+2+3=6  rsum=0   totalsum=lsum+rsum=6
lsum 1+2=3  rsum=1   totalsum=lsum+rsum=4
lsum =1  rsum=1+6   totalsum=lsum+rsum=8
lsum =0  rsum=1+6+5   totalsum=lsum+rsum=12 (max)(ans)

class Solution {
    public:
        int maxScore(vector<int>& cardPoints, int k) {
            // t.c O(2*N)
            // s.c O(1)
            
            int lsum = 0;
            int rsum = 0;
            int n = cardPoints.size();
            
            // Calculate the initial left sum by taking the first 'k' cards
            for (int i = 0; i < k; ++i) {
                lsum += cardPoints[i]; // first calulating the sum of first k element 
            }
            
            int maxScore = lsum;
            
            // Now gradually move the right window inwards
            // and shrink the left window, updating the sums
            for (int i = 0; i < k; ++i) {
                lsum -= cardPoints[k - 1 - i];
                rsum += cardPoints[n - 1 - i];
                maxScore = max(maxScore, lsum + rsum);
            }
            
            return maxScore;
        }
    };
    