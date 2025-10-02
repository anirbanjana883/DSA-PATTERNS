leetcode 990. Satisfiability of Equality Equations

class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    void unionset(int x,int y){
        int xParent=find(x);
        int yParent=find(y);

        if(xParent==yParent) return;
        else if(parent[xParent]<parent[yParent]){
            parent[xParent]=yParent;
        }else if(parent[xParent]>parent[yParent]){
            parent[yParent]=xParent;
        }else{
            parent[xParent]=yParent;
            rank[yParent]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);// as all are samller case letter
        rank.resize(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
            rank[i]=1;
        }
        // according to the question firdt do union of characters
        // we can determine equal or not by 1st index only
        for(auto &s:equations){
            if(s[1]=='='){
                unionset(s[0]-'a',s[3]-'a');
            }
        }
        // for not equal cases
        for(auto &s:equations){
            if(s[1]=='!'){ //a!+b
            char first=s[0];
            char second=s[3];

            int parentFirst=find(first-'a');
            int parentSecond=find(second-'a');

            if(parentFirst==parentSecond) return 0; //although a !=b but their parent are same thats means contradictory
            }
        }
        return 1;
    }
};