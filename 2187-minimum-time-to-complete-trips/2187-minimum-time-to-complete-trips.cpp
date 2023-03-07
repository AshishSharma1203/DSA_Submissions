class Solution
{
    public:

       	// function to find min value in the array
        void find(vector<int> &time, long long int &low)
        {

            for (int i = 0; i < time.size(); i++)
            {

                if (time[i] < low) low = time[i];
            }
        }

    bool check(vector<int> &time, long long int mid, int totalTrips)
    {

        long long int count = 0;

        for (int i = 0; i < time.size(); i++)
        {
            count += mid / time[i];
        }
        if (count >= totalTrips) return true;

        return false;
    }

    long long minimumTime(vector<int> &time, int totalTrips)
    {

        long long int low = LLONG_MAX;

        find(time, low);
        long long int high = totalTrips * low;
        long long int ans = totalTrips * low;

       	// apply binary search algorithm 

        while (low <= high)
        {
            long long int mid = low + (high - low) / 2;
           	// check whether the curr value i.e. mid is accepted or not 

            bool flag = check(time, mid, totalTrips);

            if (flag == true)
            {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};