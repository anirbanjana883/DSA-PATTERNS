The Celebrity Problem

class Solution {
  public:
    // timw complexity - O(n^2 + n)
    // space complexity - O(2 * n)
    int celebrity(vector<vector<int> >& mat) {
        // celebraty - everyone know him but he dont know anyone
        int n = mat.size();
        vector<int>iKnow(n,0);
        vector<int>knowMe(n,0);
        
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < n ;j++){
                if(i == j) continue; // Skip diagonal
                if( mat[i][j] == 1){
                    knowMe[j]++;
                    iKnow[i]++;
                }
            }
        }
        for(int i = 0; i < n ; i++){
            if(knowMe[i] == n - 1 && iKnow[i] == 0){
                return i;
            } 
        }
        return -1;
    }
};

class Solution {
  public:
    // time o ( 2 * n)
    // space o ( 1 )
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        int top = 0;
        int down = n - 1;
        while( top < down ){
            if( mat[top][down] == 1){
                top ++;// top can not be celebraty
            }
            else if(mat[down][top] == 1){
                down --; // down can not be celebraty
            }else{
                top++;
                down--;
            }
        }
        if( top > down ){
            return -1 ; // no celebraty
        }
        // now top == down
        // verification
        for(int i = 0 ; i < n; i ++){
            if( i == top ) continue;
            if(mat[top][i] != 0 || mat[i][top] != 1) return -1;
        }
        return top ; // also can be return down 
    }
};