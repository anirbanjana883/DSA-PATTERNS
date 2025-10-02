451. Sort Characters By Frequency

approach sorting | lambda function

class Solution {
public:
    //  t O(n + k log k + n)
    // s o(1)
    string frequencySort(string s) {
        /*
        can also do it using map but then to sort we
        need to store the map in vector again 
        */
        vector<pair<char,int>>hash(123);
        for(char &ch : s){
            int freq = hash[ch].second;
            hash[ch] = {ch , freq+1};
        }
        // ustom sorting
        auto lambda=[&](auto &p1,auto &p2){
            return p1.second>p2.second;
        };
        sort(hash.begin(),hash.end(),lambda);
        string result="";
        for(int i=0;i<123;i++){
            if(hash[i].second!=0){ // means here element not present
                char ch = hash[i].first;
                int freq = hash[i].second;
                string temp = string ( freq,ch);
                result += temp;
            }
        }
        return result;
    }
};

approach  priority queue | heap 

class Solution {
public:
    typedef pair<char,int> p;
    string frequencySort(string s) {
         // define lambda comparator
        auto cmp = [](p &a, p &b) {
            return a.second < b.second; // max heap by frequency
        };

        // define priority_queue with std::function
        priority_queue<p, vector<p>, decltype(cmp)> pq(cmp);
        unordered_map<char,int>mp;
        // buiding the map
        for(auto &ch : s){
            mp[ch]++;
        }
        // pushing into the priority queue
        for(auto &it : mp){
            pq.push({it.first,it.second});
        } 
        string result="";
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            char ch = top.first;
            int freq = top.second;
            string temp = string (freq,ch);
            result += temp;
        }
        return result;
    }
};