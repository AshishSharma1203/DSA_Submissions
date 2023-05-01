class Solution
{
    public:

       	// recursive approaach 

       	//     int solve(int i,int j, int m,int n, vector<vector < int>> &obstacleGrid)
       	//     {
       	//         if(i>=m || j>=n)
       	//             return 0;
       	//         if(obstacleGrid[i][j]==1)
       	//             return 0;
       	//         if(i==m-1 && j==n-1)
       	//             return 1;

       	//         int down = solve(i,j+1,m,n,obstacleGrid);
       	//         int right =solve(i+1,j,m,n, obstacleGrid);

       	//         return down+ right;    

       	//     }

       	// memoization approach 

        int solve(int i, int j, int m, int n, vector<vector < int>> &grid, vector< vector< int>> &dp)
        {

            if (i >= m || j >= n)
                return 0;
            if (grid[i][j] == 1)
                return 0;
            if (i == m - 1 && j == n - 1)
                return 1;

            if (dp[i][j] != -1)
                return dp[i][j];

            int down = solve(i, j + 1, m, n, grid, dp);
            int right = solve(i + 1, j, m, n, grid, dp);

            return dp[i][j] = down + right;
        }

    int uniquePathsWithObstacles(vector<vector < int>> &obstacleGrid)
    {

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

       	//         vector<vector < int>> dp(m,vector<int> (n,-1));

       	//         return solve(0,0,m,n,obstacleGrid,dp);

       	// tabulation approach 

        vector<vector < int>> dp(m, vector<int> (n, 0));

       	// base case: dp[0][0] = 1 if there is no obstacle in the starting cell
        if (obstacleGrid[0][0] == 0)
        {
            dp[0][0] = 1;
        }

       	// base case: dp[i][0] = 1 if there is  obstacle in the first column, and all cells below it are unreachable
        for (int i = 1; i < m; i++)
        {
            if (obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1)
            {
                dp[i][0] = 1;
            }
        }

       	// base case: dp[0][j] = 1 if there is obstacle in the first row, and all cells to the right of it are unreachable
        for (int j = 1; j < n; j++)
        {
            if (obstacleGrid[0][j] == 0 && dp[0][j - 1] == 1)
            {
                dp[0][j] = 1;
            }
        }

       	// fill the rest of the dp array
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};