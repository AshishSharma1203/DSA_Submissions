class Solution
{
    public:

        bool compare(string &s1, string &s2)
        {
            if (abs(s1.size() - s2.size() != 1)) return false;

            int first = 0;
            int second = 0;

            while (first < s1.size())
            {
                if (second < s2.size() && s1[first] == s2[second])
                {
                    first++;
                    second++;
                }
                else first++;
            }
            if (first == s1.size() && second == s2.size()) return true;
            else return false;
        }

    static bool myfun(const string s1, const string s2)
    {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string> &words)
    {

        int n = words.size();
        sort(words.begin(), words.end(), myfun);

       	// use the concept of LIS

        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int prev_ind = 0; prev_ind <= i - 1; prev_ind++)
            {

                if (compare(words[i], words[prev_ind]))
                {

                    if (1 + dp[prev_ind] > dp[i])
                    {
                        dp[i] = 1 + dp[prev_ind];
                    }
                }
            }
        }

        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};