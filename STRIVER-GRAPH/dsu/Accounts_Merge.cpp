721. Accounts Merge

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find_parent(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find_parent(parent[x]);
    }

    void unionSet(int x, int y) {
        int px = find_parent(x);
        int py = find_parent(y);
        if (px == py) return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[px] = py;
            rank[py]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        unordered_map<string, int> mailNode;  // email -> parent index

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mailNode.find(mail) == mailNode.end()) {
                    mailNode[mail] = i;
                } else {
                    unionSet(i, mailNode[mail]);
                }
            }
        }

        unordered_map<int, vector<string>> mergedMail;
        for (auto& it : mailNode) {
            string mail = it.first;
            int idx = it.second;
            int p = find_parent(idx);
            mergedMail[p].push_back(mail);
        }

        vector<vector<string>> ans;
        for (auto& it : mergedMail) {
            int idx = it.first;
            vector<string> emails = it.second;
            sort(emails.begin(), emails.end());
            vector<string> temp;
            temp.push_back(accounts[idx][0]);  // name
            temp.insert(temp.end(), emails.begin(), emails.end());
            ans.push_back(temp);
        }

        return ans;
    }
};
