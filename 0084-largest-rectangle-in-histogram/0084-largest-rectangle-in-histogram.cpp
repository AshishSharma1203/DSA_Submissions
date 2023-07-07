class Solution
{
    public:
        int largestRectangleArea(vector<int> &heights)
        {
            int n = heights.size();
            vector<int> lmin(n), rmin(n);
            stack<int> st;
            st.push(0);
            lmin[0] = 0;

           	// form the next smaller elements of left 
            for (int i = 1; i < n; i++)
            {

                int curr = heights[i];
                while (st.empty() == false && heights[st.top()] >= curr)
                {
                    st.pop();
                }
                if (st.empty())
                    lmin[i] = 0;
                else
                {

                    lmin[i] = st.top() + 1;
                }
                st.push(i);
            }

           	// form the next smaller elements of right 

            while (!st.empty())
                st.pop();

            for (int i = n - 1; i >= 0; i--)
            {

                int curr = heights[i];

                while (st.empty() == false && heights[st.top()] >= heights[i])
                {
                    st.pop();
                }
                if (st.empty())
                    rmin[i] = n - 1;
                else
                {

                    rmin[i] = st.top() - 1;
                }
                st.push(i);
            }

            int ans = 0;
            for (int i = 0; i < n; i++)
            {

                int currans = (rmin[i] - lmin[i] + 1) *heights[i];
                ans = max(ans, currans);
            }
            return ans;
        }
};