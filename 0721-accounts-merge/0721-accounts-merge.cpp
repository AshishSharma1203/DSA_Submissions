class DisjointSet
{

    vector<int> parent, size;
    public:
        DisjointSet(int n)
        {

            parent.resize(n + 1);
            size.resize(n + 1);
            for (int i = 0; i <= n; i++)
            {
                parent[i] = i;
                size[i] = 1;
            }
        }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
    public:
        vector<vector < string>> accountsMerge(vector<vector < string>> &accounts)
        {

            unordered_map<string, int> mp;
            int n = accounts.size();
            DisjointSet ds(n);
           	// consider the names as nodes and then connect the emails
            for (int i = 0; i < n; i++)
            {
                for (int j = 1; j < accounts[i].size(); j++)
                {
                    string mail = accounts[i][j];
                    if (mp.find(mail) == mp.end())
                    {
                        mp[mail] = i;
                    }
                    else
                    {
                        ds.unionBySize(i, mp[mail]);
                    }
                }
            }
           	// now store all the emails with their node number 
            vector<vector < string>> mergemail(n);
            for (auto it: mp)
            {
                string mail = it.first;
                int node = ds.findUPar(it.second);
                mergemail[node].push_back(mail);
            }

            vector<vector < string>> ans;

            for (int i = 0; i < n; i++)
            {
               	// check if the node is not empty first 
                if (mergemail[i].size() == 0) continue;
                sort(mergemail[i].begin(), mergemail[i].end());
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                for (auto it: mergemail[i])
                {
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
            sort(ans.begin(), ans.end());
            return ans;
        }
};