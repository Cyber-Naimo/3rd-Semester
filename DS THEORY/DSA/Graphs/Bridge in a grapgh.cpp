#include<bits/stdc++.h>
void dfs(int node, int parent, int timer,unordered_map<int, bool> &vis, vector<int> &low, vector<int> &dis,unordered_map<int, list<int> > &adj,
       vector<vector<int>> &result )
{
    // first mark it true
     vis[node] = true;
    // then inc timer 
     dis[node] = low[node] = timer++;
    // traverse it neighbours
    for(auto nbr : adj[node])
    {
        if(nbr == parent)
           // ignore condi
            continue;
        
        if(!vis[nbr])
        {
            // passing neighbour and parent as node
            dfs(nbr, node, timer, vis, low, dis, adj, result);
            // nowupdating low array because may be it will form backbridge
            low[node] = min(low[node], low[nbr]);
            
            // BACK BRIDGE
            if(low[nbr] > dis[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else
        {
            // ITS  VISITED AND ALSO NOT =  TO PARENTS
            low[node] = min(low[node], dis[nbr]);
        }
            
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, bool> vis;
    unordered_map<int, list<int> > adj;
    // creating adjancy list
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> low(v,-1);
    vector<int> dis(v,-1);
    int parent = -1;
    int timer = 0;
   
    vector<vector<int>> result;
    // traversing each node one by one
    for(int i = 0; i < v; i++)
    {
        if(!vis[i])
        {
            dfs(i, parent, timer, vis, low, dis, adj, result);
        }
    }
    return result;

}
