//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool checkCycleDFS(int i,unordered_map<int,bool> &vis,unordered_map<int,bool> &dfsvis,
    vector<int> adj[])
    {
        vis[i] = true;
        dfsvis[i]  = true;
        
        for(auto neibhours:adj[i])
        {
            if(!vis[neibhours])
            {
                bool check = checkCycleDFS(neibhours,vis,dfsvis,adj);
                if(check)
                {
                    return true;
                }
            }
            else if(dfsvis[neibhours])
            {
                return true;
            }
        }
        dfsvis[i] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
       unordered_map<int,bool> vis;
       unordered_map<int,bool> dfsvis;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(checkCycleDFS(i,vis,dfsvis,adj))
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

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
