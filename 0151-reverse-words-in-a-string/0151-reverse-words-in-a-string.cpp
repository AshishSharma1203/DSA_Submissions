class Solution
{
    public:
        string reverseWords(string s)
        {
            reverse(s.begin(), s.end());
            string ans = "";
            int n = s.size();
            int i = 0, j = 0;
            while (j < n)
            {
               	// remove trailing spaces 
                while (j < n && s[j] == ' ')
                {
                   	// i++;
                    j++;
                }
                if (j == n) break;
                i = j;
                while (j < n && s[j] != ' ')
                {
                    j++;
                }
               	// reverse(s.begin() + i, s.begin() + j);
                string temp = s.substr(i, j - i);
                reverse(temp.begin(), temp.end());

                ans += temp;
                ans += " ";
                j++;
                i = j;
            }

           	// reverse(s.begin(),s.end());
            ans.pop_back();
           	// reverse(ans.begin(), ans.end());
            return ans;
        }
};