1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // creating a 2D adjecency matrix 
        vector<vector<int>>matrix(n , vector<int>( n , 1e9));
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            matrix[u][v] = w;
            matrix[v][u] = w;
        }
        //making the diagonal element as 0
        for(int i = 0 ; i < n;i++) matrix[i][i] = 0;

        for(int via = 0 ;via < n ;via++){
            for(int i = 0;i < n; i++){
                for(int j = 0; j < n ; j++){
                    if(matrix[i][via] != 1e9 && matrix[via][j] != 1e9){
                        matrix[i][j] = min(matrix[i][j] , matrix[i][via] + matrix[via][j]);
                    }
                }
            }
        }
        int cityCount = 1e9;
        int cityName = -1; // actually not required for this question 
        // but can be asked as follow up question
        for(int city = 0 ;city < n ;city++){
            int cnt = 0;
            for(int adjCity = 0;adjCity < n ; adjCity ++){
                if(matrix[city][adjCity] <= distanceThreshold){
                    cnt ++;
                }
            }
            if( cnt <= cityCount){
                cityCount = cnt ;
                cityName = city ;
            }
        }
        return cityName;
    }
};