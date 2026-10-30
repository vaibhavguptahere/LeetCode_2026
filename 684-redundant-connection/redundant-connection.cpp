class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (x == parent[x]) {
            return x;
        }
        return find(parent[x], parent);
    }
    void Union(int x, int y, vector<int>& parent) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if (x_parent != y_parent) {
            parent[y_parent] = x_parent;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int pu = find(u, parent);
            int pv = find(v, parent);

            if (pu == pv) {
                return {u, v};
            }

            Union(u, v, parent);
        }
        return {};
    }
};