class Solution {
public:
     void dfs(int row, int col, vector<vector<int>> &vis, 
    vector<vector<char>> &mat, int delrow[], int delcol[]) {
        vis[row][col] = 1; 
        int m = mat.size();
        int n = mat[0].size();
        
        // check for top, right, bottom, left 
        for(int i = 0;i<4;i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i]; 
            // check for valid coordinates and unvisited Os
            if(nrow >=0 && nrow <m && ncol >= 0 && ncol < n 
            && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, mat, delrow, delcol); 
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
       int m = board.size(), n = board[0].size();

        if (m == 1 || n == 1) return;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1}; 

        vector<vector < int>> visited(m, vector<int> (n, false));

       	// check int the first row ;

        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O' && !visited[0][i])
                dfs(0, i, visited,board,delrow,delcol);
        }

       	// check int the lastrow row ;
        for (int i = 0; i < n; i++)
        {
            if (board[m - 1][i] == 'O' && !visited[m-1][i])
                dfs(m - 1, i, visited, board,delrow,delcol);
        }

       	// check int the first col ;

        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O' && visited[i][0]==false)
                dfs(i, 0,visited, board, delrow,delcol);
        }

       	// check int the last col;

        for (int i = 0; i < m; i++)
        {
            if (board[i][n - 1] == 'O' && visited[i][n-1]==false)
                dfs(i, n - 1,  visited,board,delrow,delcol);
        }

       	// change the Os to X

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O' && visited[i][j] == 0)
                    board[i][j] = 'X';
            }
        }

        
    }
};