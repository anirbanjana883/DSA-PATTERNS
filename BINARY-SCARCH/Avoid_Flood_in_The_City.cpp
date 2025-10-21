1488. Avoid Flood in The City


class Solution {
public:
    // time n + logn ( log n for lower bound)
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        unordered_map<int,int>mp;
        set<int>st; // days in which rain is zero

        vector<int> ans(n,1);

        for(int i = 0 ; i < n ; i++){
            int lake = rains[i];

            if(lake == 0){  
                st.insert(i); // string the day in which we can dry lake later
            }else{ // wll be rain
                ans[i] = -1;
                // also check is this lake contains water 
                // if yes then we will dry it up
                if(mp.count(lake)){
                    auto it = st.lower_bound(mp[lake]); // return an iterator
                    // which indicate just after the day when there is no rain
                    if(it == st.end()){ // day day not found
                        // cant  dry this lake
                        return {};
                    }
                    // dry day
                    int day = *it;
                    ans[day] = lake;

                    st.erase(it); // in that day i can not dry any ather lake 
                }
                mp[lake] = i; // ith day it ran on lake
            }
        }
        return ans;
    }
};