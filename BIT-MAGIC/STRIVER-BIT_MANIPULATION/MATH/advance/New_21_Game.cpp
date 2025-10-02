837. New 21 Game

Explanation :- 
https://youtu.be/x19SmqQbhWk?si=wu9B8sf7kfpKJc1e 

approach 1 : tle 

class Solution {
public: 
    // time o ( n * maxPts)
    double new21Game(int n, int k, int maxPts) {
        // p[i] - probability of getting score i
        vector<double>prob ( n + 1, 0.0);
        prob[0] = 1; ///score 0 initially
        for(int i = 1 ; i <= n; i++){
            for(int card = 1; card <= maxPts;card++){
                // prob of score card 1 / maxPPt
                // prob remain score p[i - card]
                if(i - card >= 0 && i - card < k){
                    prob[i] += prob[i - card] / maxPts;
                }
            }
        }
        return accumulate(prob.begin() + k , prob.end() , 0.0);
    }
};

appproach 2 : optimal

class Solution {
public:
    // time o ( n )
    double new21Game(int n, int k, int maxPts) {
        // p[i] - probability of getting score i
        vector<double> prob(n + 1, 0.0);
        prob[0] = 1; /// score 0 initially
        double currProbSum = (k == 0) ? 0 : 1;

        for (int i = 1; i <= n; i++) {
            prob[i] = currProbSum / maxPts;

            if (i < k) {
                currProbSum += prob[i]; // storing for future
            }
            if (i - maxPts >= 0 && i - maxPts < k) {
                currProbSum -= prob[i - maxPts];
            }
        }
        return accumulate(prob.begin() + k, prob.end(), 0.0);
    }
};