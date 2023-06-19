class Solution
{
    public:
        vector<int> majorityElement(vector<int> &nums)
        {
           	// approach 1 : use two for loops and count variable  
           	// approach 2: use map data structure 

            int ans1 = INT_MAX, ans2 = INT_MAX;
            int count1 = 0, count2 = 0;
            int n= nums.size();
            for (int i = 0; i < n; i++)
            {

                if (count1==0 && nums[i] != ans2)
                {
                    ans1 = nums[i];
                    count1++;
                }
                else
                if (count2==0 && nums[i] != ans1)
                {

                    ans2 = nums[i];
                    count2++;
                }
                else if (nums[i] == ans1)
                    count1++;
                else if (nums[i] == ans2)
                    count2++;
                else
                {

                    count1--;
                    count2--;
                }
            }
            
            int required= (int)(n/3)+1;
             count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == ans1) count1++;
        if (nums[i] == ans2) count2++;
    }
            vector<int> ans;
            if(count1>=required) ans.push_back(ans1);
             if(count2>=required) ans.push_back(ans2);
            return ans;
        }
};