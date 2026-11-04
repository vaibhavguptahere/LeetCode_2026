class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x], parent);
    }
    void Union(int x, int y, vector<int>& parent) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if (x_parent != y_parent) {
            parent[x_parent] = y_parent;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n);
        unordered_map<string, int> emailToAccount;

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                // Process email
                if (emailToAccount.find(email) != emailToAccount.end()) {
                    Union(i, emailToAccount[email], parent);
                } else {
                    // First time seeing this email
                    emailToAccount[email] = i;
                }
            }
        }
        vector<vector<string>> merged(n);
        for (auto& it : emailToAccount) {
            string email = it.first;
            int accountIndex = it.second;

            int root = find(accountIndex, parent);
            merged[root].push_back(email);
        }
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (merged[i].empty())
                continue;

            sort(merged[i].begin(), merged[i].end());

            merged[i].insert(merged[i].begin(), accounts[i][0]);

            ans.push_back(merged[i]);
        }
        return ans;
    }
};