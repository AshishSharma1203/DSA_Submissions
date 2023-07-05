class Solution
{
    public:
        vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
        {
            int n = nums1.size(), m = nums2.size();
            unordered_map<int, int> mp;
            for (int i = 0; i < m; i++)
            {

                for (int j = i + 1; j < m; j++)
                {

                    if (nums2[j] > nums2[i])
                    {
                        mp.insert({ nums2[i],
                            nums2[j] });
                        break;
                    }
                }
            }

           vector<int> ans;
            for (int i = 0; i < n; i++)
            {

                if (mp.find(nums1[i]) != mp.end())
                {
                    ans.push_back(mp[nums1[i]]);
                }
                else
                    ans.push_back(-1);
            }

            return ans;
        }
};