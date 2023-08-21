class Solution
{
    public:

      bool bfs(vector<vector<int>> &heights, int effort) {
    int m = heights.size(), n = heights[0].size();
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    vector<vector<int>> visited(m, vector<int>(n, false));

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int row = curr.first, col = curr.second;
        if (row == m - 1 && col == n - 1)
            return true;

        for (int k = 0; k < 4; k++) {
            int x = row + dx[k], y = col + dy[k];

            if (x >= 0 && x < m && y >= 0 && y < n && visited[x][y] == false) {
                if (abs(heights[x][y] - heights[row][col]) <= effort) {
                    q.push({x, y});
                    visited[x][y] = true;
                }
            }
        }
    }
    return false;
}

int minimumEffortPath(vector<vector<int>> &heights) {
    int low = 0, high = 1e6, ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (bfs(heights, mid)) {
            ans = mid;
            high = mid - 1;  // Fix this line: change "mid = high - 1" to "high = mid - 1"
        } else
            low = mid + 1;
    }

    return ans;
}

};