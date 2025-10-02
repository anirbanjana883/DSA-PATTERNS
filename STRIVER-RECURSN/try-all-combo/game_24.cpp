679. 24 Game

class Solution {
public:
    // time o(1)
    // space o(1)
    double epsilon = 0.1;
    bool solve(vector<double>cards){
        if(cards.size() == 1){
            return abs(cards[0] - 24) <= epsilon;
        }

        for(int i = 0 ; i < cards.size();i++){
            for(int j = 0 ; j < cards.size(); j++){
                if( i == j) continue;

                vector<double>temp;
                for(int k = 0 ; k < cards.size(); k++){
                    if(k != i && k != j){
                        temp.push_back(cards[k]);
                    }
                }

                double a = cards[i];
                double b = cards[j];

                vector<double>possibleVal = {a + b , a - b , a * b};
                if(a > 0){
                    possibleVal.push_back(a / b);
                }
                if(b > 0){
                    possibleVal.push_back(b / a);
                }

                for(auto val : possibleVal){
                    temp.push_back(val);
                    if(solve(temp) == true){
                        return true;
                    }
                    temp.pop_back();
                }

            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double>nums(cards.size());
        for(int i = 0 ; i < cards.size(); i++){
            nums[i] = cards[i] * 1.0; // converting to double;
        }   
        return solve(nums);
    }
};