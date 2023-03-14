class Solution
{
    public:

//        void bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q, int& ans, int& fresh) {
//     int dx[] = {1, 0, -1, 0};
//     int dy[] = {0, 1, 0, -1};

//     int m = grid.size(), n = grid[0].size();

//     while (!q.empty() && fresh > 0) {
//         int size = q.size();

//         for (int i = 0; i < size; i++) {
//             auto curr = q.front();
//             q.pop();
//             int x = curr.first;
//             int y = curr.second;

//             for (int j = 0; j < 4; j++) {
//                 int row = x + dx[j];
//                 int col = y + dy[j];
//                 if (row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1) {
//                     grid[row][col] = 2;
//                     fresh--;
//                     q.push({row, col});
//                 }
//             }
//         }
//         ans++;
//     }
// }

    
        void bfs(vector<vector < int>> &grid, queue< pair<int, int>> q, int &ans,int &fresh)
        {
            int dx[] ={1, 0, -1, 0};
            int dy[] ={0, 1, 0, -1};

            int m = grid.size(), n = grid[0].size();

            while (q.empty() == false && fresh>0)
            {
                int size = q.size();
            
                for (int i = 0; i <size; i++)
                {
                    auto curr = q.front();
                    q.pop();
                    int x = curr.first;
                    int y = curr.second;

                    for (int j = 0; j < 4; j++)
                    {
                        int row=x+dx[j];
                        int col=y+dy[j];
                        if (row >= 0 && row< m && col >= 0 && col< n && grid[row][col] == 1)
                        {
                            grid[row][col] = 2;
                            fresh--;
                            q.push({ row,col});
                                
                        }
                    }
                }
                ans++;
            }
        }

    int orangesRotting(vector<vector < int>> &grid)
    {

        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        int fresh=0;

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(grid[i][j]==1) fresh++;
                if (grid[i][j] == 2)
                {
                    q.push({ i, j });
                       
                }
            }
        }

        bfs(grid, q, ans,fresh);
       
        
       return fresh==0?ans:-1;
    }
};