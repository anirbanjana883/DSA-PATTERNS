2115. Find All Possible Recipes from Given Supplies

approach 1:

class Solution {
    public:
        // time complexity o(n^2 * m)
        // space complexity o(n + size of supply)
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            int n=recipes.size();
            vector<string>result;
    
            unordered_set<string>st(begin(supplies),end(supplies));
            vector<bool>cooked(n,false);
    
            int count=n;
            while(count--){
                for(int j=0;j<n;j++){
                    if(cooked[j]){
                        continue; // that means the receipee is cooked
                    }
    
                    bool if_possible_to_make=true;
                    for(int k=0;k<ingredients[j].size();k++){
                        if(!st.count(ingredients[j][k])){
                            if_possible_to_make=false;
                            break;
                        }
                    }
    
                    // if any  receipe is possible to make 
                    // then it may required to make another receipee
    
                    if(if_possible_to_make){
                        st.insert(recipes[j]);
                        result.push_back(recipes[j]);
                        cooked[j]=true;
                    }
                }
            }
            return result;
        }
};

approach 2:


notice one thing that sandwitch can only form after 
processing of bread; 
isn't' it remind of "topological sort" ?????? >>