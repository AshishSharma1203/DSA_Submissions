class Solution
{
    public:
        bool repeatedSubstringPattern(string s)
        {

            int n = s.size();
            for (int j = 0; j < n; j++)
            {
                string s1 = s.substr(0, j + 1);
                int length = j + 1;
                // cout << s1 << endl;
                bool flag = true;
                if (j == n - 1)
                    return false;
                for (int k = j + 1; k < n; k = k + length)
                {

                    string s2 = s.substr(k, length);
                    // cout << s2 << endl;
                    {
                        if (s1 != s2)
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag)
                    return true;
            }
            return false;
        }
};