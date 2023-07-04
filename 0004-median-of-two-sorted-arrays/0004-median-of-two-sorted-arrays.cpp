class Solution
{
    public:
        double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
        {

           	// approach 1: use temp array and twoo pointers to fill the array in sorted order, then use the                  formula 
           	// of median and return the median 

           	// approach:2 use binary search 

            int m = nums1.size(), n = nums2.size();
            if (m > n)
                return findMedianSortedArrays(nums2, nums1);

            int low = 0, high = m;
            int medpos = (m + n + 1) / 2;
            while (low <= high)
            {

                int mid = (low + high) / 2;
                int cut1 = mid;
                int cut2 = medpos - cut1;

                int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
                int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
                int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];
                int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

                if (l1 <= r2 && r1 >= l2)
                {

                    if ((m + n) % 2 != 0)
                        return max(l1, l2);
                    else
                        return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else if (l1 > r2)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            return 0.0;
        }
};