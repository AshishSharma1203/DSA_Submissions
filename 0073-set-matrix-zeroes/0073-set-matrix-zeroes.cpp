class Solution
{
    public:
        void setZeroes(vector<vector < int>> &matrix)
        {

            int m = matrix.size(), n = matrix[0].size();

           	// we cant update the matrix while traversing cause it will also set other cell to zero, which will further behaves as cell having zero value but previously it can have non zero value 
            vector<int> rowcheck(m, 0), colcheck(n, 0);

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][j] == 0)
                    {
                        rowcheck[i] = 1;
                        colcheck[j] = 1;
                    }
                }
            }

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {

                    if (rowcheck[i] == 1 || colcheck[j] == 1)
                        matrix[i][j] = 0;
                }
            }
            return;
        }
};