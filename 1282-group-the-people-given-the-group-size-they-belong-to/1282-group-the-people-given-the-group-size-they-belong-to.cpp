class Solution
{
    public:
        vector<vector < int>> groupThePeople(vector<int> &groupSizes)
        {

           	            vector<vector < int>> ans;
           	            int n = groupSizes.size();
           	            vector<pair<int, int>> groups;

           	            for (int i = 0; i < n; i++)
           	            {
           	                groups.push_back({ groupSizes[i],
           	                    i });
           	            }
           	            sort(groups.begin(), groups.end());

           	            int i = 0;
           	            while (i < n)
           	            {
           	                int count = groups[i].first;
           	                vector<int> temp;
           	                int j;
           	                for (j = i; j < i+count; j++)
           	                {
           	                    temp.push_back(groups[j].second);
           	                   
           	                }
           	                ans.push_back(temp);
           	                i = j;
           	            }

           	            return ans;

//             int n = groupSizes.size();

//             vector<vector < int>> ans;
//             map<int, vector < int>> mp;
//             for (int i = 0; i < n; i++)
//             {

//                 mp[groupSizes[i]].push_back(i);
//             }

//             for (auto i: mp)
//             {

//                 int count = i.first;
//                 vector<int> temp = i.second;

//                 int counter = 0;
//                	// int j = temp.size();
//                 vector<int> groups;

//                 for (int k = 0; k < temp.size(); k++)
//                 {

//                     groups.push_back(temp[k]);
//                     counter++;

//                     if (counter == count)
//                     {
//                         ans.push_back(groups);
//                         counter = 0;
//                         groups.clear();
//                     }
//                 }
//             }

//             return ans;
        }
};