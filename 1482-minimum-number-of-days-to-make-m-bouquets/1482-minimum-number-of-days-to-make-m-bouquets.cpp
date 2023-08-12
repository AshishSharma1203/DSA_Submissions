class Solution
{
    public:

        bool isPossible(vector<int> &arr, int mid, int m, int k)
        {

            int count = 0, b = 0;
            for (int i = 0; i < arr.size(); i++)
            {
                if (arr[i] <= mid)
                {
                    count++;
                    if (count == k)
                    {
                        b++;
                        count = 0;
                    }
                }
                else
                    count = 0;
            }
            // cout<<b;
            return b >= m;
        }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        long long int total=1LL *  m*k;
          if(total >n) 
            return -1;

        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }

       int  ans = -1;

        while (low <= high)
        {

            int mid = low + (high - low) / 2;
            // cout<<mid<<endl;
            if (isPossible(bloomDay, mid, m, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return ans;
    }
};