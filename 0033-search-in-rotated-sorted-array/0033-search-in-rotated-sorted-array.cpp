class Solution
{
    public:
        int search(vector<int> &nums, int target)
        {

            int n = nums.size();
            int low = 0;
            int high = n - 1;

            while (low <= high)
            {

                int mid = low + (high - low) / 2;

                if (nums[mid] == target)
                    return mid;

                if (nums[mid] >= nums[low])	// this show left half is sorted 
                {
                   	// check if the element lies in the sorted part  
                    if (target < nums[mid] && target >= nums[low])
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
                else if (nums[mid] < nums[high])	// this show left half is sorted
                {
                   	// check if the element lies in right sorted part  
                    if (target <= nums[high] && target > nums[mid])
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }
            }

            return -1;
        }
};