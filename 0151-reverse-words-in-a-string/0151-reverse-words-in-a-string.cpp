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

                    j++;
                }
               	// if there is trailing spaces only then 
                if (j == n) break;
               	// start another sustirng from i =j 
                i = j;
                while (j < n && s[j] != ' ')
                {
                    j++;
                }

                string temp = s.substr(i, j - i);
                reverse(temp.begin(), temp.end());

                ans += temp;
                ans += " ";
                j++;
                i = j;
            }

           	// remove the last added extra " " 
            ans.pop_back();

            return ans;
        }
};