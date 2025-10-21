1110. Delete Nodes And Return Forest


class Solution {
public:
    TreeNode*delete_node(TreeNode* root,unordered_set<int>&st,vector<TreeNode*>&result){
        if(!root){
            return NULL;
        }
        // reach at the end first
        root->left=delete_node(root->left,st,result);
        root->right=delete_node(root->right,st,result);
        // check if the node has to be deleted or not
        if(st.find(root->val)!=st.end()){
            // first put the left and right child into the result
            if(root->left) result.push_back(root->left);
            if(root->right) result.push_back(root->right);
            // after pushing the child return null
            return NULL;
        }else{
            // means we dont have toi delete the node 
            return root;
        }

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // better approach is to delete from down to up [dfs]
        vector<TreeNode*>result;
        // to avoid travarsal in to_delete vector 
        unordered_set<int>st(to_delete.begin(),to_delete.end());
        // function to delete node
        delete_node(root,st,result);
        // see we are skipping the case of root node 
        // if we dont have to delete the root node then 
        // we have to ush it into theresult
        if(st.find(root->val)==st.end()){
            result.push_back(root);
        } 
        return result;
    }
};