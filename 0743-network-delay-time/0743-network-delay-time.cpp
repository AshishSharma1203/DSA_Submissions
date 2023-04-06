class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> graph(n);
    for (const auto& time : times) {
        int u = time[0] - 1, v = time[1] - 1, w = time[2];
        graph[u].emplace_back(v, w);
    }

    // initialize distance array and visited set
    vector<int> dist(n, numeric_limits<int>::max());
    dist[k-1] = 0;

    // Dijkstra's algorithm using priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, k-1);
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first, w = neighbor.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    // check if all nodes can receive the signal
    int maxDist = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] == numeric_limits<int>::max()) {
            return -1; // unreachable node
        }
        maxDist = max(maxDist, dist[i]);
    }
    return maxDist;
    }
};