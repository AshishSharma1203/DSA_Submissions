class Solution
{
    public:

        bool check(vector<int> &dist, int speed, double hour)
        {

            double currtime = 0;

            for (int i = 0; i < dist.size(); i++)
            {

                if (i == dist.size() - 1)
                {
                    currtime += dist[i] / (1.0 *speed);
                }
                else
                {

                    double reqtime = ceil(dist[i] / (1.0 *speed));
                    currtime += reqtime;
                }
            }

            if (currtime <= hour)
                return true;
            return false;
        }

    int minSpeedOnTime(vector<int> &dist, double hour)
    {

        int n = dist.size();
       	// each train will require one hour min (inlcuding waiting time) 
        if (hour <= n - 1)
            return -1;

        int low = 1, high = 1e7;
        int ans = INT_MAX;
        while (low <= high)
        {

            int mid = low + (high - low) / 2;
           	// check if the curr value of speed is acceptable or not 
            if (check(dist, mid, hour))
            {
                ans = mid;
                high = mid - 1;
            }
            else
               	// move to right side 
                low = mid + 1;
        }

        return ans;
    }
};