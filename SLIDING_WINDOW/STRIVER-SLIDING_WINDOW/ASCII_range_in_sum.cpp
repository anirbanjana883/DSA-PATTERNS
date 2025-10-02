ASCII Range Sum

class Solution {
  public:
    // time o ( n )
    // space o( 1 )
    vector<int> asciirange(string& s) {
        // code here
        int n = s.size();
        vector<int>focc(26 , -1) , locc(26 , -1);
        
        for(int i = 0 ; i < n ; i++){
            if(focc[s[i] - 'a'] == -1){
                focc[s[i] - 'a'] =i;
            }
        }
        
        for(int i = n - 1 ; i >= 0 ; i--){
            if(locc[s[i] - 'a'] == -1){
                locc[s[i] - 'a'] =i;
            }
        }
        
        int sum = 0;
        for(int i = 0 ; i < n; i++){
            sum += int(s[i]);
            
            if(focc[s[i] - 'a'] == i){
                focc[s[i] - 'a'] = ( -1 * sum);
            }else if(locc[s[i] - 'a'] == i){
                locc[s[i] - 'a'] = (sum - int(s[i]));
            }
        }
        
        vector<int>ans;
        for(int i = 0 ; i < 26 ;i++){
            int val = focc[i] + locc[i];
            if( val > 0) ans.push_back(val);
        }
        return ans;
    }
};