//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int src)
    {
        //we have array of vector of vector
        //so our structure is
    //{{1,3},{2,5}}{{1,3},{3,9}} where first one is for all nodes connected to the first node(u,v,w)
        
        vector<int> dist(n,INT_MAX);
      
        //initialized set and inserted our source node
        set<pair<int,int> > st;
        dist[src] = 0;
        st.insert(make_pair(0,src));
        // another method for initiallization
        //  st.insert({0,src});
        //pattern is distance,node which has been inserted
        //bfs like operation where we use set instead of queue
        //we could have used priority queue instead of queue
        while(!st.empty())
        {
            // take min element
            auto top = *(st.begin());
            int nodeDistance = top.first;
            int topNode = top.second;
            
            st.erase(st.begin());
            //we have extracted the values we need and we have erased it
            //traverse on neighbours
            for(auto it:adj[topNode])
			{
			    // takeing weight of 1 neigbour
                int weight = it[1];
                // weight of adjacent neighbour
                int adjacent_node = it[0];

                // if currnode distance + neighbour[1] is < then 2nd neighbour then update the min value
                if(weight+ nodeDistance < dist[adjacent_node])
                {
                    // ALSO IN DISTANCE ARRAY IF IN THE ADJACENT NODE POSITION INFINITY NOT EXISTS THEN GO
                    if(dist[adjacent_node]!=INT_MAX)
                    {
                        st.erase({dist[adjacent_node],adjacent_node});
                    }
                    // Now update the distnace and then insert in pair 
                    dist[adjacent_node]= weight+nodeDistance;

                    st.insert({dist[adjacent_node],adjacent_node});

                }

            }
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
