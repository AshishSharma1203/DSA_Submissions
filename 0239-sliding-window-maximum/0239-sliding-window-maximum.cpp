class Solution
{
    public:
        vector<int> maxSlidingWindow(vector<int> &nums, int k)
        {
           	// approach 1: use two nested loops 
            // approach 2 : using priority queue 
            vector<int> ans;
            priority_queue<pair<int, int>> pq;
            int n = nums.size();
            for (int i = 0; i < k; i++)
            {

                pq.push({ nums[i],
                    i });
            }
            ans.push_back(pq.top().first);

            for (int i = k; i < n; i++)
            {
                while (!pq.empty() && pq.top().second < i - k + 1)
                {
                    pq.pop();
                }
                pq.push({ nums[i],
                    i });
                ans.push_back(pq.top().first);
            }
            return ans;
        }
};