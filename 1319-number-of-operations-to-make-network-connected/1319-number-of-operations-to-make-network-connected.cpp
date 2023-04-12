class DisjointSet
{

    public:
    vector<int> parent, size;
        DisjointSet(int n)
        {
            parent.resize(n + 1);
            size.resize(n + 1);

            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
                size[i] = 1;
            }
        }

    int findUparent(int u)
    {
        if (parent[u] == u) return u;

        int par = parent[u];
        int uparent = findUparent(par);
        return parent[u] = uparent;
    }

    void UnionBySize(int u, int v)
    {
        int par_u = findUparent(u), par_v = findUparent(v);
        if (par_u == par_v) return;

        if (size[par_u] > size[par_v])
        {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
        else
        {
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        }
    }
};

class Solution
{

    public:
        int makeConnected(int n, vector<vector < int>> &connections)
        {
            cout<<n<<" "<<connections.size()<<endl;

            // if (connections.size() < n - 1) return -1;

           	// use min spanning tree using kruskal's algo

            DisjointSet ds(n+1);
            int extraedges=0;

            for (int i = 0; i < connections.size(); i++)
            {
                int u = connections[i][0], v = connections[i][1];
                int par_u = ds.findUparent(u), par_v = ds.findUparent(v);

                if (par_u == par_v)
                {
                   
                    extraedges++;
                }
                else
                {
                    ds.UnionBySize(u, v);
                    
                }
            }

            int count = 0;

            for (int i = 0; i < n; i++)
            {
                if (ds.parent[i]==i)
                    count++;
            }
               int ans=count-1;
            if(extraedges>=count-1) return count-1;
            return -1;
        }
};