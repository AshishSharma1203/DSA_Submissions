class Solution
{
    public:

        int largestRectangleArea(vector<int> &heights)
        {

           	// use concept of max rectangle area 
            int n = heights.size(), ans = INT_MIN;
            stack<int> st;
            vector<int> lmin(n), rmin(n);

            st.push(0);
            lmin[0] = 0;

            for (int i = 1; i < n; i++)
            {

                int currheight = heights[i];

                while (st.empty() == false && heights[st.top()] >= currheight)
                    st.pop();

                lmin[i] = (st.empty() == true) ? 0 : st.top() + 1;
                st.push(i);
            }
            
            
            
            while (!st.empty())
                st.pop();
            rmin[n - 1] = n - 1;
            st.push(n - 1);

            for (int i = n - 2; i >= 0; i--)
            {

                int currheight = heights[i];

                while (st.empty() == false && heights[st.top()] >= currheight)
                    st.pop();

                rmin[i] = (st.empty() == true) ? n - 1 : st.top() - 1;
                st.push(i);
            }

            for (int i = 0; i < n; i++)
            {
                int currarea =( rmin[i] - lmin[i] + 1)*heights[i];
                ans = max(ans, currarea);
            }
            return ans;
        }

    int maximalRectangle(vector<vector < char>> &matrix)
    {

        int m = matrix.size(), n = matrix[0].size();

        vector<int> histogram(n, 0);
        int ans = INT_MIN;
        for (int i = 0; i < m; i++)
        {
           	// make the histogram of each level 

            for (int j = 0; j < n; j++)
            {

                if (matrix[i][j] == '0')
                    histogram[j] = 0;
                else
                    histogram[j] += 1;
            }

            int currarea = largestRectangleArea(histogram);
            ans = max(ans, currarea);
        }
        return ans;
    }
};