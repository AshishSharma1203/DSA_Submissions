class Solution
{
    public:

        void solve(int i, int n, int k, int count, vector<int> temp, vector<vector< int>> &ans)
        {
            if (count > k)
                return;
            if (count == k)
            {
                ans.push_back(temp);
                return;
            }

            for (int j = i + 1; j <= n; j++)
            {
                temp.push_back(j);
                solve(j, n, k, count + 1, temp, ans);
               	// backtrack : pop out the last inserted element to find new combination  
                temp.pop_back();
            }
        }

    vector<vector < int>> combine(int n, int k)
    {

        vector<int> temp;
        vector<vector < int>> ans;
       	// if (size of combination is greater than value of n then its not possible too generate the combination)
        if (k > n)
            return ans;

       	// loop from 1 to n and generate all possible combination 
        for (int i = 1; i <= n; i++)
        {
            temp.push_back(i);
            solve(i, n, k, 1, temp, ans);
            temp.pop_back();
        }

        return ans;
    }
};