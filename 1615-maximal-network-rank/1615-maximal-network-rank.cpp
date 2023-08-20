class Solution
{
    public:
        int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    vector<vector<int>> adj(n);

    for (auto it : roads) {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int curr = adj[i].size();

        for (int j = i + 1; j < n; j++) {
            int connected = count(adj[j].begin(), adj[j].end(), i);

            curr = adj[i].size() + adj[j].size() - connected;

            ans = max(ans, curr);
        }
    }

    return ans;
}

};