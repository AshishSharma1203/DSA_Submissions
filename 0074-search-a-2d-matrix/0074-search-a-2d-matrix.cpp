class Solution
{
    public:
        bool searchMatrix(vector<vector < int>> &matrix, int target)
        {

           	// approach 1  use normal search by traversing 

           	// optimal approach 

            int m = matrix.size(), n = matrix[0].size();

            int i = 0, j = n - 1;
            bool ans = false;
            while (i < m && j >= 0)
            {
               	// if current cell= target return 
                if (matrix[i][j] == target)
                    return true;
               	// if current cell value is greater than target move left 
                if (target < matrix[i][j])
                {
                    j--;
                }
                else
                   	// if current cell value is less than target then move down
                    i++;
            }
            return false;
        }
};