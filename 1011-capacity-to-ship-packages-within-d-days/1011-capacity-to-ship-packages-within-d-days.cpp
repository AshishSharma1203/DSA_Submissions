class Solution
{
    public:
    
// find overall weight of all the packages 
    
        int solve(vector<int> weights)
        {
            int sum = 0;
            for (int i = 0; i < weights.size(); i++)
                sum += weights[i];

            return sum;
        }

    int check(vector<int> weights, int mid, int days)
    {
        int life = 0, currwt = 0;

        for (int i = 0; i < weights.size(); i++)
        {
            if (weights[i] > mid) return -1;
            if (currwt + weights[i] > mid)
            {
                life++;
                currwt = weights[i];
            }
            else
            {
                currwt += weights[i];
            }
        }
        life++;
        if (life > days) return -1;
        return life;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {

        int n = weights.size(), ans = INT_MAX;

        int sum = solve(weights);	// find the overall sum of all the  packages.

       	// soo  min wt= lowest weights of available package and max wt. = overall sum of all packages .ie. sum 

        int low = weights[0], high = sum;

        // apply binary search here
        
        while (low <= high)
        {
            int mid = (low + high) / 2;	// mid is current min capacity of ship 

            int curr = check(weights, mid, days);	// check the days required to ship with this particular value               of ship capacity 

            if (curr != -1)
            {
               	// it means this is accepted value for min. value of ship

                ans = min(ans, mid);	// this is our possible answer 
                high = mid - 1;	// go to left side to check if any optimum min . vlaue exists or not  
            }
            else
            {
               	// it means it is not possible to carry all packages in given days with curr min capacity of ship
                low = mid + 1;
            }
        }

        return ans;
    }
};