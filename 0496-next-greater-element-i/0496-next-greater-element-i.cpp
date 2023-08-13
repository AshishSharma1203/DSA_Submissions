class Solution
{
    public:

       	// approach 1: use linear traversal 
       	//     {
       	//      int n = nums1.size(), m = nums2.size();
       	//      unordered_map<int, int> mp;
       	//             for (int i = 0; i < m; i++)
       	//             {

       	//                 for (int j = i + 1; j < m; j++)
       	//                 {

       	//                     if (nums2[j] > nums2[i])
       	//                     {
       	//                         mp.insert({ nums2[i],
       	//                             nums2[j] });
       	//                         break;
       	//                     }
       	//                 }
       	//             }

       	//            vector<int> ans;
       	//             for (int i = 0; i < n; i++)
       	//             {

       	//                 if (mp.find(nums1[i]) != mp.end())
       	//                 {
       	//                     ans.push_back(mp[nums1[i]]);
       	//                 }
       	//                 else
       	//                     ans.push_back(-1);
       	//             }

       	//             return ans;
       	//     }

        vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
        {
            int n = nums1.size(), m = nums2.size();
            unordered_map<int, int> mp;
           	// to store element and its greater element of nums2  array  

            stack<int> st;
           	// vector<int> arr(m);
            st.push(nums2[m - 1]);
           	// arr[m-1]=
            mp[nums2[m - 1]] = -1;

            for (int j = m - 2; j >= 0; j--)
            {
                while (!st.empty() && st.top() < nums2[j])
                {

                    st.pop();
                }

                if (st.empty())
                {
                    mp[nums2[j]] = -1;
                    st.push(nums2[j]);
                }
                else
                {

                    mp[nums2[j]] = st.top();
                    st.push(nums2[j]);
                }
            }
            vector<int> ans(n);
            for (int i = 0; i < nums1.size(); i++)
            {

                ans[i] = mp[nums1[i]];
            }
            return ans;
        }
};