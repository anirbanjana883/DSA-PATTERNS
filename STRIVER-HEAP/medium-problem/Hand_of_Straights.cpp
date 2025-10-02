846. Hand of Straights

class Solution {
public:
    // time ((n * groupSize) + nlogn)
    // space o (n)
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0){
            return false;
        }

        map<int , int> mp; 
        for(auto &it : hand){
            mp[it]++; // nlogn for putting into ordered map
        }
        int grpCount = 0;
        while(!mp.empty()){
            int curr = mp.begin()->first; // seconf freq
            // see the loop runnnig fro 0 to < groupSize 
            // it automatically handle the element from current to groupsize
            for(int i = 0 ;i < groupSize ; i++){
                if(mp[curr + i] == 0) return false;

                mp[curr + i]--;
                if(mp[curr + i] == 0) mp.erase(curr + i);
            }
        }

        return true;
    }
};