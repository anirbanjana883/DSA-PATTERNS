1079. Letter Tile Possibilities

approach1:

t.c O(n!)
s.c O(n*n!)+O(N)[for resusn stack space ]
class Solution {
    public:
        unordered_set<string>s;
        int n;
        void solve(int idx,string &tiles,string temp,vector<bool>&visited){
            s.insert(temp);
            for(int i=0;i<n;i++){
                if(visited[i]==false){
                visited[i]=true;
                temp.push_back(tiles[i]);
                solve(idx+1,tiles,temp,visited);
                temp.pop_back();
                visited[i]=false;
                }
            }
        }
        int numTilePossibilities(string tiles) {
            // to avoid duplicate element we  need 
            // unordered set
            n=tiles.size();
            vector<bool>visited(n,0);
            solve(0,tiles,"",visited);
            return s.size()-1; // because we have taken an empty string also 
        }
    };


appproach 2:

since we are using some character multiple time we 
dont need to stroe the index 
we can use freequency arr

class Solution {
    public:
        unordered_set<string>result;
        
        void solve(string s,int n,string temp,vector<int>&freq){
            result.insert(temp);
    
            for(int i=0;i<n;i++){
                if(freq[s[i]-'A']==0) continue;
                temp.push_back(s[i]); // take 
                freq[s[i]-'A']--;
                solve(s,n,temp,freq);
                temp.pop_back(); // not take
                freq[s[i]-'A']++;
            }
        }
        int numTilePossibilities(string tiles) {
            int n=tiles.size();
            vector<int>freq(26,0);
            for(int i=0;i<n;i++){
                freq[tiles[i]-'A']++;
            }
            string temp="";
            solve(tiles,n,temp,freq);
            return result.size()-1;
        }
    };