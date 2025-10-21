515. Find Largest Value in Each Tree Row

BFS 

class Solution {  T.c O(N)
public:
    void BFS(TreeNode* root,vector<int>&result){
        if(!root) return ;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int maxelement=INT_MIN;
            while(n--){
                auto top=q.front();
                q.pop();

                maxelement=max(maxelement,top->val);
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            result.push_back(maxelement);
        }
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int>result;
        BFS(root,result);
        return result;
    }
};

 DFS  imp

 
