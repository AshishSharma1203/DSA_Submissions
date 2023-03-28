//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
      
        
        // create a graph tht represents the order ie.e which alphabet comes first by making edge from 
        // lexical first ( as per alien dict.) to other alphabet
        vector<int> graph[K];
        
        // present is to store char in int form so that nodes can be numbered 
        // bool present[26]={0};
        int indegree[26]={0};
        
       for(int i=0;i<N-1;i++)
       {
           string s1=dict[i],s2=dict[i+1];
            int n=s1.size(),m=s2.size();
            int len = min(n, m);
           for (int ptr = 0; ptr < len; ptr++) {
				if (s1[ptr] != s2[ptr]) {
					graph[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
					indegree[s2[ptr]-'a']++;
					break;
				}
			}
       }
       
    //   now apply topological sort algo 
    
    queue<int> q;
    
       for(int i=0;i<K;i++)
       {
           if(indegree[i]==0)
           q.push(i);
       }
       
       string ans="";
       while (q.empty()==false)
       {
           int curr=q.front();
           q.pop();
           char ch= curr+'a';
           ans.push_back(ch);
           
           for(auto v:graph[curr])
           {
               indegree[v]--;
               if(indegree[v]==0)
               q.push(v);
           }
           
       }
       
       return ans; 
       
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends