class Solution
{
    public:

        static bool compare(vector<int> &a, vector<int> &b)
        {
            return a[0] < b[0];
        }

    int findndexbyBS(int i, vector<vector < int>> &offers)
    {

        int low = i+1, high = offers.size()-1;
        int ans = offers.size();
        while (low <= high)
        {

            int mid = low + (high - low) / 2;

            if (offers[mid][0] > offers[i][1])
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }

    int findIndex(int i, vector<vector < int>> &offers)
    {

        for (int j = i + 1; j < offers.size(); j++)
        {
            if (offers[j][0] > offers[i][1])
                return j;
        }
        return offers.size();
    }

   	//     int solve(int i, int n, vector<vector < int>> &offers, vector<int> &dp)
   	//     {

   	//         if (i >= offers.size())
   	//             return 0;
   	//         if (dp[i] != -1)
   	//             return dp[i];

   	//         int way1 = 0 + solve(i + 1, n, offers,dp);
   	//         int index = findIndex(i, offers);
   	//         int way2 = offers[i][2] + solve(index, n, offers,dp);

   	//         return dp[i] = max(way1, way2);
   	//     }

    int maximizeTheProfit(int n, vector<vector < int>> &offers)
    {

        int m = offers.size();
        sort(offers.begin(), offers.end(), compare);
       	// vector<int> dp(m, -1);
       	// return solve(0, n, offers, dp);

        vector<int> dp(m + 1, 0);
        dp[m] = 0;
        for (int i = m - 1; i >= 0; i--)
        {

            int way1 = dp[i + 1] + 0;
            int index = findndexbyBS(i, offers);
            int way2 = offers[i][2] + dp[index];

            dp[i] = max(way1, way2);
        }

        return dp[0];
    }
};