class Solution
{
    public:

       void dfs(int i, vector<int> adj[], vector<int>& nodes, vector<int>& visited) {
    visited[i] = true;
    nodes.push_back(i);

    for (auto v : adj[i]) {
        if (visited[v] == false)
            dfs(v, adj, nodes, visited);
    }
}

bool check(vector<int>& nodes, vector<int> adj[]) {
    for (int i = 0; i < nodes.size(); i++) {
        int u = nodes[i];
        for (int j = i + 1; j < nodes.size(); j++) {
            int v = nodes[j];
            bool connected = false;
            for (int k = 0; k < adj[u].size(); k++) {
                if (adj[u][k] == v) {
                    connected = true;
                    break;
                }
            }
            if (!connected) {
                return false;
            }
        }
    }
    return true;
}

int countCompleteComponents(int n, vector<vector<int>>& edges) {
    int ans = 0;
    vector<int> adj[n];

    // make the adjacency list of the graph
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph, so add edges in both directions
    }

    vector<int> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            vector<int> nodes;
            dfs(i, adj, nodes, visited);
            if (check(nodes, adj))
                ans++;
        }
    }

    return ans;
}

};