class Solution
{
    public:

       int isPowerOf5(string s) {
         if (s[0] == '0') return false;
         reverse(s.begin(), s.end());
         int n = 0;
         for (int i = 0; i < s.size(); i++) {
             if (s[i] == '1') n += pow(2, i);
         }
         for (int i = 0; i*i <= sqrt(n); i++) {
             if (pow(5, i) == n) return true;
         }
         return false;
     }
    int helper(string &s, int i, int j, vector<vector<int>> &dp) {
        if (dp[i][j] != -1) return dp[i][j];
        if (isPowerOf5(s.substr(i, j - i + 1))) return 1;
        if(i==j)
            return s[i]=='1'?1:1e9;
        int ans = 1e9;
        for (int k = i + 1; k <= j; k++) {
            if (s[k] == '1' and s[k - 1] == '1') {
                int a = helper(s, i, k - 1, dp);
                int b = helper(s, k, j, dp);
                ans = min(ans, a + b);
            }
        }
        return dp[i][j] = ans;
    }
    int minimumBeautifulSubstrings(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        int i = 0;
        int ans = helper(s, i, s.size() - 1, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};