433. Minimum Genetic Mutation


class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // to avoid scarching wrod on bank by iterating
        unordered_set<string>bankSet(bank.begin(),bank.end());
        // visited vector to avoid viisting same string
        unordered_set<string>visited;
        queue<string>q;

        q.push(startGene);
        visited.insert(startGene);
        int lavel=0;
        while(!q.empty()){
           
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();

                // we have reached our target
                if(curr==endGene) return lavel;

                // we will access all the string by the char A C G T
                for(char ch:"ACGT"){
                    for(int i=0;i<curr.length();i++){
                        string NextPossibleString=curr;
                        // we will find next possible string of curr
                        // by changing each character
                        NextPossibleString[i]=ch; // first try with A then C etc

                        // now we cheak if the bank set not visited before
                        // and also if it is present in bank

                        if(visited.find(NextPossibleString)==visited.end() &&
                        bankSet.find(NextPossibleString)!=bankSet.end()){
                            // mark it visited and push it into queue
                            visited.insert(NextPossibleString);
                            q.push(NextPossibleString);
                        }
                    }
                } 
            }
            // one lavel end 
            lavel++;
        }
        return -1;
    }
};