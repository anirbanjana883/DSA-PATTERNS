class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        // firts pushing the root node
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int>v;
            for(int i=0;i<s;i++){
                TreeNode *node=q.front();
                q.pop();
                // pushing the left child into the queue
                if(node->left!=NULL)q.push(node->left);
                // pushing the right child into the queue
                if(node->right!=NULL)q.push(node->right);
                // them pusing the node val into the result
                v.push_back(node->val);
            }
            ans.push_back(v);
        }
        return ans;
    }
};

note one thing there is two type of BFS present 

while(){  this when we have to  all lavel of node in same lavel simultaniously
    int n=q.size(); for example revese all node of a lavel 
    while(n--){

    }
}

and this one \

while(){  this is for normal print the lavel travarsal etc;
    temp=q.front();
    q.pop();
}