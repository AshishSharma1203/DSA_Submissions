class Solution
{
    public:
        vector<vector < int>> merge(vector<vector < int>> &intervals)
        {

            int n = intervals.size();
            vector<vector < int>> ans;
            sort(intervals.begin(), intervals.end());

            ans.push_back(intervals[0]);

            for (int i = 1; i < n; i++)
            {

                int curr_size = ans.size();
                int prev_start = ans[curr_size - 1][0];
                int prev_end = ans[curr_size - 1][1];
                int curr_start = intervals[i][0];
                int curr_end = intervals[i][1];

               	// check if curr_start is less than last inteval's end time  
                if (curr_start <= prev_end)
                {

                    ans[curr_size - 1][1] = max(curr_end, prev_end);
                }
                else
                {
                    ans.push_back(intervals[i]);
                }
            }

            return ans;
        }
};