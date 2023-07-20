class Solution
{
    public:

        int numEnclaves(vector<vector < int>> &grid)
        {
            int count = 0;
            int m = grid.size(), n = grid[0].size();
           	// vector<vector < int>> ans(m, vector<int> (n, 0));

           	// push all the boundary 1's to queue and do bfs/dfs traversal and mark all the connected cells around it 
            queue<pair<int, int>> q;

            vector<vector < int>> visited(m, vector<int> (n, 0));

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                   	//First row, first col, last row, last col
                    if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
                    {
                        if (grid[i][j] == 1)
                        {
                            q.push({ i,
                                j });
                            visited[i][j] = 1;
                        }
                    }
                }
            }

           	// bfs(q,ans,grid,visited);
            int dx[] = { -1,
                0,
                1,
                0
            };
            int dy[] = { 0,
                1,
                0,
                -1
            };

            while (q.empty() == false)
            {

                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int row = i + dx[k];
                    int col = j + dy[k];

                    if (row >= 0 && row < m && col >= 0 && col < n && visited[row][col] == 0 && grid[row][col] == 1)
                    {
                        q.push({ row,
                            col });
                        visited[row][col] = 1;
                    }
                }
            }

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1 && visited[i][j] == 0)
                        count++;
                }
            }

            return count;
        }
};