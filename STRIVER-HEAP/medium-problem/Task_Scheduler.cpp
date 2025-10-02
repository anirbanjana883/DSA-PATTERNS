621. Task Scheduler

approach 1 : using heap

class Solution {
public:
    //T.C : O(n)
    //S.C : O(1)
    int leastInterval(vector<char>& tasks, int p) {
        int n = tasks.size();
        unordered_map<char, int> mp;
        
        for(char &ch : tasks) {
            mp[ch]++;
        }

        priority_queue<int> pq; //max heap
        //we want to finish the process which is most occurring (having highest frequency)
        //so that we don't have to finish in the last with p gaps.
        int time = 0;
        
        for(auto &it : mp) {
            pq.push(it.second);
        }
        
        while(!pq.empty()) { 
            vector<int> temp;
            for(int i = 1; i<=p+1; i++) {
                //filling first p+1 characters
                if(!pq.empty()) {
                    temp.push_back(pq.top()-1); //finishing one instance of each process
                    pq.pop();
                }
            }
            
            for(int &freq : temp) { // can run max 26 times
                if(freq > 0)
                    pq.push(freq);
            }
            
            if(pq.empty()) //all processes finished
                time += temp.size();
            else
                time += (p+1); //we finished p+1 tasks above in the loop
            
        }
        
        return time;
    }
};


approach 2 : using greedy methode

class Solution {
public:
    // greedy approach :
    /*
        
        ["A","A","A","B","B","B"], k = 2
        A-3
        b-3
        A _ _ A _ _ A
        Number of chunks     = freq('A')-1 = 2
        Number of idol spots = (Number of chunks)*(p) = 2*2 = 4
            
        Now, we will try to fill these 4 idol spots
        If at the end idol spots is 0, it means all idol spots were enough
        to accomodate all other taks. So, out result will be tasks.size();
        
        If, idol spots are not empty, it means that we need more spaces (equal to idol spots)
        than the tasks.size() to accomodate all tasks.
        So, result = tasks.size() + idol_spots
        
        */
        
    // time o( n )
    // space o(1)
    int leastInterval(vector<char>& tasks, int p) {
        int n = tasks.size();
        if(p == 0) return n;
        vector<int>mp(26,0);
        for(auto &it : tasks){ // o(n)
            mp[it - 'A']++;
        }
        sort(mp.begin() , mp.end()); // sorted in ascending order 26log26
        int elWtihMaxFreq = mp[25];
        int gap = elWtihMaxFreq - 1;
        int idleSpot = gap * p;

        for(int i = 24 ; i >= 0 ; i--){ // o (26)
            idleSpot -= min( gap , mp[i]);
        }

        if(idleSpot > 0)
            return n + idleSpot;
        
        return n;
    }
};