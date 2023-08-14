class Solution
{
    public:
        int findKthLargest(vector<int> &nums, int k)
        {
           	// approach 1: sort the array and then return nums[k-1];
           	// using max heap  TC: klogn
           	//         priority_queue < int>pq(nums.begin(),nums.end());
           	//         int count=k-1;
           	//         while(count--)
           	//         {

           	//             pq.pop();
           	//         }
           	//         return pq.top();

           	// using min heap TC : nlogk
            priority_queue<int, vector < int>, greater < int>> pq;

            for (int i: nums)
            {

                pq.push(i);
                if (pq.size() > k)
                    pq.pop();
            }

            return pq.top();
        }
};