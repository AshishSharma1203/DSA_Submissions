class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {

            int ans = 0;
            int n = s.size();
            if(n==0) return 0;
            if(n==1) return 1;
            for (int i = 0; i < n; i++)
            {

                unordered_set<char> st;
               	// st.insert(s[i]);
                int j = i;
                while (j < n)
                {

                    if (st.find(s[j]) != st.end())
                    {
                        j=i-1;
                        break;
                    }
                    else
                    {
                        st.insert(s[j]);
                            ans = max(ans, j - i+1 );
                        j++;
                    }
                }
            }

            return ans;
        }
};