class Solution
{
    public:
        vector<int> findClosestElements(vector<int> &arr, int k, int x)
        {

           	// vector<int> ans;
            queue<int> q;
            int n = arr.size();
           	// unordered_set
            for (int i = 0; i < k; i++)
            {
                q.push(arr[i]);
            }

            int left = 0, right = k;

            while (right < n)
            {

                int d1 = abs(q.front() - x);
                int d2 = abs(arr[right] - x);

                if (d2 < d1)
                {
                    q.pop();
                    q.push(arr[right]);
                }
                right++;
            }

            vector<int> ans;
            while (q.empty() == false)
            {
                ans.push_back(q.front());
                q.pop();
            }

            return ans;
        }
};