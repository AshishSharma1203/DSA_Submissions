class DisjointSet
{
public:
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int u)
    {
        if (u == parent[u])
            return u;

        return parent[u] = findUPar(parent[u]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u), ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;

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
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        DisjointSet s(n);

        int extraCables = 0, required = 0;

        for (int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0], v = connections[i][1];
            if (s.findUPar(u) == s.findUPar(v))
            {
                extraCables++;
            }
            else
            {
                s.unionBySize(u, v);
            }
        }

        for (int i = 0; i < n; i++) // Loop from 0 to n-1
        {
            if (s.parent[i] == i)
            {
                required++;
            }
        }
// as in one network all node will be connected
        return (required-1 > extraCables) ? -1 : required-1;
    }
};
