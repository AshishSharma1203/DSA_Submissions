class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      // approach 1: sort the array and then return nums[k-1];
        
        priority_queue<int>pq(nums.begin(),nums.end());
        int count=k-1;
        while(count--)
        {

            pq.pop();
        }
        return pq.top();
        
    }
};