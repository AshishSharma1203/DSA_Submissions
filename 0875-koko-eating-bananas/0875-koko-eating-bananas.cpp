class Solution
{
    public:

        bool isPossible(int mid, vector<int> &piles, int h)
        {

            long long int hours_taken = 0;

            for (auto i: piles)
            {
                hours_taken += ceil( (double)i / (double)mid);
                
            }

            return hours_taken <= h;
        }

    int minEatingSpeed(vector<int> &piles, int h)
    {

       	//  approach 1: use linear search 

       	// approach 2 : use binary search 

        // int low = 1, high = accumulate(piles.begin(), piles.end(), 0);
           int low = 1, high = 1e9;

        int ans;
        while (low <= high)
        {

            int mid = low + (high - low) / 2;

            if (isPossible(mid, piles, h))
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