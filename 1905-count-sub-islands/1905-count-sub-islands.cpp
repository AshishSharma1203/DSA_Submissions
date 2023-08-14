class Solution
{
    public:

        void dfs(int i, int j, int m, int n, vector<vector < int>> &grid2, vector< vector< bool>> &visited,vector<pair<int, int>> &coordinates)
        {
            visited[i][j] = true;
            coordinates.push_back({i,j});

            int dx[4] = { -1,
                0,
                1,
                0
            };
            int dy[4] = { 0,
                -1,
                0,
                1
            };

            for (int k = 0; k < 4; k++)
            {
                int row = i + dx[k], col = j + dy[k];
                if (row >= 0 && row < m && col >= 0 && col < n && grid2[row][col] == 1 && !visited[row][col])
                {
                    dfs(row, col, m, n, grid2, visited,coordinates);
                }
            }
        }

    bool check(vector<vector < int>> &grid1, vector< pair<int, int>> &coordinates)
    {
        for (auto i: coordinates)
        {
            int a = i.first, b = i.second;
            if (grid1[a][b] == 0)
            {
                return false;
            }
        }
        return true;
    }

    int countSubIslands(vector<vector < int>> &grid1, vector< vector< int>> &grid2)
    {
        int m = grid2.size(), n = grid2[0].size();
        vector<vector < bool>> visited(m, vector<bool> (n, false));

        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid2[i][j] == 1 && !visited[i][j])
                {
                    vector<pair<int, int>> coordinates;
                    dfs(i, j, m, n, grid2, visited,coordinates);
                    if (check(grid1, coordinates))
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};