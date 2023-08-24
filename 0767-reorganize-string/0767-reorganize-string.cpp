class Solution
{
    public:

        string reorganizeString(string s)
        {
            vector<int> charCount(26, 0);

            for (int i = 0; i < s.size(); i++)
            {
                charCount[s[i] - 'a']++;
            }

            priority_queue<pair<int, char>> pq;

            for (int i = 0; i < 26; i++)	
            {
                if (charCount[i] > 0)
                {
                    pq.push({ charCount[i],
                        (char) i + 'a' });
                }
            }

            string ans = "";

            while (pq.empty() == false)
            {
                auto curr = pq.top();
                pq.pop();

                if (ans == "")
                {
                    ans.push_back(curr.second);
                    curr.first--;
                    if (curr.first > 0)	
                    {
                        pq.push({ curr.first,
                            curr.second });	
                    }
                }
                else
                {
                    if (ans.back() != curr.second)
                    {
                        ans.push_back(curr.second);
                        curr.first--;
                        if (curr.first > 0)	
                        {
                            pq.push({ curr.first,
                                curr.second });	
                        }
                    }
                    else
                    {
                        if (pq.empty())	// Add this condition to handle corner cases 
                        {
                            return "";
                        }

                        auto curr_next = pq.top();
                        pq.pop();
                        pq.push(curr);
                        ans.push_back(curr_next.second);
                        curr_next.first--;
                        if (curr_next.first > 0)	
                        {
                            pq.push({ curr_next.first,
                                curr_next.second });	
                        }
                    }
                }
            }

            return ans;
        }
};