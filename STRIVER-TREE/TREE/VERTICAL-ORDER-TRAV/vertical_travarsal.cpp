  VERTICAL ORDER TRAVARSAL

  leetcode [hard]

class Solution {
public:
     void verticalOrder(TreeNode* root, int level, int d, map<int, vector<pair<int, int>>>& mp) {
        if(!root)
            return;
        mp[d].push_back({level, root->val});
        verticalOrder(root->left, level+1, d-1, mp);
        verticalOrder(root->right, level+1, d+1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;
        verticalOrder(root, 0, 0, mp);
        vector<vector<int>> result;
        
        for(auto it:mp) {
            vector<pair<int, int>> temp = it.second;
            sort(temp.begin(), temp.end());
            vector<int> re;
            for(auto x:temp)
                re.push_back(x.second);
            result.push_back(re);
        }
        
        return result;
    }
};