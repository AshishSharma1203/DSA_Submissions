class Solution
{
    public:

       	// brute force 
       	// int trap(vector<int> &height) 
       	// {
       	//       int ans = 0;
       	//             int n = height.size();
       	//             for (int i = 1; i < n - 1; i++)
       	//             {

       	//                	// find the left max 
       	//                 int lmax = 0, rmax = 0;
       	//                 for (int j = 0; j <= i - 1; j++)
       	//                 {

       	//                     lmax = max(lmax, height[j]);
       	//                 }
       	//                	// find the right max
       	//                 for (int k = i + 1; k < n; k++)
       	//                 {
       	//                     rmax = max(rmax, height[k]);
       	//                 }
       	//                	// curr water trap capacity 
       	//                 int curr_trap = min(lmax, rmax);
       	//                	// check currheight is smaller than curr_trap or not 
       	//                 if (curr_trap > height[i])
       	//                 {
       	//                     ans += curr_trap - height[i];
       	//                 }
       	//             }

       	//             return ans;
       	// }

        int trap(vector<int> &height)
        {
           	// approach 2: use precomputation to find lmax and right max 
            int n = height.size();
           	// int lmax[n], rmax[n];
            vector<int> lmax(n, 0), rmax(n, 0);
            lmax[0] = height[0];
            for (int i = 1; i < n; i++)
            {
                lmax[i] = max(height[i], lmax[i - 1]);
            }

            rmax[n - 1] = height[n - 1];
            for (int j = n - 2; j >= 0; j--)
            {
                rmax[j] = max(rmax[j + 1], height[j]);
            }

            int ans = 0;

            for (int i = 1; i < n - 1; i++)
            {
                int curr_ans = min(rmax[i], lmax[i]);
                if (curr_ans > height[i])
                    ans += curr_ans - height[i];
            }
            return ans;
        }
};