class Solution
{
    public:
        bool solve(int i, int j, string s1, string s2, string s3, vector<vector < int>> &memo)
        {
            if (i == s1.size() && j == s2.size())
            {
                return true;
            }

            if (memo[i][j] != -1)
            {
                return memo[i][j] == 1;
            }

            bool way1 = false, way2 = false;

            if (i < s1.size() && s1[i] == s3[i + j])
            {
                way1 = solve(i + 1, j, s1, s2, s3, memo);
            }

            if (j < s2.size() && s2[j] == s3[i + j])
            {
                way2 = solve(i, j + 1, s1, s2, s3, memo);
            }

            memo[i][j] = (way1 || way2) ? 1 : 0;
            return way1 || way2;
        }

    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.size();
        int m = s2.size();
        int t = s3.size();

        if (n + m != t)
        {
            return false;
        }

        vector<vector < int>> memo(n + 1, vector<int> (m + 1, -1));

        return solve(0, 0, s1, s2, s3, memo);
    }
};