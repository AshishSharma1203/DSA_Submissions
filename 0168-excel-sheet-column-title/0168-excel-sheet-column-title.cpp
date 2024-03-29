class Solution
{
    public:
        string convertToTitle(int columnNumber)
        {

            string ans = "";

            while (columnNumber > 0)
            {
                columnNumber--;
                char ch = (columnNumber % 26)+ 'A'; 
                ans.push_back(ch);
                columnNumber = columnNumber / 26;
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
};