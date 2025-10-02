947. Most Stones Removed with Same Row or Column


approach 1 : DFS techniquue - not a proper algo for ssolving this question

we can remove a stone if a stone is present in the same row or same Column

  0   1   2  so we cna remove 3 stone 
0 s       s

1     s

2 s       s 

 
s-------s
|       |
|   s   |
|       |
s       s so the question can be also solved by disjoint set union

so one member will always alive in on one group
>> so number of stone removed == (no of coordinate - no of groups)

class Solution {
public:
    void DFS(vector<vector<int>>&stones,int index,vector<bool>&visited){
        // mark visited
        visited[index]=true;

        for(int i=0;i<stones.size();i++){
            // check if not visited
            // check if the point is on same row or
            // the points is on same column
            int r=stones[index][0]; // retrive the x cordinate
            int c=stones[index][1]; // retrive the y cordinate
            if((visited[i]==false) && 
            (stones[i][0]==r || stones[i][1]==c)){
                DFS(stones,i,visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool>visited(n,false);

        int group=0;
        for(int i=0;i<n;i++){
            if(visited[i]==true){
                // if the stone is visited then do nothing
                continue;
            }
            // if not visited that means we need to put it in a group
            DFS(stones,i,visited);
            // whenevr we are doing dfs we are making a group extra 
            group++;
        }
        return (n-group);
    }
};


appproach 2 : [DFS]
this is a proper algo for solving the component related question 

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find_parent(int X) {
        // add code here
        if (parent[X] == X)
            return X;
        // insted of making a long chain we  are making one parent as
        // ultimate leadert for all the node
        return parent[X] = find_parent(parent[X]);
    }
    void unionSet(int X, int Z) {
        // add code here.
        //  finding the parenys of x
        int xParent = find_parent(X);

        // finding the parenys of z
        int yParent = find_parent(Z);

        // maing anyons parent as leader
        if (xParent == yParent) {
            return;
            // whose rank is greater it will become the parent
        } else if (rank[xParent] < rank[yParent]) {
            parent[xParent] = yParent;

        } else if (rank[xParent] > rank[yParent]) {
            parent[yParent] = xParent;

        } else {
            // bothn have same rank
            // makew anyone parent and then inc. its rank
            parent[xParent] = yParent;
            // we have make yparent as partent
            rank[yParent]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        // in each gorup only one people will survive
        // whne will be in same group - if in same row or column

        int number_of_stones = stones.size();
        parent.resize(number_of_stones , 0);
        rank.resize(number_of_stones ,0);

        for(int i = 0 ; i < number_of_stones ; i++){
            parent[i] = i;
            rank[i] = i;
        }        

        for(int i = 0 ; i < number_of_stones ; i++){
           for(int j = i +1 ; j < number_of_stones ;j++){
            if((stones[i][0] == stones[j][0]) || (stones[i][1] == stones[j][1])){
                unionSet(i , j); // parent vector will get upddated
            }
           }
        }

        int groupCount = 0;
        for(int i = 0 ;i < number_of_stones ;i++){
            if(parent[i] == i ) groupCount ++;
        }
        return number_of_stones - groupCount ;
    }
};