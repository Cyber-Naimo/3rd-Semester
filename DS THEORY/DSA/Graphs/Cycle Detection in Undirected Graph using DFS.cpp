//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool IsDFS_Cycle(int i,vector<int> adj[],int vis[],int par)
    {
        vis[i] = 1;
        
        for(auto neigbhors:adj[i])
        {
            if(!vis[neigbhors])
            {
                if(IsDFS_Cycle(neigbhors,adj,vis,i))
                {
                    return true;
                }
            }
            else if(neigbhors!=par)
            {
                return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) 
    {
        int vis[] = {0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                int parent = -1;
                if(IsDFS_Cycle(i,adj,vis,parent))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
