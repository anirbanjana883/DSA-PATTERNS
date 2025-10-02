1926. Nearest Exit from Entrance in Maze

why graph ?
se in bfs we trsvarse lavel wise 
so from entrance if we travarse lavelwise then we will get the nearest exit from entrance
           |----------|
           | -------- |
           | |      | |
           | |   E  | | like a rader signal ha ha ha!
           | |------| |
           |----------|


boundary means eaither
 left boundary or right boundary  boundary(i,j)= i==0 || i==n-1
                   or   
 up boundary or donw boundary  boundary(i,j)= j==0 || j==n-1

 an entrance should not be exit i,j!=Entrance

 we will take any point and go to each direction (cheaking if the direction is feasible or not)
 and check if this is boundary[exit] or not if feasible and not boundary then push it into the queue
 
 
class Solution {
    public:
    // direction vector
        vector<vector<int>>direction={{0,-1},{0,1},{1,0},{-1,0}};
        
        int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
            int n=maze.size();
            int m=maze[0].size();

            queue<pair<int,int>>q;
            // pushing the entrance coordinate into the queue
            q.push({entrance[0],entrance[1]});
            // marking the cell as visited
            maze[entrance[0]][entrance[1]]='+';

            int noOfStep=0;
            // classic bfs code 
            while(!q.empty()){
                int N=q.size();
                while(N--){
                    pair<int,int>temp=q.front();
                    q.pop();

                    int x=temp.first;
                    int y=temp.second;
                    // cheaking if we reach to exit or we reach back to entrance cell
                    if((temp!=make_pair(entrance[0],entrance[1]))
                    &&( x==0||x==n-1||y==0||y==m-1)){
                        // that means we have found our exit
                        return noOfStep;
                    }

                    // atherwiswe explore the ather paths also

                    for(auto &dir:direction){
                        int new_x=x+dir[0];
                        int new_y=y+dir[1];

            // cheak if the neighbour is pushable into queue or not 
                        // means there should no be wall or boundary
                        if(new_x>=0 && new_x<n && new_y>=0 && new_y<m &&
                        maze[new_x][new_y]!='+'){
                            q.push({new_x,new_y});
                            // mark as visited
                            maze[new_x][new_y]='+';
                        } 
                    }

                }
                noOfStep++;
            }
            return -1;
        }
};